#include <stdio.h>
#include <stdbool.h>
#include <cs50.h>

typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
}node;

node* root;

bool insert(node* ptr,int i)
{
    if (ptr->val == i)
        return false;
    else if (ptr->val > i)
    {
        if (ptr->left == NULL)
        {
            ptr->left = malloc(sizeof(node));
            ptr->left->val = i;
            return true;
        }
        else
            return insert(ptr->left,i);
    }
    else (ptr->val <i)
    {
        if (ptr->right == NULL)
        {
            ptr->right = malloc(sizeof(node));
            ptr->right->val = i;
            return true;
        }
        else
            return insert(ptr->right,i);
    }
        
}
bool contain(node* ptr,int i)
{   
    if (ptr == NULL)
        return false;
    else if (i > ptr-> val)
        return contain(ptr->right,i);
    else if (i < ptr->val)
        return contain(ptr->left,i);
    else
        return true;
        
}
int cal(node* ptr)
{
    int n = 0;
    if ((ptr->left == NULL && ptr->right != NULL) || (ptr->left != NULL && ptr->right ==NULL))
        return 
        
}
int main(void)
{
    root = malloc(sizeof(node));
    root->val = 7; 
    insert(root,3);
    insert(root,9);
    insert(root,6);
    insert(root,5);
    insert(root,2);
    insert(root,8);
    insert(root,1);
    insert(root,4);
    insert(root,9);
    insert(root,2);
    int i;
    if (contain(root,i =GetInt()) == true)
        printf("exist %d\n",i);
    return 0;
    
    
}
