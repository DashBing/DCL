//
// strmem.h
//
//         By DPFramework
//
//         Copyright (c) DashBing
//

/*
    Warn: This file is dangrous
*/

#pragma once
#ifndef _INC_STRMEM
#define _INC_STRMEM

char * string_init(int lenth){
    char *s;
    s = (char *)malloc(lenth * sizeof(char));
    return(s);
}
void string_chlong(char **string, int lenth){
    *string = (char *)realloc(*string, lenth * sizeof(char));
}
void string_del(char **string){
    free(*string);
}

#endif
