// test scaffold
#include <cassert>
#include <stdlib.h>
#include "QuickSort.h"
#define SIZE 1000

bool testQs(int s)
{
	int *a = new int[s];
	for(int i=0; i<s; ++i) a[i] = rand();
	qs(a, s);
	bool success = true;
	for(int i=0; success && i<s-1; ++i){
		if(a[i] > a[i+1]) success = false;
}
delete [] a;
	return success;
}

void testQuickSort()
{
	assert(testQs(0));
	assert(testQs(1));
	assert(testQs(SIZE));
}


