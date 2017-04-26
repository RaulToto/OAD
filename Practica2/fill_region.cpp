#include <iostream>
#include <string>
#include <vector>
using namespace std;

void fill_region ( vector < string > & pixels , int row , int col );
string update(string );
int getPlus(string);
int main()
{
    vector < string > pixels ;
    string row ;
    while(cin>>row)
        pixels.push_back(row);
    
    fill_region ( pixels , 9 , 7);
    for ( int i = 0; i < pixels . size (); i ++)
        cout << pixels [ i ] << endl ;
    return 0;
}
void fill_region ( vector < string > & pixels , int row , int col )
{
    string str;
    //pixels[5]=update(str);
    for (int i = 0; i < pixels.size(); i++)
    {
        str=pixels[i];
        pixels[i]=update(str);
    }
}
string update(string str)
{
    for(int i=0;i < str.length();i++)
    {
        if(str[i]=='+')
        {
            if(getPlus(str)>1)
                i++;
            while(str[i]=='-')
            {
                str[i]='+';
                i++;
              
            }
        }
    }
    return str;
}
int getPlus(string str)
{
    int j=0;
    for (int i = 0; i < str.length(); i++)
    {
        if(str[i]=='+')
            j++;
    }
    return j;
}