#include <cs50.h>
#include <stdio.h>

#define SIZE 8
bool help(int needle,int haystack[],int begin,int end );
bool search(int needle, int haystack[], int size)
{
    return help(needle,haystack,0,size);
}
bool help(int needle,int haystack[],int begin,int end )
{
    if (begin > end)
        return false;
    int mid = (begin +end) / 2;
    if (haystack[mid] == needle) 
        return true;
    else if (haystack[mid] > needle)
            return help(needle,haystack,begin,mid - 1); 
         else
            return help(needle,haystack,mid + 1,end); 
     
    
}

int main(void)
{
    int numbers[SIZE] = { 4, 8, 15, 16, 23, 42, 50, 108 };
    printf("> ");
    int n = GetInt();
    if (search(n, numbers, SIZE))
        printf("YES\n");
    return 0;
}
