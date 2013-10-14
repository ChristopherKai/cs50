/****************************************************************************
 * mario.c
 *
 * 
 * KaiSong
 *
 * 
 *Get a non-negative integer no greater than 23,
 * which is height of half-pyramid the progarm will creat by hashes.
 ***************************************************************************/
#include <stdio.h>
#include <cs50.h>
int main(void)
{   
    // prompt user to type in height
    printf("Height:");
    int h=GetInt();
    
    
    // repeatedly ask for input if input is not valid
    while (h<0||h>23)
    {  
        printf("Height:");
        h=GetInt();
    }
    
    
    // creat the half-pyramid
    for (int i=1;i<=h;i++)
    {   
        for(int j=h-i;j>0;j--)
        {
            printf(" ");
        }
        for(int k=1+i;k>0;k--)
        {
            printf("#");
        }
            printf("\n");
     }
      
      
    return 0;

}
