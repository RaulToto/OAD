#include <iostream>
using namespace std;

int main()
{
    int lista[11]={ 0, 0, 0, 0, 0, 0, 1, 2, 4, 2, 1 };
       cout << "Grade distribution:" << endl;

   // for each element of array n, output a bar of the chart
   for ( int i = 0; i < 11; ++i ) 
   {
      // output bar labels ("0-9:", ..., "90-99:", "100:" )
      if ( 0 == i )
         cout << "  0-9: ";
      else if ( 10 == i )
         cout << "  100: ";
      else
         cout << i * 10 << "-" << ( i * 10 ) + 9 << ": ";

      // print bar of asterisks
      for ( unsigned int stars = 0; stars < lista[ i ]; ++stars )
         cout << '*';

      cout << endl; // start a new line of output
   } // end outer for

}