//
// strplus.hpp
//
//         By DPFramework
//
//         Copyright (c) DashBing
//

/*
    Note: This file may conflict with the 'string' file in the C++ standard class library
*/

#pragma once
#ifndef _INC_STRPLUS
#define _INC_STRPLUS

//#include <string.h>

namespace strlib{
    template <class number>
    number strlen_t(char *string){
        number ret = 0;
        char *tmp = string;
        while (*tmp != '\0'){
            tmp++;
            ret++;
        }
        return(ret);
    }
    int strlen(char *string){
        return(strlen_t<int>(string));
    }
    void copy_from_str(char *string, char *toS){}
    void str_plus(char *stra, char *strb, char *toS){}
}

namespace strplus{
    class strplus{
        protected:
        char *data;
        public:
        strplus();
        strplus(char *string);
        strplus(strplus &copyobj);
        ~strplus();
        strplus operator+(strplus obj);
        strplus operator+(char *string);
        strplus operator=(strplus obj);
        strplus operator=(char *string);
        bool operator==(strplus obj);
        bool operator!=(strplus obj);
        char operator[](int syntax);
    };
    strplus::strplus(){
        data = new char[1];
    }
    strplus::strplus(char *string){}
    strplus::strplus(strplus &copyobj){}
    strplus::~strplus(){
        delete data;
    }
    strplus strplus::operator+(strplus obj){}
    strplus strplus::operator+(char *string){}
    strplus strplus::operator=(strplus obj){}
    strplus strplus::operator=(char *string){}
    bool strplus::operator==(strplus obj){}
    bool strplus::operator!=(strplus obj){}
    char strplus::operator[](int syntax){
        return(data[syntax]);
    }
    typedef strplus stringplus, string, str;
}

namespace stringplus{
    using namespace strplus;
}

namespace std{
    using namespace strlib;
    using namespace strplus;
}

#endif