#ifndef EXCEPTIONSUM_H
#define EXCEPTIONSUM_H
#include <stdexcept>
using namespace std;
class ExceptionSum:public runtime_error
{
public:
    ExceptionSum():runtime_error("suma mayor a un entero"){}

};

#endif // EXCEPTIONSUM_H
