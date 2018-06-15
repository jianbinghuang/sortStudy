#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "System.h"
#include "Utility.h"


template <typename T> void selectionSort(T* a, int n)
{
	for(int i=0; i<n; ++i){
		// a[0..i-1] is sorted, find minimum of [i..n-1] and swap with a[i]
		int m = i;
		for(int j=i+1; j<n; ++j){
			if(a[j] < a[m]) m = j;
        }
        swap(a, m,i);
    }
}

#endif