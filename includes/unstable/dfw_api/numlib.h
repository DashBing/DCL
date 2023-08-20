//
// numlib.h
//
//         By DPFramework
//
//         Copyright (c) DashBing
//

#pragma once
#ifndef _INC_NUMLIB
#define _INC_NUMLIB

long pow(long a, int b){
    //long tmp = a;
    int i;
    if (b>0){
        for (i = 0; i<b; i++){
            a *= a;
        }
    }
    else if (b==0){
        a = 1;
    }
    else{
        for (i = 0; i<(-b); i++){
            a /= a;
        }
    }
    return(a);
}

#endif