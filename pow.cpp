#include <iostream>
#include <stdio.h>
using namespace std;
float pow(int ,int );
int main()
{
    cout << pow(2,-2);    
}

float pow(int a ,int b)
{
    if (b<0)
    {
        return (1.0/a)*pow(a,b+1);
    }
    else if (b==0)
    {

        return 1;
    }

    else
    {
        return a*pow(a,b-1);
    } 
}

