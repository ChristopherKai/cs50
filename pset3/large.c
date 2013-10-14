#include <stdio.h>
#include <stdlib.h>
int main (void)
{
    FILE* f = fopen("/home/jharvard/Dropbox/pset3/largenote","w");
    char* x = "dasdhasjkdhskajdhsajkdhasjkdhsjkadhjkashdjkasdhjkasdjksahjkdhasjkd";
    int n = 0;
    while ( n <= 49999)
    {
        fputs(x,f);
        n++;
    }
    fclose(f);
}
