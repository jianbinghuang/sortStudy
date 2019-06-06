// test scaffold
#include "SelectionSort.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "StdSort.h"
#include "InsertionMergeSort.h"
#include "HashMap.h"
#include "Timer.h"

using namespace std;
 
#define SORTSIZE 10000

struct SortElem
{
    SortElem() = default;
    SortElem(int ik) : k(ik), v(0) {}
    bool operator<(const SortElem& rhs) const { return k<rhs.k; }
    bool operator<=(const SortElem& rhs) const { return k<=rhs.k; }
    bool operator>(const SortElem& rhs) const { return k>rhs.k; }
    bool operator>=(const SortElem& rhs) const { return k>=rhs.k; }
    bool operator==(const SortElem& rhs) const { return k==rhs.k; }
    int operator-(const SortElem& rhs) const { return k-rhs.k; }
    int32_t k;
    int32_t v;
};

template<typename Callable> bool testSort(int32_t s, Callable f)
{
	SortElem *a = new SortElem[s];
    MapInt32Int32 keyMap;
	for(int32_t i=0; i<s; ++i){
        a[i] = rand();
        keyMap.insert(a[i].k, i);
    }

	f(a, s);
	bool success = true;
	for(int32_t i=0; success && i<s-1; ++i){
		if(a[i] > a[i+1])
            success = false;
    }
	for(int32_t i=0; success && i<s; ++i){
        if(!keyMap.find(a[i].k).isValid())
            success = false;
    }

    delete [] a;
	return success;
}


void testSort()
{
    Timer t;
#if 0
    // Works but extremely slow
	Demand(testSort(0, [&](SortElem* a, int32_t n) { bubbleSort(a, n); }), "bubble sort failed.");
	Demand(testSort(1, [&](SortElem* a, int32_t n) { bubbleSort(a, n); }), "bubble sort failed.");
    t.start();
	Demand(testSort(SORTSIZE, [&](SortElem* a, int32_t n) { bubbleSort(a, n); }), "bubble sort failed.");
    cout<<"bubble sort:"<<t.elapsedTime()<<" seconds."<<endl;

	Demand(testSort(0, [&](SortElem* a, int32_t n) { selectionSort(a, n); }), "selection sort failed.");
	Demand(testSort(1, [&](SortElem* a, int32_t n) { selectionSort(a, n); }), "selection sort failed.");
    t.start();
	Demand(testSort(SORTSIZE, [&](SortElem* a, int32_t n) { selectionSort(a, n); }), "selection sort failed.");
    cout<<"selection sort:"<<t.elapsedTime()<<" seconds."<<endl;
#endif

	Demand(testSort(0, [&](SortElem* a, int32_t n) { insertionSort(a, n); }), "insertion sort failed.");
	Demand(testSort(1, [&](SortElem* a, int32_t n) { insertionSort(a, n); }), "insertion sort failed.");
    t.start();
	Demand(testSort(SORTSIZE, [&](SortElem* a, int32_t n) { insertionSort(a, n); }), "insertion sort failed.");
    cout<<"insertion sort:"<<t.elapsedTime()<<" seconds."<<endl;

	Demand(testSort(0, [&](SortElem* a, int32_t n) { qs(a, n); }), "quick sort failed.");
	Demand(testSort(1, [&](SortElem* a, int32_t n) { qs(a, n); }), "quick sort failed.");
    t.start();
	Demand(testSort(SORTSIZE, [&](SortElem* a, int32_t n) { qs(a, n); }), "quick sort failed.");
    cout<<"Quicksort:"<<t.elapsedTime()<<" seconds."<<endl;

	Demand(testSort(0, [&](SortElem* a, int32_t n) { stdSort(a, n); }), "std sort failed.");
	Demand(testSort(1, [&](SortElem* a, int32_t n) { stdSort(a, n); }), "std sort failed.");
    t.start();
	Demand(testSort(SORTSIZE, [&](SortElem* a, int32_t n) { stdSort(a, n); }), "std sort failed.");
    cout<<"std sort:"<<t.elapsedTime()<<" seconds."<<endl;

	Demand(testSort(0, [&](SortElem* a, int32_t n) { insertionMergeSort(a, n); }), "insertionMerge sort failed.");
	Demand(testSort(1, [&](SortElem* a, int32_t n) { insertionMergeSort(a, n); }), "insertionMerge sort failed.");
    t.start();
	Demand(testSort(SORTSIZE, [&](SortElem* a, int32_t n) { insertionMergeSort(a, n); }), "insertionMerge sort failed.");
    cout<<"insertionMerge sort:"<<t.elapsedTime()<<" seconds."<<endl;
}


