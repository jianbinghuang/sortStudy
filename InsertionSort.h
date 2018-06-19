#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "System.h"

// rotate the array between l and r so that
// a[l] = a[r], and a[k+1] = a[k] for l<=k<r
template<typename T> inline void rotate(T* a, int32_t l, int32_t r)
{
	assert(r>=l);
	T t = a[r];
	for(int32_t i=l; i<r; ++i) a[i+1] = a[i];
    a[l] = t;
}

// move value a[m-1] to proper location k such that
// a[k-1] <= a[m-1] <= a[k+1]
// input: a[k-1]<=a[k]<=a[k+1], for 1<=k<=m-3
template <typename T> inline void insert(T* a, int32_t m)
{
	int32_t k = m-1;
	while(k>=0 && a[k]>a[m]) k--;
    rotate(a, k+1, m);
}

/// @pre a[0...l-1] is sorted
/// @post a[0...r] is sorted
template<typename T> inline void  insertionSort(T* a, int32_t l, int32_t r)
{
	for (int32_t i = l; i<=r; ++i) {
		insert(a, i);
	}
}

template<typename T> void insertionSort(T* a, int32_t n)
{
	return insertionSort(a, 1, n - 1);
}

#endif