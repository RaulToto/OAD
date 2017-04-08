#include <stdio.h>
#include <string.h>
char* streverse(char *list,int cont,int size)
{
    char tem;
    if ( cont>size)
    {
        return NULL;
    }
    tem=list[cont];
    list[cont]=list[size];
    list[size]=tem;
    streverse(list,cont+1,size-1);
    return list;

   
}
int mystrlen(char *s)
{
    int n;
    for (n  = 0; *s != '\0'; *s++)
    {
        n++;
    }
    return n;

}
int main()
{
    char list[]="mamita";
    streverse(list,0,mystrlen(list)-1);
    printf("%s",list);
    return 0;
}
