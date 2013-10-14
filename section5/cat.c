#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Usage: cat filename [filename ...]\n");
        return 1;
    }

    for (int i = 1; i < argc; i++)
    {
        FILE* f = fopen(argv[i],"r");
        char buffer[128];
        int j;
        for ( j = 0 ;(buffer[j] = fgetc(f)) != EOF ;j++);
        buffer[j-1] = '\0';
        printf("%s\n",buffer);
        fclose(f);
        
    }

    return 0;
}

