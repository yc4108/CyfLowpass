/*******************************************************************************
The content of this file includes portions of the AUDIOKINETIC Wwise Technology
released in source code form as part of the SDK installer package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use this file in accordance with the end user license agreement provided
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

Apache License Usage

Alternatively, this file may be used under the Apache License, Version 2.0 (the
"Apache License"); you may not use this file except in compliance with the
Apache License. You may obtain a copy of the Apache License at
http://www.apache.org/licenses/LICENSE-2.0.

Unless required by applicable law or agreed to in writing, software distributed
under the Apache License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
OR CONDITIONS OF ANY KIND, either express or implied. See the Apache License for
the specific language governing permissions and limitations under the License.

  Copyright (c) 2021 Audiokinetic Inc.
*******************************************************************************/

#include "CyfLowpassFX.h"
#include "../CyfLowpassConfig.h"

#include <AK/AkWwiseSDKVersion.h>
#include <cmath>



#ifndef M_PI

#define M_PI 3.14159265359

#endif

AK::IAkPlugin* CreateCyfLowpassFX(AK::IAkPluginMemAlloc* in_pAllocator)
{
    return AK_PLUGIN_NEW(in_pAllocator, CyfLowpassFX());
}

AK::IAkPluginParam* CreateCyfLowpassFXParams(AK::IAkPluginMemAlloc* in_pAllocator)
{
    return AK_PLUGIN_NEW(in_pAllocator, CyfLowpassFXParams());
}

AK_IMPLEMENT_PLUGIN_FACTORY(CyfLowpassFX, AkPluginTypeEffect, CyfLowpassConfig::CompanyID, CyfLowpassConfig::PluginID)

CyfLowpassFX::CyfLowpassFX()
    : m_pParams(nullptr)
    , m_pAllocator(nullptr)
    , m_pContext(nullptr)
    , m_coeff(0.99f)
    , V0s(0.0f)
    , cs(0.0f)
    , ds(0.0f)
{
}

CyfLowpassFX::~CyfLowpassFX()
{
}

AKRESULT CyfLowpassFX::Init(AK::IAkPluginMemAlloc* in_pAllocator, AK::IAkEffectPluginContext* in_pContext, AK::IAkPluginParam* in_pParams, AkAudioFormat& in_rFormat)
{
    m_pParams = (CyfLowpassFXParams*)in_pParams;
    m_pAllocator = in_pAllocator;
    m_pContext = in_pContext;
    m_previousOutput.resize(in_rFormat.GetNumChannels(), 0.0f);
    m_previousInput.resize(in_rFormat.GetNumChannels(), 0.0f);
    m_previousOutput_2.resize(in_rFormat.GetNumChannels(), 0.0f);
    m_previousInput_2.resize(in_rFormat.GetNumChannels(), 0.0f);
    m_xh.resize(in_rFormat.GetNumChannels(), 0.0f);
    m_xh_2.resize(in_rFormat.GetNumChannels(), 0.0f);
    m_xh_new.resize(in_rFormat.GetNumChannels(), 0.0f);
    m_sampleRate = in_rFormat.uSampleRate;
    return AK_Success;
}

AKRESULT CyfLowpassFX::Term(AK::IAkPluginMemAlloc* in_pAllocator)
{
    AK_PLUGIN_DELETE(in_pAllocator, this);
    return AK_Success;
}

AKRESULT CyfLowpassFX::Reset()
{
    return AK_Success;
}

AKRESULT CyfLowpassFX::GetPluginInfo(AkPluginInfo& out_rPluginInfo)
{
    out_rPluginInfo.eType = AkPluginTypeEffect;
    out_rPluginInfo.bIsInPlace = true;
	out_rPluginInfo.bCanProcessObjects = false;
    out_rPluginInfo.uBuildVersion = AK_WWISESDK_VERSION_COMBINED;
    return AK_Success;
}

void CyfLowpassFX::Execute(AkAudioBuffer* io_pBuffer)
{
    AkReal32 coeffBegin = m_coeff, coeffEnd = 0.0f, coeffStep = 0.0f;
    AkReal32 V0 = V0s, c = cs, d = ds, V0step = 0.0f, cstep = 0.0f, dstep = 0.0f;
    if (m_pParams->m_paramChangeHandler.HasChanged(PARAM_FREQUENCY_ID))
    {
        switch (m_pParams->RTPC.iFilterType) {
        case 0:
            coeffEnd = static_cast<AkReal32>(exp(-2.0 * M_PI * m_pParams->RTPC.fFrequency / m_sampleRate));
            break;
        case 1:
            coeffEnd = static_cast<AkReal32>(abs(tan(M_PI * m_pParams->RTPC.fFrequency / m_sampleRate)));
            break;
        case 2:
            coeffEnd = static_cast<AkReal32>(abs(tan(M_PI * m_pParams->RTPC.fFrequency / m_sampleRate)));
            break;
        default:
            coeffEnd = static_cast<AkReal32>(exp(-2.0 * M_PI * m_pParams->RTPC.fFrequency / m_sampleRate));
            break;
        }
        
        coeffStep = (coeffEnd - coeffBegin) / io_pBuffer->uValidFrames;
    }
    if (m_pParams->RTPC.isEnable) {
        V0s = pow(10, m_pParams->RTPC.fResonance / 20);
        if (m_pParams->RTPC.fResonance >= 0) {
            cs = (tan(M_PI * m_pParams->RTPC.fResonanceband / 2) - 1) / (tan(M_PI * m_pParams->RTPC.fResonanceband / 2) + 1);
        }
        else {
            cs = (tan(M_PI * m_pParams->RTPC.fResonanceband / 2) - V0) / (tan(M_PI * m_pParams->RTPC.fResonanceband / 2) + V0);
        }
        ds = -cos(M_PI * 2 * m_pParams->RTPC.fFrequency / m_sampleRate);
        V0step = (V0s - V0) / io_pBuffer->uValidFrames;
        cstep = (cs - c) / io_pBuffer->uValidFrames;
        dstep = (ds - d) / io_pBuffer->uValidFrames;
    }

    const AkUInt32 uNumChannels = io_pBuffer->NumChannels();
    //m_coeff = static_cast<AkReal32>(exp(-2.0 * M_PI * m_pParams->RTPC.fFrequency / m_sampleRate));
    AkUInt16 uFramesProcessed;
    for (AkUInt32 i = 0; i < uNumChannels; ++i)
    {
        AkReal32* AK_RESTRICT pBuf = (AkReal32* AK_RESTRICT)io_pBuffer->GetChannel(i);
        coeffBegin = m_coeff;
        uFramesProcessed = 0;
        while (uFramesProcessed < io_pBuffer->uValidFrames)
        {
            // Execute DSP in-place here
            if (m_pParams->RTPC.isEnable) {
                switch (m_pParams->RTPC.iFilterType) {
                    case 0:
                        m_previousOutput[i] = pBuf[uFramesProcessed] =

                            pBuf[uFramesProcessed] + (m_previousOutput[i] - pBuf[uFramesProcessed]) * coeffBegin;
                        break;
                    case 1:
                        if (uFramesProcessed > 0) {
                            m_previousInput[i] = pBuf[uFramesProcessed - 1];
                        }

                        m_previousOutput[i] = pBuf[uFramesProcessed] =

                            (pBuf[uFramesProcessed] + m_previousInput[i] + m_previousOutput[i] * (1 / coeffBegin - 1)) / (1 + 1 / coeffBegin);
                        break;
                    case 2 :
                        if (uFramesProcessed > 0) {
                            m_previousInput[i] = pBuf[uFramesProcessed - 1];
                        }
                        if (uFramesProcessed > 1) {
                            m_previousInput_2[i] = pBuf[uFramesProcessed - 2];
                        }

                        pBuf[uFramesProcessed] = 
                        
                            (pBuf[uFramesProcessed] + 2 * m_previousInput[i] + m_previousInput_2[i] + m_previousOutput[i] * static_cast<AkReal32>(2 * pow(1 / coeffBegin, 2) - 2) + m_previousOutput_2[i] * static_cast<AkReal32>(sqrt(2) * 1 / coeffBegin - 1 - pow(1 / coeffBegin, 2))) / static_cast<AkReal32>(1 + sqrt(2) * 1 / coeffBegin + pow(1 / coeffBegin, 2));
                            //(pBuf[uFramesProcessed] + 2 * m_previousInput[i] + m_previousInput_2[i] + m_previousOutput[i] * (2 * pow(1 / coeffBegin, 2) - 2) + m_previousOutput_2[i] * (sqrt(2) * 1 / coeffBegin - 1 - pow(1 / coeffBegin, 2))) / (1 + sqrt(2) * 1 / coeffBegin + pow(1 / coeffBegin, 2));
                        m_previousOutput_2[i] = m_previousOutput[i];
                        m_previousOutput[i] = pBuf[uFramesProcessed];
                        break;
                    default:
                        break;
                }

                coeffBegin += coeffStep;

                if (m_pParams->RTPC.fResonance != 0.0f) {
                    m_xh_new[i] = pBuf[uFramesProcessed] - d * (1 - c) * m_xh[i] + c * m_xh_2[i];
                    pBuf[uFramesProcessed] = 0.5 * (V0 - 1) * (pBuf[uFramesProcessed] - (-c * m_xh_new[i] + d * (1 - c) * m_xh[i] + m_xh_2[i])) + pBuf[uFramesProcessed];
                    m_xh_2[i] = m_xh[i];
                    m_xh[i] = m_xh_new[i];
                }
                c += cstep;
                d += dstep;
                V0 += V0step;

                pBuf[uFramesProcessed] = pBuf[uFramesProcessed] * AK_DBTOLIN(m_pParams->RTPC.fVolume);

            }

            if (m_pParams->RTPC.isOverride) {
                if (abs(pBuf[uFramesProcessed]) < m_pParams->RTPC.fOverride) {
                    pBuf[uFramesProcessed] = 2 * pBuf[uFramesProcessed];
                }
                else if (abs(pBuf[uFramesProcessed]) >= 2 * m_pParams->RTPC.fOverride) {
                    if (pBuf[uFramesProcessed] > 0) {
                        pBuf[uFramesProcessed] = 1;
                    }
                    if (pBuf[uFramesProcessed] < 0) {
                        pBuf[uFramesProcessed] = -1;
                    }
                }
                else {
                    if (pBuf[uFramesProcessed] > 0) {
                        pBuf[uFramesProcessed] = 1 - ((1 - 2 * m_pParams->RTPC.fOverride) / pow(m_pParams->RTPC.fOverride, 2)) * pow((pBuf[uFramesProcessed] - 2 * m_pParams->RTPC.fOverride), 2);
                    }
                    if (pBuf[uFramesProcessed] < 0) {
                        pBuf[uFramesProcessed] = -1 + ((1 - 2 * m_pParams->RTPC.fOverride) / pow(m_pParams->RTPC.fOverride, 2)) * pow((abs(pBuf[uFramesProcessed]) - 2 * m_pParams->RTPC.fOverride), 2);
                    }
                }
                pBuf[uFramesProcessed] /= sqrt(2);
            }

            if (m_pParams->RTPC.isDistort) {
                if (pBuf[uFramesProcessed] > 0) {
                    pBuf[uFramesProcessed] = (1 - exp(-abs(pBuf[uFramesProcessed] * m_pParams->RTPC.fDistort))) * m_pParams->RTPC.fDistortmix + (1 - m_pParams->RTPC.fDistortmix) * pBuf[uFramesProcessed];
                }
                if (pBuf[uFramesProcessed] < 0) {
                    pBuf[uFramesProcessed] = (-1 + exp(-abs(pBuf[uFramesProcessed] * m_pParams->RTPC.fDistort))) * m_pParams->RTPC.fDistortmix + (1 - m_pParams->RTPC.fDistortmix) * pBuf[uFramesProcessed];

                }
            }
            ++uFramesProcessed;
        }
    }
    m_coeff = coeffBegin;
}

AKRESULT CyfLowpassFX::TimeSkip(AkUInt32 in_uFrames)
{
    return AK_DataReady;
}
