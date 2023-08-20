//#pragma once
#ifndef _DCL_GC
#define _DCL_GC

#include <sys_base/stdlib.h>

namespace gc{
    // 基类(抽象类区)
    #ifndef _DCL_GC_H
    typedef struct gcva{
        void * adr;
    } gc_value_adr, gc_adr, gcadr;
    #endif
    class GC{
        public:
        virtual void init()=0;
        virtual void init(unsigned int)=0;
        virtual void clean()=0;
        void reset();
        void reset(unsigned int);
    };
    void GC::reset(){
        clean();
        init();
    }
    void GC::reset(unsigned int size){
        clean();
        init(size);
    }
    class GCMgrBase:public GC{
        protected:
        gcva * glob_list;
        public:
        void init(unsigned int, unsigned int);
        void reset(unsigned int, unsigned int);
        virtual void add(void *)=0;
        virtual void * create(unsigned int)=0;
        void * create(unsigned int, unsigned int);
        void operator+=(void *);
        //void operator+=(unsigned int);
        void * operator<<(void *);
        void * operator<<(unsigned int);
    };
    void GCMgrBase::init(unsigned int size_a, unsigned int size_b){
        init(size_a*size_b);
    }
    void GCMgrBase::reset(unsigned int size_a, unsigned int size_b){
        clean();
        init(size_a, size_b);
    }
    void * GCMgrBase::create(unsigned int size_a, unsigned int size_b){
        return(create(size_a*size_b));
    }
    void GCMgrBase::operator+=(void * p){
        add(p);
    }
    /*void GCMgrBase::operator+=(unsigned int size){
        create(size);
    }*/
    void * GCMgrBase::operator<<(void * p){
        add(p);
        return(p);
    }
    void * GCMgrBase::operator<<(unsigned int size){
        return(create(size));
    }
    template <class type>
    class GCTypeBase:public GC{
        protected:
        type * adr_p;
        public:
        type operator[](unsigned int);
        virtual void init_low(unsigned int)=0;
        void init(unsigned int);
    };
    template <class type>
    type GCTypeBase<type>::operator[](unsigned int index){
        return(adr_p[index]);
    }
    template <class type>
    void GCTypeBase<type>::init(unsigned int length){
        init_low(length*sizeof(type));
    }

    // 实际重载实现
}

namespace dcl{
    using namespace gc;
}

#endif
