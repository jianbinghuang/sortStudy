#ifndef STDSORT_H
#define STDSORT_H

#include "System.h"
#include "Utility.h"
#include <algorithm>

template<typename T> void stdSort(T* a, int32_t n)
{
    std::sort(a, a+n);
}

#endif