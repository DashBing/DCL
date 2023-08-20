//
// beepplayer.h
//
//         By DPFramework
//
//         Copyright (c) DashBing
//

/*
    Note: This file can only run on the Windows
*/

#pragma once
#ifndef _INC_BEEPPLAYER
#define _INC_BEEPPLAYER

#include <windows.h>
#include "numlib.h"

enum music_note{DO=1,RE,MI,FA,SO,LA,SI};
typedef enum music_note mn, mu, midi, mu_nt;

#define MDO 440.0
#define MRE 493.88
#define MMI 554.37
#define MFA 587.33
#define MSO 659.33
#define MLA 739.99
#define MSI 830.61

float mu_to_hz(enum music_note music_note, int mu_high = 0, bool up_half_m = false){
    const float mu_hz[] = {0.0,MDO,MRE,MMI,MFA,MSO,MLA,MSI};
    float r;
    //int tmpsyn;
    r = mu_hz[music_note];
    if (mu_high>0){
        r = r * pow(2, mu_high);
    }
    else if(mu_high<0){
        r = r / pow(2, mu_high);
    }
    if (up_half_m){
        if (music_note==7){
            r = (mu_hz[1] * 2 + r) / 2;
        }
        else{
            r = (mu_hz[music_note + 1] + r) / 2;
        }
    }
    return(r);
}

#undef MDO
#undef MRE
#undef MMI
#undef MFA
#undef MSO
#undef MLA
#undef MSI

struct sound{
    enum music_note note;
    int sound_high = 0;
    bool up_half_sound = false;
};
typedef unsigned long long ull;

bool play(struct sound sound, ull time){
    return(Beep(mu_to_hz(sound.note, sound.sound_high, sound.up_half_sound), time));
}

#endif