
#pragma once

#include <AK/SoundEngine/Common/AkCommonDefs.h>


class ButterworthFilter

{


public:

    ButterworthFilter();

    ~ButterworthFilter();



    void Setup(AkUInt32 in_sampleRate);

    void SetFrequency(AkReal32 in_newFrequency);

    void Execute(AkReal32* io_pBuffer, AkUInt16 in_uValidFrames);




private:

    AkUInt32 m_sampleRate;

    AkReal32 m_frequency;

    AkReal32 m_coeff;

    AkReal32 m_previousOutput;

    bool m_frequencyChanged;

};