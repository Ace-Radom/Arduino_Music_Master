#include"Music_Master.h"

/*
#ifndef _MUSIC_MASTER_H_

#define _MUSIC_MASTER_H_
#error Headfile Protection not found

#endif
*/

_Pitch_ _MusicBase_[] = {
    {},  // NULL bit
//          C              C+ / D-              D              D+ / E-              E                 F              F+ / G-              G              G+ / F-              A              A+ / B-              B
    { -11.0 , 131 } , { -11.5 , 139 } , { -21.0 , 147 } , { -21.5 , 156 } , { -31.0 , 165 } , { -41.0 , 175 } , { -41.5 , 185 } , { -51.0 , 196 } , { -51.5 , 208 } , { -61.0 , 220 } , { -61.5 , 233 } , { -71.0 , 247 } ,
    {  10.0 , 262 } , {  10.5 , 277 } , {  20.0 , 294 } , {  20.5 , 311 } , {  30.0 , 330 } , {  40.0 , 349 } , {  40.5 , 370 } , {  50.0 , 392 } , {  50.5 , 415 } , {  60.0 , 440 } , {  60.5 , 466 } , {  70.0 , 494 } ,
    
};

/* Preset the pin of the Tone and BPM */
Music_Master::Music_Master( uint8_t _pin , uint32_t _bpm ){
    _PIN = _pin;
    _BPM = _bpm;
    float _Beat_durationtime = 60.0 / ( float ) ( _BPM );
    _Beat_durationtime_ms = _durationtime_change_( _Beat_durationtime );
    return;
}

/* Play the given pitch */
void Music_Master::play( float _pitch , float _durationBeat ){
    play( _Frequency_pointback( _pitch ) , _durationBeat );
    return;
}

/* do pause */
void Music_Master::pause( float _durationBeat ){
    play( ( uint32_t ) ( 0 ) , _durationBeat );
    return;
}

/* private play function, use tone directly */
void Music_Master::play( uint32_t _Frequency , float _durationBeat ){
    uint32_t _DT = _durationBeat * _Beat_durationtime_ms; // the duration time for this pitch in this play function
    if ( _Frequency == 0 ) // if pitch is not recognized or using pause
    {
        delay( _DT );
        return;
    }
    tone( _PIN , _Frequency );
    delay( _DT );
    noTone( _PIN );
    return;
}

/* return the frequency of the given pitch in the musicbase */
uint32_t Music_Master::_Frequency_pointback( float _pitch ){
    uint16_t _ssize = sizeof( _MusicBase_ ) / sizeof( _MusicBase_[0] ); // _MusicBase_ size
    for ( uint16_t i = 1 ; i < _ssize ; i++ )
    {
        if ( _MusicBase_[i]._pitch == _pitch )
        {
            return _MusicBase_[i]._Frequency;
        }
    }
    return 0; // _pitch not found or wrong format
}