// test scaffold
#include "HashMap.h"

extern void testHashMap()
{
    MapInt32Int32 map;
    for(int i=0; i<100; ++i) 	map.insert(i, i);
    for(int i=0; i<100; ++i){
	    IteratorInt32Int32 iter = map.find(i);
        assert(iter.isValid() && iter.key() == i);
    }
    for(int i=0; i<100; ++i) 	map.remove(i);
    for(int i=0; i<100; ++i){
	    IteratorInt32Int32 iter = map.find(i);
        assert(!iter.isValid());
    }
}
