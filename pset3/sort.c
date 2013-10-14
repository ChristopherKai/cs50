#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#define SIZE 18
void merge(int* array1,int size1,int* array2,int size2);
void sort(int array[], int size)
{
    if (size < 2)
    {
        return;
    }
    else
    {
        sort(array,size / 2);
        sort(array + size / 2,size - size / 2);
        merge(array,size / 2,array + size / 2,size - size / 2);
    }
    
        
}
void merge(int* array1,int size1,int* array2,int size2)
{
    int* array  = malloc(sizeof(int)*(size1 + size2));
    int i,j,k = 0;
    for (i = 0,j = 0;i < size1 && j < size2;)
    {
        if (array1[i] < array2[j])
        {
            array[k] = array1[i];
            i++;
            k++;
        }
        else
        {
            array[k] = array2[j];
            j++;
            k++;
        }
    }
    if (i == size1)
    {
        for (;j < size2;j++,k++)
            array[k] = array[j];
        
    }
    else
    {
        for (;i < size1;i++,k++)
            array[k] = array1[i];
    }
    for (int i = 0;i < size1 + size2 ;i++ )
        array1[i] = array[i];
    free(array);
    return;
    
}
int main(void)
{
    int numbers[SIZE] = {9,8,7,6,5,4,3,2,1,21,32,14,24,15,67,43,68,23};
    for (int i = 0; i < SIZE; i++)
        printf("%d ", numbers[i]);
    printf("\n");
    sort(numbers, SIZE);
    for (int i = 0; i < SIZE; i++)
        printf("%d ", numbers[i]);
    printf("\n");
    return 0;
}
