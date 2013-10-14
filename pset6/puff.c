/****************************************************************************
 * puff.c
 *
 * Computer Science 50
 * Problem Set 6
 *
 * puff a binary file into text file
 ***************************************************************************/

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "forest.h"
#include "huffile.h"
#include "tree.h"



Tree* hufftree(Forest* ptr);

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 3)
    {
        printf("Usage: %s input output\n", argv[0]);
        return 1;
    }

    // open input
    Huffile* input = hfopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open %s for reading.\n", argv[1]);
        return 1;
    }
    
    // create puffed file
    FILE* output = fopen(argv[2],"w");
    if (output == NULL)
    {
        hfclose(input);
        printf("Could not open %s for puffing",argv[2]);
        return 1;
    }

    // read in header
    Huffeader header;
    if (hread(&header, input) == false)
    {
        hfclose(input);
        fclose(output);
        printf("Could not read header.\n");
        return 1;
    }

    // check for magic number
    if (header.magic != MAGIC)
    {
        hfclose(input);
        fclose(output);
        printf("File was not huffed.\n");
        return 1;
    }

    // check checksum
    int checksum = header.checksum;
    for (int i = 0; i < SYMBOLS; i++)
    {
        checksum -= header.frequencies[i];
    }
    if (checksum != 0)
    {
        hfclose(input);
        fclose(output);
        printf("File was not huffed.\n");
        return 1;
    }

    
    
    // huffman forest
    Forest* huff = mkforest();
    if (huff == NULL)
    {
        hfclose(input);
        fclose(output);
        fprintf(stderr,"No memory for forest\n");
        return 1;
    }
    
    // ctreate a forest 
    for (int i = 0;i < SYMBOLS;i++)
    {
        // create a tree for every character
        Tree* temp = mktree();
        if (temp == NULL)
        {
            rmforest(huff);
            hfclose(input);
            fclose(output);
            fprintf(stderr,"No memory for trees\n");
            return 1;
        }
        if ((temp->frequency = header.frequencies[i]) != 0)
        {
            temp->symbol = i;
        
            // plant this tree into forest
            if (plant(huff,temp) == false)
            {
                rmtree(temp);
                rmforest(huff);
                hfclose(input);
                fclose(output);
                fprintf(stderr,"Couldn't plant\n");
                return 1;
            }
        }   
        else
            rmtree(temp); 
    }
    
    // create a haffman tree from that forest
    Tree* huffmantree = hufftree(huff);
    if (huffmantree == NULL)
    {
        rmforest(huff);
        fclose(output);
        hfclose(input);
        return 1;
    } 
    
    // decoding and output
    int bit;
    int temp;
    Tree* ptr = huffmantree;
    while ((bit = bread(input)) != EOF)
    {
        ptr = (bit == 0)?(ptr->left):(ptr->right);
        if (ptr->left == NULL && ptr->right ==NULL)
        {
            temp = ptr->symbol;
            fputc(temp,output);
            ptr = huffmantree;
        }
          
    }    
    
    // remove forest
    rmforest(huff);
    
    // close output file
    fclose(output);
   

    // close input
    hfclose(input);

    // that's all folks!
    return 0;
}



Tree* hufftree(Forest* ptr)
{
    // only one tree left
    if (ptr->first->next == NULL)
        return ptr->first->tree;
    else
    {
        // pick two trees with lowest two weights
        Tree* lefttree = pick(ptr);
        Tree* righttree = pick(ptr);
        
        if(lefttree == NULL || righttree == NULL)
            return NULL;
        
        // create a new tree form them two
        Tree* new = mktree();
        if (new == NULL)
        {
            return NULL;
        }
        new->left = lefttree;
        new->right = righttree;
        new->frequency = lefttree->frequency + righttree->frequency;
        
         
        // plant it back forest
        if (plant(ptr,new) == false)
        {
            rmtree(new);
            return NULL;
        }
        else
            return hufftree(ptr);
    }
}

