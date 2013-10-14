#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
bool isalpha(char a);
bool isupper(char a);
bool islower(char a);
int main(int argc,char* argv[])
{    
    // check if input is valid
    if (argc != 2)
    {   
        printf("Usage: ./caesar <key>");
        return 1;
    }
    //convert the argument into numbers
    int keylen = strlen(argv[1]);
    int key[keylen];    
    for(int i = 0;i<keylen;i++)
    {
        if (isupper(argv[1][i]) == true)
        {
            key[i] = argv[1][i]-65;
        }
        if (islower(argv[1][i]) == true)
        {
            key[i] = argv[1][i]-97;
        }
        if (isalpha(argv[1][i]) == false)
        {   printf("Usage: ./caesar <keyletters>");
            return 1;
        }
        
    }
    string plaintext= GetString();
    int length = strlen(plaintext);
    
    // encrypt
    for (int i=0,k=0;i<length;i++)
    {
        if (isalpha(plaintext[i]) == true)
        {
            if (isupper(plaintext[i]) == true)
            {   
                // compute its position in alphabat and shift 
                //65 is the begining of the upper case letters                                          
                plaintext[i] = 65+(key[k%keylen]+plaintext[i]-65)%26;
                printf("%c",plaintext[i]);
            }
            if (islower(plaintext[i]) == true)
            {
                // compute its position in alphabat and shift
                //97a is the begining of the lower case 
                plaintext[i] = 97+(key[k%keylen]+plaintext[i]-97)%26;
                printf("%c",plaintext[i]);
            }
            k++;// keep track of the cycle
        }
        else 
            printf("%c",plaintext[i]);
       
       
    }
    printf("\n");
    return 0;
}
// check if it's a letter
bool isalpha(char a)
{
    if ((a>=65&&a<=95)||(a>=97&&a<=122))
        return true;
    else 
        return false;
}
// check its case
bool isupper(char a)
{
    if (a>=65&&a<=95)
        return true;
    else 
        return false;
}
// check its case
bool islower(char a)
{
    
    if (a>=97&&a<=122)
        return true;
    else 
        return false;
}
