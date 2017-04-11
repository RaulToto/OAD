#include <iostream>
#include <stack>
using namespace std;
void roll(stack<char> &stack,int n ,int k)
{
    char lista[n];
    char tem[n];
    for(int i=0;i<n;i++)
    {
        lista[i]=stack.top();
        stack.pop();
    }
    int cont=0;
    while(cont<k)
    {
        
        for(int i=0;i<n;i++)
        {
            
            if(i==n-1)
            {
                tem[n-1]=lista[0];
            }
            else
                tem[i]=lista[i+1];
          
        }
        
        for(int i=0;i<n;i++)
        {
            lista[i]=tem[i];
        }
        cont++;
    }
    /*
    for(int i=0;i<n;i++)
    {
        cout << tem[i] << endl;
    }*/
    cout << "-------" << endl;
    for(int i=1;i<=n;i++)
    {
        stack.push(tem[n-i]);
    }
    //stack.push(tem[n-1]);
    //stack.push(tem[n-2]);
    //stack.push(tem[n-3]);
    while (!stack.empty())
    {
        cout << stack.top() << endl;
        stack.pop();
    }
    cout << endl;

}
int main()
{
    stack<char> s;
    int n=3,k=2;
    for(int i='A';i<'E';i++)
    {
        s.push(i);
    }/*
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;*/
    roll(s,2,4);
}