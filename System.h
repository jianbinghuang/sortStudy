#ifndef SYSTEM_H
#define SYSTEM_H

#include <cstdint>      // int type
#include <iostream>     // stream
#include <cassert>      // assert

#define Demand(test, msg) if(!test) throw std::exception(msg);

#endif