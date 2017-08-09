#ifndef RANGE_H
#define RANGE_H

#include <stdexcept>
using namespace std;
class Range:public runtime_error
{
public:
    Range():runtime_error("ingreso un valor fuera de rango"){}

};

#endif // RANGE_H
