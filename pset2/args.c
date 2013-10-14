#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
bool isalpha(char a);
bool isupper(char a);
bool islower(char a);
int main(int argc,char* argv[])
{
    if (argc != 2)
        return 1;
    int key = atoi(argv[1]);
    string plaintext= GetString();
    int length = strlen(plaintext);
    
    
    for (int i=0;i<length;i++)
    {
        if (isalpha(plaintext[i]) == true)
        {
            if (isupper(plaintext[i]) == true)
            {
                plaintext[i] = 64+(key+plaintext[i]-64)%24;
                printf("%c",plaintext[i]);
            }
            if (islower(plaintext[i]) == true)
            {
                plaintext[i] = 96+(plaintext[i]+key-96)%24;
                printf("%c",plaintext[i]);
            }
            
        }
        else 
            printf("%c",plaintext[i]);
       
       
    }
    printf("\n");
    return 0;
}
bool isalpha(char a)
{
    if ((a>=65&&a<=95)||(a>=97&&a<=122))
        return true;
    else 
        return false;
}
bool isupper(char a)
{
    if (a>=65&&a<=95)
        return true;
    else 
        return false;
}
bool islower(char a)
{
    
    if (a>=97&&a<=122)
        return true;
    else 
        return false;
}
