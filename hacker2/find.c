#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>


int main(int argc,char* argv[])
{
    char test[9];
    char * cipher = argv[1];
    test[8] = '\0';
    int k = 6;
    for (char i1 = 'a';i1<='z';i1++)
    {
        for (char i2 = 'n';i2<='z';i2++)
        {
            for (char i3 = 'n';i3<='z';i3++)
            {
                for (char i4 ='`';i4<='z';i4++)
                {
                    for (char i5 ='`';i5<='z';i5++)
                    {
                        for (char i6 ='`';i6<='z';i6++)
                        {
                            for (char i7 ='`';i7<='z';i7++)
                            {
                                for(char i8 = 'a';i8<='z';i8++)
                                {
                                    
                                    test[0] = i8;
                                    test[1] = i7;
                                    test[2] = i6;
                                    test[3] = i5;
                                    test[4] = i4;
                                    test[5] = i3; 
                                    test[6] = i2;
                                    test[7] = i1;
                                    switch (k)
                                    {
                                        case 0: test[1] = '\0';break;
                                        case 1: test[2] = '\0';break;
                                        case 2: test[3] = '\0';break;
                                        case 3: test[4] = '\0';break;
                                        case 4: test[5] = '\0';break;
                                        case 5: test[6] = '\0';break;
                                        case 6: test[7] = '\0';break;
                                        case 7: test[8] = '\0';break;
                                        default : ;break;
                                    }
                                    printf("%s\n",test);
                                    if (cipher == crypt(test,"50"))
                                    {
                                        printf("Key is %s\n",test);
                                        return 0;
                                    }
                                    
                                }
                                if (k==0)
                                k++;
                            }
                            if (k==1)
                            k++;
                        }
                        if (k==2)
                        k++;
                    }
                    if (k==3)
                    k++;
                }
                if (k==4)
                {
                    k++;
                    //printf("%s\n",test);
                }
            }
            if (k==5)
            {
                k++;
                //printf("%s\n",test);
            }
        }
        if (k==6)
        {
            k++;
            //printf("%s\n",test);
        }
    }
  
}
