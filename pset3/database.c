#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#include "students.h"

#define NUM 3

int main(int argc,string argv[])
{
    student student[NUM]; 
    FILE* f = fopen("data","w");
    for (int i = 0; i < NUM; i++)
    {
        printf("input name");
        student[i].name = GetString();
        printf("input id");
        student[i].id = GetInt();
        printf("input score");
        student[i].score = GetInt();
        
    
    
    }
 
    if (f != NULL)
    {
        for (int i = 0; i <NUM; i++)
        {
            fprintf(f,"%s\n",student[i].name);
            fprintf(f,"%d\n",student[i].id);
            fprintf(f,"%d\n",student[i].score);
        }
        fclose(f);
    }
    
    for (int i = 0; i < NUM; i++)
    {
      free(student[i].name);
      
    }
}








