
#include "ButterworthFilter.h"

#include <cmath>



#ifndef M_PI

#define M_PI 3.14159265359

#endif



ButterworthFilter::ButterworthFilter()

    : m_sampleRate(0)

    , m_frequency(0.0f)

    , m_coeff(0.0f)

    , m_previousOutput(0.0f)

    , m_frequencyChanged(false)

{

}


ButterworthFilter::~ButterworthFilter() {}


void ButterworthFilter::Setup(AkUInt32 in_sampleRate)

{

    m_sampleRate = in_sampleRate;

}


void ButterworthFilter::SetFrequency(AkReal32 in_newFrequency)

{

    if (m_sampleRate > 0)

    {

        m_frequency = in_newFrequency;

        m_frequencyChanged = true;

    }

}




void ButterworthFilter::Execute(AkReal32* io_pBuffer, AkUInt16 in_uValidFrames)

{

    AkReal32 coeffBegin = m_coeff, coeffEnd = 0.0f, coeffStep = 0.0f;

    if (m_frequencyChanged)

    {

        coeffEnd = static_cast<AkReal32>(exp(-2.0 * M_PI * m_frequency / m_sampleRate));

        coeffStep = (coeffEnd - coeffBegin) / in_uValidFrames;

        m_frequencyChanged = false;

    }



    AkUInt16 uFramesProcessed = 0;

    while (uFramesProcessed < in_uValidFrames)

    {

        m_previousOutput = io_pBuffer[uFramesProcessed] =

            io_pBuffer[uFramesProcessed] + (m_previousOutput - io_pBuffer[uFramesProcessed]) * coeffBegin;

        coeffBegin += coeffStep;

        ++uFramesProcessed;

    }

    m_coeff = coeffBegin;

}