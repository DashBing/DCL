/*
* This file is to pre-define the entry function
*/

#pragma once
#ifndef _INC_EDWIN32_H
#define _INC_EDWIN32_H
#if defined WIN32 || defined _WIN32

#ifndef _INC_BASICAPI_H
#include "basicapi.h"
#endif

int WinMain(HINSTANCE hInstence, HINSTENCE hPrevInstence, LPSTR lpCmdline, int nCmdShow){
    return(main(hInstence, hPrevInstence, lpCmdline, nCmdShow));
}

#endif
#endif
