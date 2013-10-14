#include <stdio.h>
#include <stdlib.h>
int main (void)
{
    FILE* f = fopen("./test.txt","w");
    char* a = malloc(sizeof(char)*8);
    fgets(a,8,stdin);
    fprintf(f,"%s\n",a);
    fclose(f);
    free(a);
}
