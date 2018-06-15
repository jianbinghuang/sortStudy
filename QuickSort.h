#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "System.h"
#include "Utility.h"

template<typename T> void qs_recursive(T* a, int32_t n, int32_t l, int32_t u)
{
	if(l>=u) return;

	// Pick pivot value as the leftmost element
	int32_t pi = l;
	T p = a[pi];
	int32_t ml = l+1, mu = u;
	while(ml<=mu){
	    while(a[ml] <= p && ml<=mu) ++ml;
	    while(a[mu] > p && ml<=mu) --mu;
	    if(ml<mu) swap(a, ml, mu);
   	}
	swap(a, pi, mu);	
	qs_recursive(a, n, l, mu-1);
	qs_recursive(a, n, mu+1, u);
}

// sort input array a
template<typename T> void qs(T* a, int32_t n)
{
	qs_recursive(a, n, 0, n-1);
}

#endif