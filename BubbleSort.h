#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "System.h"
#include "Utility.h"


// return true if any swap occurred, false otherwise
// a[0...t-1] is already sorted
template <typename T> bool bubble(T* a, int t, int b)
{
	bool swapped = false;
	for(int i=b; i>t;--i){
		if(a[i] < a[i-1]){
            swap(a, i, i-1);
            swapped = true;
        }
    }
    return swapped;
}

template<typename T> void bubbleSort(T* a, int n)
{
	bool swapped = true;
	int t=0;
	while(bubble(a, t++, n-1));
}

#endif