#ifndef UTILITY_H
#define UTILITY_H

#include "System.h"

template<typename T> void swap(T* a, int32_t l, int32_t r)
{
	T temp = a[l];
	a[l] = a[r];
	a[r] = temp;
}

// rotate the array between l and r so that
// a[l] = a[r], and a[k+1] = a[k] for l<=k<r
template<typename T> inline void rotate(T* a, int32_t l, int32_t r)
{
    assert(r >= l);
    T t = a[r];
    for (int32_t i = r - 1; i >= l; --i) a[i + 1] = a[i];
    a[l] = t;
}

#endif