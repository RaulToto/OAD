#ifndef EXCEPTIONINTLEGAL_H
#define EXCEPTIONINTLEGAL_H

#include <stdexcept>
using namespace std;
class ExceptionIntLegal:public runtime_error
{
public:
    ExceptionIntLegal():runtime_error("entero no legal"){}

};

#endif // EXCEPTIONINTLEGAL_H
