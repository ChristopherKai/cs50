/****************************************************************************
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 ***************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


// copy a JPEG from file and return the address of this JPEG and modify its size
char* copy(FILE* f,char* buffer,int* size);


int main(void)
{
    // open file
    FILE* f = fopen("card.raw","r");
    if (f == NULL)
    {
        fprintf(stderr,"Couldn't find %s","card.raw");
        return 1;
    }       
   
    // the number of JPEG that have been found
    int num = 0;
   
    // keep finding untill reach the end of file
    while (feof(f) == 0)
    {
        // a buffer for the content of "card.raw"
        char* buffer = malloc(sizeof(char)*512); 
        if (buffer == NULL)
        {
            fprintf(stderr,"No Memory for buffer");  
            return 2;
        }
            
        // read 512 bytes from file into buffer
        fread(buffer,1,512,f);
       
        // check if its beginning matches the beginning of a JPEG
        if ( buffer[0] == '\377' && buffer[1] == '\330' && buffer[2] == '\377'  && ( buffer[3] == '\340' || buffer[3] == '\341' ) )
        {   
            // name a JPEG
            char* name = malloc(8*sizeof(char));
            sprintf(name,"%03d.jpg",num);
            name[8] = '\0';
           
            // keep track
            num++;
           
            // create a file for JPEG
            FILE* out = fopen(name,"w");  
            if (out == NULL)
            {
                fprintf(stderr,"Couldn't creat %s",name);
                return 3;
            } 
           
            // the size of the JPEG
            int* size = malloc(sizeof(int)); 
            *size = 512;  
           
            // find the entire JPEG 
            buffer = copy(f,buffer,size);
           
            // write the JPEG into a file
            fwrite(buffer,*size,1,out);
           
            // close file and free memory
            fclose(out);
            free(name);
            free(buffer);
            free(size);
        }
        else
            free(buffer);
       
    }
    // close file
    fclose(f);
    return 0;
}


char* copy(FILE* f,char* buffer,int* size)
{
    // read the next 512 bytes into newbuffer
    char* newbuffer = malloc(512*sizeof(char));
    fread(newbuffer,512,1,f);
    
    //  check if reach another JPEG
    if ( newbuffer[0] == '\377' && newbuffer[1] == '\330' && newbuffer[2] == '\377'  && ( newbuffer[3] == '\340' || newbuffer[3] == '\341'))
    {
        // move the cursor backwards
        fseek(f,-512,SEEK_CUR);
        free(newbuffer);
        return buffer;
    }
    else 
    {
        // reach the end of file
        if(feof(f) != 0)
            return buffer;        
        else 
        {
            // increase the buffer
            buffer = realloc(buffer,512 + *size);
                
            // append the newbuffer to buffer
            memcpy(buffer + *size,newbuffer,512);
                
            // increase the size
            *size += 512;
            free(newbuffer);
                
            // check the next 512 bytes 
            return copy(f,buffer,size);
                
         }    
    }
    
}
