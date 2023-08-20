//
// numlib.hpp
//
//         By DPFramework
//
//         Copyright (c) DashBing
//

#pragma once
#ifndef _INC_NUMLIB_PLUS
#define _INC_NUMLIB_PLUS
//#define _INC_NUMLIB

namespace numlib{
    template <class number, class b_type>
    number pow(number a, b_type b){
        b_type i;
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
}

namespace std{
    using namespace numlib;
}

#endif