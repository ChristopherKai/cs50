#include <cs50.h>
#include <stdio.h>

#define SIZE 8

bool search(int needle, int haystack[], int size)
{
    int mid = size  / 2;
    int begin = 0;
    int end = size - 1;
    while (begin <= end)
    {
        mid = (end + begin) / 2;
        if (needle > haystack[mid])
        {
            begin = mid + 1;
            
        }
        else if (needle < haystack[mid])
             {
                end = mid - 1;
             }
            
            else return true;
    }
    
    return false;
         
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
