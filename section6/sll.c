/*************************************************************************
 * sll.c
 *
 * Implements a simple singly-linked list structure for ints.
 ************************************************************************/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// the size of our test list: feel free to adjust as you wish!
#define TEST_SIZE 1000

typedef struct node
{
    // the value to store in this node
    int i;

    // the link to the next node in the list
    struct node* next;
}
node;

// declare the first node of our list (as a global variable)
node* first = NULL;

/**
 * Returns the length of the list.
 */
int length(void)
{
    if (first == NULL)
        return 0;
    else 
    {
        int length = 0;
        node* ptr = first;
        while (ptr->next != NULL)
        {
            length++;
            ptr = ptr->next;
        }
        length++;
        return length;    
    }
}

/**
 * Returns true if a node in the list contains the value i and false
 * otherwise.
 */
bool contains(int i)
{
    if (first == NULL)
        return false;
    else
    {
        node* ptr = first;
        while (ptr->i != i)
        {
            ptr = ptr->next;
            if (ptr == NULL)
                return false;
        }
        return true;
    }
}

/**
 * Puts a new node containing i at the front (head) of the list.
 */
void prepend(int i)
{
    node* new = malloc(sizeof(node));
    new->i = i;
    new->next = NULL;
    if (first == NULL)
        first = new;
    else
    {
        new->next = first;
        first = new;
    }
}

/**
 * Puts a new node containing i at the end (tail) of the list.
 */
void append(int i)
{
    node* ptr = first;
    node* new= malloc(sizeof(node));
    new->i = i;
    new->next = NULL;
    if (ptr == NULL)
    {
        first = new;
        return;
    }
    else
    {   
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = new;
        return;
    }
    
}

/**
 * Puts a new node containing i at the appropriate position in a list
 * sorted in ascending order.
 */
void insert_sorted(int i)
{
    node* ptr1,*ptr2;
    node* new= malloc(sizeof(node));
    new->i = i;
    new->next = NULL;
    if (first == NULL)
    {
        free(new);
        append(i);
    }    
    else if (first->i > i)
    {
        new->next = first;
        first = new;
    } 
    else 
    { 
        ptr1 = first;
        ptr2 = ptr1->next;
        while (ptr2 != NULL)
        {
            if ((ptr1->i <= i) && (ptr2->i > i))
            {
                new->next = ptr2;
                ptr1->next = new; 
                return;
            }
            ptr1 = ptr2;
            ptr2 = ptr2->next;
        }
        free(new);
        append(i);
    }   
        
}

/**
 * Implements some simple test code for our singly-linked list.
 */
int main(void)
{
    printf("Prepending ints 0-%d onto the list...", TEST_SIZE);
    for (int i = 0; i < TEST_SIZE; i++)
    {
        prepend(i);
    }
    printf("done!\n");

    printf("Making sure that the list length is indeed %d...", TEST_SIZE);
    assert(length() == TEST_SIZE);
    printf("good!\n");

    printf("Making sure that values are arranged in descending order...");
    node* n = first;
    for (int i = 0; i < TEST_SIZE; i++)
    {
        assert(n != NULL);
        assert(n->i == TEST_SIZE - i - 1);
        n = n->next;
    }
    printf("good!\n");

    printf("Freeing the list...");
    while (first != NULL)
    {
        node* next = first->next;
        free(first);
        first = next;
    }
    printf("done!\n");

    printf("Appending ints 0-%d to the list...", TEST_SIZE);
    for (int i = 0; i < TEST_SIZE; i++)
    {
        append(i);
    }
    printf("done!\n");

    printf("Making sure that the list length is indeed %d...", TEST_SIZE);
    assert(length() == TEST_SIZE);
    printf("good!\n");

    printf("Making sure that values are arranged in ascending order...");
    n = first;
    for (int i = 0; i < TEST_SIZE; i++)
    {
        assert(n != NULL);
        assert(n->i == i);
        n = n->next;
    }
    printf("good!\n");

    printf("Freeing the list...");
    while (first != NULL)
    {
        node* next = first->next;
        free(first);
        first = next;
    }
    printf("done!\n");

    printf("Inserting %d random ints to the list...", TEST_SIZE);
    for (int i = 0; i < TEST_SIZE; i++)
    {
        insert_sorted(rand() % TEST_SIZE);
    }
    printf("done!\n");

    printf("Making sure that the list length is indeed %d...", TEST_SIZE);
    assert(length() == TEST_SIZE);
    printf("good!\n");

    printf("Making sure that values are arranged in sorted order...");
    n = first;
    int prev = 0;
    for (int i = 0; i < TEST_SIZE; i++)
    {
        assert(n != NULL);
        assert(n->i >= prev);
        prev = n->i;
        n = n->next;
    }
    printf("good!\n");

    printf("Freeing the list...");
    while (first != NULL)
    {
        node* next = first->next;
        free(first);
        first = next;
    }
    printf("done!\n");

    printf("\n********\nSuccess!\n********\n");

    return 0;
}
