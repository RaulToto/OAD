#include <stdio.h>
//#include "simpio.h"

void getshape(int row, int column, char shape);
void fill(char shape, int row, int column);
int main()
{
    int row, column;
    int r, c;
    char shape[row][column];
    getshape(shape, row, column);
    fill(shape, row, column);
    getchar();
    return 0;
}
void getshape(int row, int column, char shape)
{
     printf("Enter the number of rows\n");
     row=GetInteger();
     printf("Enter the number of columns\n");
     column=GetInteger();
     
     char end='.';
     printf("Enter a shape and when your done enter '.'\n");
     while ((end=getchar()) != '.')
     {
           shape=getchar();
     }
}
void fill(char shape, int row, int column)
{
     int r, c;
     printf("Enter the interior point(where the program will start filling)\n");
     printf("Enter the row number\n");
     r=GetInteger();
     printf("Enter the column number\n");
     c=GetInteger();
     if (r < 0 || r > row || c > column || c < 0) return;
     if (shape[r][c] == '*' || shape[r][c] == '#') return;
     fill[r][c] = '*';
	
	 fill(shape,r+1,c);//down
	 fill(shape,r-1,c);//up
	 fill(shape,r,c-1);//left
	 fill(shape,r,c+1);//right
} 