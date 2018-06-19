#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "System.h"

// move value a[m-1] to proper location k such that
// a[k-1] <= a[m-1] <= a[k+1]
// input: a[k-1]<=a[k]<=a[k+1], for 1<=k<=m-2
template <typename T> inline void insert(T* a, int32_t m)
{
	int32_t k = m-1;
	while(k>=0 && a[k]>a[m]) k--;
    rotate(a, k+1, m);
}

template<typename T> void insertionSort(T* a, int32_t n)
{
	for(int32_t i=1; i<n; ++i){
		insert(a, i);
    }
}

#endif