#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
int main(int argc,char* argv[])
{
    FILE* f = fopen("/usr/share/dict/words","r");
    char a[128];
    char* key;
    key = a;
    char* unknown = argv[1];
    while (fscanf(f,"%s\n",key) == 1)
    {
        if (strcmp(unknown,crypt(key,"50"))==0)
        {     
            printf("key is %s\n",key);
            fclose(f);
            return 0;
        }
    }
    fclose(f);
    return 0;
    
}
