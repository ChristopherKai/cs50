/****************************************************************************
 * greedy.c
 *
 *pset1 
 *
 * KaiSong(Christerpher)
 *
 * 
 *Ask user how much change is owed
 *and spit out the minimum number of coins with which said change can be made
 ***************************************************************************/
 #include <stdio.h>
 #include <cs50.h>
 #include <math.h>
 int main(void)
 {  
    printf("How much is owed?");
    float c = GetFloat();
    
    // check if input is valid
    while (c <= 0)
    {
        printf("How much is owed?");
        c = GetFloat();
    }
    
    
    // covert dollars to cents
    float b = c*100;
    int a = round(b);
    int num_coins = 0;
    
    
    // compute the minimun number of coins possible
    while (a != 0)
    {   
        while (a >= 25)
        {
            a -= 25;
            num_coins++;
        }
        while (a >= 10)
        {
            a -= 10;
            num_coins++;
        }
        while (a >= 5)
        {
            a -= 5;
            num_coins++;
        }
        while (a >= 1)
        {
            a -= 1;
            num_coins++;
        }
        
    }
    
    
    printf("%d\n",num_coins);
    
    
    return 0;
 }
