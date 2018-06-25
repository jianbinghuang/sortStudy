#ifndef INSERTIONMERGESORT_H
#define INSERTIONMERGESORT_H

#include "System.h"

#define INSERTIONSIZE 32

/// Merge two sorted chunks of data, a[la...ra] and b[lb...rb] and the sorted result is put in a third 
/// array c[sc...sc+ra-la+rb-lb]
/// @pre ra > la, rb > lb
template <typename T> inline void merge(T* a, int32_t la, int32_t ra, T* b, int32_t lb, int32_t rb, T* c, int32_t sc)
{
	T* as = a+la, *ae = a+ra, *bs=b+lb, *be=b+rb;
	T* ac = as, *bc=bs, *cc=c+sc;
	while(ac || bc){
		if(!ac){
			memcpy(cc, bc, sizeof(T)*(be-bc+1));
			bc=nullptr;
        }
        else if(!bc){
			memcpy(cc, ac, sizeof(T)*(ae-ac+1));
			ac=nullptr;
        }
        else{
            if(*ac > *bc){
	            *(cc++) = *bc;
	            bc = (bc==be) ? nullptr:bc+1;
            }
            else{
	            *(cc++) = *ac;
	            ac = (ac==ae) ? nullptr:ac+1;
            }
        }
    }
}

/// @pre sortSpan < n
template <typename T> inline void sortOneLevel(T* a, int32_t n, int32_t sortSpan, T* t)
{
	int32_t s=0;
	while(s<n){
	    if(n-s >= 2*sortSpan){
		    merge(a,s,s+sortSpan-1, a, s+sortSpan, s+2*sortSpan-1, t, s);
		    s += 2*sortSpan;
        }
        else if(n-s>sortSpan){
		    merge(a,s,s+sortSpan-1, a, s+sortSpan, n-1, t, s);
		    s = n;
        }
        else{
            memcpy(t+s, a+s, (n-s)*sizeof(T));
            break;
        }
    }
}

template <typename T> void insertionMergeSort(T* a, int32_t n)
{
	int32_t curr = 0;
	while(1){
		int32_t rem = n-curr-INSERTIONSIZE;
		if(rem >= 0){
		    insertionSort(a, curr, curr+INSERTIONSIZE-1);
		    curr += INSERTIONSIZE;
        }
        else{
	        insertionSort(a, curr, n-1);
	        break;
        }
    }
	T* t = new T[n];
    int32_t sortSpan = INSERTIONSIZE;
    bool swapped = false;
	while(sortSpan < n){
		if(!swapped){
		    sortOneLevel(a, n, sortSpan, t);
		    swapped = true;
        }
        else{
	        sortOneLevel(t,n,sortSpan,a);
	        swapped = false;
        }
		sortSpan *= 2;	
    }

    if(swapped)
	    memcpy(a, t, sizeof(T)*n);
    delete [] t;
}



#endif