#ifndef HASHMAP_H
#define HASHMAP_H

#include "System.h"

#define HASHSIZE 379
template<typename KT, typename VT> struct HashNode
{
    HashNode() : next(nullptr) {}
	HashNode<KT, VT>(const KT& inKey, const VT& inVal) : key(inKey), val(inVal), next(nullptr) {}
	KT key;
	KT val;
	HashNode<KT, VT>* next;
};

inline int32_t straightHash(int32_t key) { return key; }

template<typename KT, typename VT> class Bucket
{
public:
    Bucket() : _pHead(nullptr) {}
    typedef HashNode<KT, VT> HashNodeT;
	HashNodeT* find(const KT& k)
    {
	    HashNodeT* pCurr = _pHead;
	    while(pCurr && pCurr->key != k) pCurr = pCurr->next;
	    return pCurr;
    }
	HashNodeT* insert(const KT& k, const VT& v)
    {
	    HashNodeT *pPrev = nullptr, * pCurr = _pHead;
	    while(pCurr && pCurr->key != k){
		    pPrev = pCurr;
        pCurr = pCurr->next;
    }
	if(pCurr) return pCurr; // already exists
	else if(pPrev){	// _pHead != nullptr
		HashNodeT* pNew = new HashNodeT(k, v);
		pPrev->next = pNew;
		return pNew;
    }
    else{	// _pHead == nullptr
	    _pHead = new HashNodeT(k, v);
	    return _pHead;
    }
}
// return true if k is found and removed, false if k is not found
bool remove(const KT& k)
{
	HashNodeT *pPrev = nullptr, * pCurr = _pHead;
	while(pCurr && pCurr->key != k){
		pPrev = pCurr;
        pCurr = pCurr->next;
    }
	if(pCurr){
        if(pPrev){
	        pPrev->next = pCurr->next;
	        delete pCurr;
        }
        else{
	        _pHead = pCurr->next;
	        delete pCurr;
        }
        return true;
    }
    else return false;
}
private:
	HashNodeT* _pHead;
};

template<typename KT, typename VT> class HashMap
{
	Bucket<KT, VT> _b[HASHSIZE];
public:
typedef HashNode<KT, VT> HashNodeT;
class Iterator
{
	HashNodeT* _n;
public:
	Iterator(HashNodeT* n) : _n(n) {}
    bool isValid() const { return _n != nullptr; }	
	const KT& key() { assert(isValid()); return _n->key; }
	const VT& value() { assert(isValid()); return _n->value; }
};

// return valid iterator if n is found, return invalid otherwise
Iterator find(const KT& k) 
{
	int32_t b_idx = straightHash(k) % HASHSIZE;
	return Iterator(_b[b_idx].find(k));
}

// If n already exists, return Iterator to the existing node
Iterator insert(const KT& k, const VT& v) 
{
	int32_t b_idx = straightHash(k) % HASHSIZE;
           return Iterator( _b[b_idx].insert(k, v));
}

bool remove(const KT& k) 
{
	int32_t b_idx = straightHash(k) % HASHSIZE;
            return _b[b_idx].remove(k);
}
};
typedef HashMap<int32_t, int32_t> MapInt32Int32;
typedef HashMap<int32_t, int32_t>::Iterator IteratorInt32Int32;


#endif