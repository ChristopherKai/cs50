/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "dictionary.h"



typedef struct node
{
    bool is_word;
    struct node* children[27];
}node;

node* root = NULL;

int total = 0;

struct stack
{
    int size;
    node* p[LENGTH+1];
}buffer;


bool push(node* a)
{
    if (buffer.size == LENGTH)
        return false;
    else
    {
        buffer.p[buffer.size] = a;
        buffer.size++;
        return true;
    }
}

node* pop(void)
{
    if (buffer.size == 0)
        return false;
    else
    {
        return buffer.p[--buffer.size];
    }
}
/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    int i = 0,temp;
    node* ptr = root; 
    while (word[i] != '\0')
    {
        if (word[i] == '\'')
        {
            ptr = ptr->children[0];
            if (ptr == NULL)
                return false;
        }
        else 
        {
            temp = (word[i] | 96) & (~ 96);
            ptr = ptr->children[temp];
            if (ptr == NULL)
                return false;
        }
        i++;
            
    }
    if (ptr->is_word == true)
        return true;
    else
        return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    FILE* f = fopen(dictionary,"r");
    int temp;
    root = malloc(sizeof(node));
    memset(root,0,sizeof(node));
    root->is_word = false;
    node* ptr = root;
    while ((temp = fgetc(f)) != EOF)
    {
        if (temp == '\n')
        {
            ptr->is_word = true;
            total++;
            ptr = root;
        }    
        else if (temp == '\'')
        {
            // hash " \' "
            temp = 0;
            if (ptr->children[temp] == NULL)
            {
                ptr->children[temp] = malloc(sizeof(node));
                memset(ptr->children[temp],0,sizeof(node));
                ptr->children[temp]->is_word = false;
            }
            ptr = ptr->children[temp];
            ptr->is_word = false;
            
        }
        else
        {
            // hash the character 96 is 0110 0000 in binary
            temp &= ~96;            
            
            // create a new node
            if (ptr->children[temp] == NULL)
            {
                ptr->children[temp] = malloc(sizeof(node));
                memset(ptr->children[temp],0,sizeof(node));
                ptr->children[temp]->is_word = false;
            }
            ptr = ptr->children[temp];
            
            
        }
        
    }
    if (f == NULL)
        return false;
    else
    {
        fclose(f);
        return true;
    }
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return total;
}
bool help(node* ptr)
{
    int flag = 0;
    for (int i = 0;i < 27;i++)
    {
        if(ptr->children[i] != NULL)
        {
            push(ptr);
            ptr = ptr->children[i];
            if (help(ptr) == true)
            {
                ptr = pop();
                flag++;
            }
        }
        else
            flag++;
    }
    if (flag == 27)
    { 
       free(ptr);
       return true;
    }
    else 
        return false;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    node* ptr = root;
    if (help(ptr) == true)
        return true;
    else
        return false;
}
