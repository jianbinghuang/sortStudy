#ifndef SYSTEM_H
#define SYSTEM_H

#include <cstdint>      // int type
#include <iostream>     // stream
#include <cassert>      // assert

#define Demand(test, msg) if(!test) throw std::exception(msg);

// rotate the array between l and r so that
// a[l] = a[r], and a[k+1] = a[k] for l<=k<r
template<typename T> inline void rotate(T* a, int32_t l, int32_t r)
{
	assert(r>=l);
	T t = a[r];
	for(int32_t i=r-1; i>=l; --i) a[i+1] = a[i];
    a[l] = t;
}

#endif