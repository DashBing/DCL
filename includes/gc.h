#ifndef _DCL_GC_H
#define _DCL_GC_H

#include <sys_base/stdlib.h>
#include <baselib/arrlib.h>

#ifndef _DCL_GC
typedef struct gc_value_adr{
    void * adr;
} gc_adr, gcva, gcadr;
#endif

static gc_value_adr * gc_global_list;

void gc_init(){
    gc_global_list = (gc_value_adr *)NULL;//(gc_value_adr *)(calloc(1,sizeof(gc_value_adr)));
}

void gc_add(void * p){
    if(gc_global_list == (gc_value_adr *)NULL){
        gc_global_list = (gc_value_adr *)calloc(1, sizeof(gc_value_adr));
    }
    else{
        gc_global_list = (gc_value_adr *)realloc(gc_global_list, sizeof(gc_global_list) + sizeof(gc_value_adr));
        gc_value_adr tmp;
        tmp.adr = p;
        gc_global_list[arrlen(gc_global_list) - 1] = tmp;
    }
}

void * gc_create(unsigned int size){
    void * tmp = calloc(size, 1);
    gc_add(tmp);
    return(tmp);
}

void gc_clean(){
    for(unsigned int i = 0; i<arrlen(gc_global_list); i++){
        free(gc_global_list[i].adr);
    }
    free(gc_global_list);
    gc_init();
}

/*
static void ** gc_global_list;
//extern void ** gc_global_list;

void gc_init(){
    gc_global_list = calloc(1, sizeof(void *));
}
*/

#endif
