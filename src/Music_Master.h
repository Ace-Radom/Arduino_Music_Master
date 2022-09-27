#ifndef _MUSIC_MASTER_H_
#define _MUSIC_MASTER_H_

#include<Arduino.h>

/* change beat duration time from s to ms and save in uint32_t var */
#define _durationtime_change_( x ) ( x * 1000 )

struct _Pitch_{
    float _pitch;
    uint32_t _Frequency;
};

class Music_Master{
    public:
        Music_Master( uint8_t _pin , uint32_t _bpm );
        void play( float _pitch , float _durationBeat );
        void pause( float _durationBeat );
    
    private:
        uint8_t _PIN;
        uint32_t _BPM;
        uint32_t _Beat_durationtime_ms;

        void play( uint32_t _Frequency , float _durationBeat );
        uint32_t _Frequency_pointback( float _pitch );
};

#endif