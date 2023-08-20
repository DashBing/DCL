#ifndef _DCL_BASE_ARRLIB_H
#define _DCL_BASE_ARRLIB_H

/*
#define array_length(arr) sizeof(arr)/sizeof(arr[0])

inline unsigned int arrlen(void * arr){
    return(array_length(arr));
}
*/

#define arrlen(arr) sizeof(arr)/sizeof(arr[0])

#endif
