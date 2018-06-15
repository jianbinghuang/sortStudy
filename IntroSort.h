#ifndef INTROSORT_H
#define INTROSORT_H

#include "System.h"
#include "Utility.h"


template <int32_t ElemSize> class alSwap { public: alSwap(void *qb, void *qe); };
template <int32_t ElemSize> class alRotate { public: alRotate(void *qb, void *qe); };

template <int32_t ElemSize>
alSwap<ElemSize>::alSwap(void *qb, void *qe)
{    /* swap elements *qb and *qe */
    int8_t buf[ElemSize];
    memmove(buf, qb,  ElemSize);
    memmove(qb,  qe,  ElemSize);
    memmove(qe,  buf, ElemSize);
}

template <int32_t ElemSize>
alRotate<ElemSize>::alRotate(void *qb, void *qe)
{    /* right rotate [*qb, *qe] one place */
    int8_t buf[ElemSize];
    int8_t *pL = (int8_t *) qb,
            *pR = (int8_t *) qe;
    int64_t n = (pR - pL);
    memmove(buf, pR, ElemSize);
    memmove(pL + ElemSize, pL, n);
    memmove(pL, buf, ElemSize);
}


template <class ElemType>
void adjust_heap(ElemType *qb,
                 size_t h,
                 size_t n)
{    /* reheap item at h in heap (char qb[size])[n] */
    size_t h0 = h;
    size_t k = 2 * h + 2;
    ElemType *qh = qb + h;
    ElemType *qk = qb + k;
    
    for (; k <= n; k = 2 * k + 2, qk = qb + k)
    {    /* percolate hole out to larger/only child */
        if (k == n || *qk < *(qk - 1))
            --k, qk--;
        alSwap<sizeof(ElemType)>(qh, qk);
        h = k, qh = qk;
    }
    
    for (; h0 < h; )
    {    /* percolate hole back in as far as h0 */
        size_t i = (h - 1) / 2;
        ElemType *qi = qb + i ;
        if (!(*qi < *qh))
            break;
        alSwap<sizeof(ElemType)>(qi, qh);
        h = i, qh = qi;
    }
}


template <class ElemType>
void intro_sort(ElemType *qb,
                size_t n,
                size_t ideal)
{    /* sort recursively */
    const size_t SortMax = 32;    /* > 1, cutover for insertion sort */

    for (; 0 < ideal && SortMax < n; )
    {    /* quick sort with fat pivot */
        size_t m = n / 2;
        ElemType *qm = qb + m;
        ElemType *qf = qb, *ql = qb + n;
        
        if (*qm < *qf)
            alSwap<sizeof(ElemType)>(qf, qm);
        if (*(ql - 1) < *qm)
            alSwap<sizeof(ElemType)>(qm, (ql - 1));
        if (*qm < *qf)
            alSwap<sizeof(ElemType)>(qf, qm);
        
        for (; ; qf++)
        {    /* partition about pivot value */
            for (; qf < ql && !(*qm < *qf) ; qf++)
                ;
            for (; qb < ql && !(*--ql < *qm) ; )
                ;
            if (ql <= qf)
                break;
            
            alSwap<sizeof(ElemType)>(qf, ql);
            if (qm == qf)
                qm = ql;
            else if (qm == ql)
                qm = qf;
        }
        ideal /= 2, ideal += ideal / 2;
        m = (ql - qb) + 1;
        n -= (qf - qb);
        if (m <= n)
            intro_sort(qb, m, ideal), qb = qf;
        else
            intro_sort(qf, n, ideal), n = m;
    }
    
    if (SortMax < n)
    {    /* heap sort */
        size_t h;
        ElemType *qe;
        for (h = n / 2; 0 < h; )
            adjust_heap(qb, --h, n);
        for (qe = qb + n ; 1 < n; )
        {    /* pop largest item to (shrinking) end */
            alSwap<sizeof(ElemType)>(qb, --qe);
            adjust_heap(qb, (size_t)0, (size_t)(--n));
        }
    }
    else if (1 < n)
    {    /* insertion sort */
        ElemType *qm;
        for (qm = qb; 0 < --n; )
        {    /* percolate back elements [2, n) */
            qm++;
            if (*qm < *qb)
                alRotate<sizeof(ElemType)>(qb, qm);
            else
            {    /* scan backwards for insertion point */
                ElemType *qx = qm, *qx0 = qm;
                for (; *qm < *--qx0; qx = qx0)
                    ;
                if (qx != qm)
                    alRotate<sizeof(ElemType)>(qx, qm);
            }
        }
    }
}

template <class ElemType>
void introSort(ElemType *qb, size_t n)
{
    return intro_sort(qb, n, n);
}

#endif