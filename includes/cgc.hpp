//#pragma once
#ifndef _DCL_CGC
#define _DCL_CGC

namespace cgc{
#ifdef _DCL_GC_H
#undef _DCL_GC_H
#include <gc.h>
#define _DCL_GC_H
#else
#include <gc.h>
#endif
}

namespace dcl{
    using namespace cgc;
}

#endif