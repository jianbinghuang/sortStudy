#ifndef UTILITY_H
#define UTILITY_H

#include "System.h"

template<typename T> void swap(T* a, int32_t l, int32_t r)
{
	T temp = a[l];
	a[l] = a[r];
	a[r] = temp;
}

#endif