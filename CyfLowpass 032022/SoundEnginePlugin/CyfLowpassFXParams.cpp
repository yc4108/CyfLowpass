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

#include "CyfLowpassFXParams.h"

#include <AK/Tools/Common/AkBankReadHelpers.h>

CyfLowpassFXParams::CyfLowpassFXParams()
{
}

CyfLowpassFXParams::~CyfLowpassFXParams()
{
}

CyfLowpassFXParams::CyfLowpassFXParams(const CyfLowpassFXParams& in_rParams)
{
    RTPC = in_rParams.RTPC;
    NonRTPC = in_rParams.NonRTPC;
    m_paramChangeHandler.SetAllParamChanges();
}

AK::IAkPluginParam* CyfLowpassFXParams::Clone(AK::IAkPluginMemAlloc* in_pAllocator)
{
    return AK_PLUGIN_NEW(in_pAllocator, CyfLowpassFXParams(*this));
}

AKRESULT CyfLowpassFXParams::Init(AK::IAkPluginMemAlloc* in_pAllocator, const void* in_pParamsBlock, AkUInt32 in_ulBlockSize)
{
    if (in_ulBlockSize == 0)
    {
        // Initialize default parameters here
        RTPC.fVolume = 0.0f;
        RTPC.fFrequency = 1000.0f;
        RTPC.isEnable = true;
        RTPC.iFilterType = 0;
        RTPC.fOverride = 0.333f;
        RTPC.isOverride = false;
        RTPC.isDistort = false;
        RTPC.fDistort = 0.0f;
        RTPC.fDistortmix = 0.0f;
        RTPC.fResonance = 0.0f;
        RTPC.fResonanceband = 0.5f;
        m_paramChangeHandler.SetAllParamChanges();
        return AK_Success;
    }

    return SetParamsBlock(in_pParamsBlock, in_ulBlockSize);
}

AKRESULT CyfLowpassFXParams::Term(AK::IAkPluginMemAlloc* in_pAllocator)
{
    AK_PLUGIN_DELETE(in_pAllocator, this);
    return AK_Success;
}

AKRESULT CyfLowpassFXParams::SetParamsBlock(const void* in_pParamsBlock, AkUInt32 in_ulBlockSize)
{
    AKRESULT eResult = AK_Success;
    AkUInt8* pParamsBlock = (AkUInt8*)in_pParamsBlock;

    // Read bank data here
    RTPC.fVolume = READBANKDATA(AkReal32, pParamsBlock, in_ulBlockSize);
    RTPC.fFrequency = READBANKDATA(AkReal32, pParamsBlock, in_ulBlockSize);
    RTPC.isEnable = READBANKDATA(bool, pParamsBlock, in_ulBlockSize);
    RTPC.iFilterType = READBANKDATA(AkInt32, pParamsBlock, in_ulBlockSize);
    RTPC.fOverride = READBANKDATA(AkReal32, pParamsBlock, in_ulBlockSize);
    RTPC.isOverride = READBANKDATA(bool, pParamsBlock, in_ulBlockSize);
    RTPC.isDistort = READBANKDATA(bool, pParamsBlock, in_ulBlockSize);
    RTPC.fDistort = READBANKDATA(AkReal32, pParamsBlock, in_ulBlockSize);
    RTPC.fDistortmix = READBANKDATA(AkReal32, pParamsBlock, in_ulBlockSize);
    RTPC.fResonance = READBANKDATA(AkReal32, pParamsBlock, in_ulBlockSize);
    RTPC.fResonanceband = READBANKDATA(AkReal32, pParamsBlock, in_ulBlockSize);
    CHECKBANKDATASIZE(in_ulBlockSize, eResult);
    m_paramChangeHandler.SetAllParamChanges();

    return eResult;
}

AKRESULT CyfLowpassFXParams::SetParam(AkPluginParamID in_paramID, const void* in_pValue, AkUInt32 in_ulParamSize)
{
    AKRESULT eResult = AK_Success;

    // Handle parameter change here
    switch (in_paramID)
    {
    case PARAM_VOLUME_ID:
        RTPC.fVolume = *((AkReal32*)in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_VOLUME_ID);
        break;
    case PARAM_FREQUENCY_ID:
        RTPC.fFrequency = *((AkReal32*)in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_FREQUENCY_ID);
        break;
    case PARAM_ONOFFFILTER_ID:
        RTPC.isEnable = (*(AkReal32*)(in_pValue)) != 0;
        m_paramChangeHandler.SetParamChange(PARAM_ONOFFFILTER_ID);
        break;
    case PARAM_FILTERTYPE_ID:
        RTPC.iFilterType = (*(AkReal32*)(in_pValue));
        m_paramChangeHandler.SetParamChange(PARAM_FILTERTYPE_ID);
        break;
    case PARAM_OVERRIDE_ID:
        RTPC.fOverride = *((AkReal32*)in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_OVERRIDE_ID);
        break;
    case PARAM_ONOVERRIDE_ID:
        RTPC.isOverride = (*(AkReal32*)(in_pValue)) != 0;
        m_paramChangeHandler.SetParamChange(PARAM_ONOVERRIDE_ID);
        break;
    case PARAM_ONDISTORT_ID:
        RTPC.isDistort = (*(AkReal32*)(in_pValue)) != 0;
        m_paramChangeHandler.SetParamChange(PARAM_ONDISTORT_ID);
        break;
    case PARAM_DISTORTION_ID:
        RTPC.fDistort = *((AkReal32*)in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_DISTORTION_ID);
        break;
    case PARAM_DISTORTMIX_ID:
        RTPC.fDistortmix = *((AkReal32*)in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_DISTORTMIX_ID);
        break;
    case PARAM_RESONANCE_ID:
        RTPC.fResonance = *((AkReal32*)in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_RESONANCE_ID);
        break;
    case PARAM_RESONANCEBAND_ID:
        RTPC.fResonanceband = *((AkReal32*)in_pValue);
        m_paramChangeHandler.SetParamChange(PARAM_RESONANCEBAND_ID);
        break;
    default:
        eResult = AK_InvalidParameter;
        break;
    }

    return eResult;
}
