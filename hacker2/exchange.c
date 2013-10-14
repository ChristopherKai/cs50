#include <stdio.h>
#include <cs50.h>
int main(void)
{
    int a = GetInt();
    int b = GetInt();
    a ^= b;
    b ^= a;
    a ^= b;
    printf("%d,%d\n",a,b);
}
