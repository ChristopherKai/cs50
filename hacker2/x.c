#include <stdio.h>
#include <stdlib.h>
int main (void)
{
    FILE* f = fopen("/home/jharvard/Dropbox/pset3/data","a");
    char* x = malloc(sizeof(char)*8);
    char c ;
    int n = 0;
    while ( (c = fgetc(stdin)) != '\n')
    {
        *x = c;
        x++;
        n++;
    }
    *x = '\0';
    x -= n;
    fputs(x,f);
    free(x);
    fclose(f);
    
    
    
}
