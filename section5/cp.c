#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("Usage: cp source destination\n");
        return 1;
    }

    FILE* f1 = fopen(argv[1],"r");
    FILE* f2 = fopen(argv[2],"w");
    char a ;
    while ((a = fgetc(f1)) != EOF)
        fputc(a,f2);
    fclose(f1);
    fclose(f2);
    return 0;
}

