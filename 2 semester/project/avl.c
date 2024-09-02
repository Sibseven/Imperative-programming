#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define minimal 1000000001

typedef struct Tree
{
    struct Tree *left, *right;
    void* value;
    void* adr_struct;
    size_t size;
    int height;
}Root;

Root* rotateLeft(Root* root)
{
    Root* temp = root->right;
    root->right = root->right->left;
    temp->left = root;
    return temp;
}

Root* rotateRight(Root* root)
{
    Root* temp = root->left;
    root->left = root->left->right;
    temp->right = root;
    return temp;
}

void updateHeight(Root* root)
{
    int height = 0;
    
    if (root->left != NULL)
    {
        height = height > root->left->height ? height : root->left->height;
    }
    
    if(root->right != NULL)
    {
        height = height > root->right->height ? height : root->right->height;
    }
    
    root->height = height + 1;
}

Root* rebalance(Root* root)
{
    int heightLeft, heightRight;
    heightLeft = root->left == NULL ? 0 : root->left->height;
    heightRight = root->right == NULL ? 0 : root->right->height;

    if (abs(heightLeft - heightRight) <= 1)
    {
        updateHeight(root);
        return root;
    }

    if (heightRight > heightLeft)
    {
        int heightRightLeft, heightRightRight;
        heightRightLeft = root->right->left == NULL ? 0 : root->right->left->height;
        heightRightRight = root->right->right == NULL ? 0 : root->right->right->height;
        
        if (heightRightLeft == heightRightRight + 1)
        {
            root->right = rotateRight(root->right);
        }

        root = rotateLeft(root);
        updateHeight(root->left);
        updateHeight(root);
    }
    else
    {
        int heightLeftLeft, heightLeftRight;
        heightLeftLeft = root->left->left == NULL ? 0 : root->left->left->height;
        heightLeftRight = root->left->right == NULL ? 0 : root->left->right->height;

        if(heightLeftRight == heightLeftLeft + 1)
        {
            root->left = rotateLeft(root->left);
        }

        root = rotateRight(root);
        updateHeight(root->right);
        updateHeight(root);
    }
    return root;
}

void lower_bound(Root* root, void* value, void** minimum, void** minimum_adr, size_t* size)
{
    if (root == NULL)
    {
        return;
    }
    if ((size_t)root->value > (size_t)value)
    {
        //printf("LEFT %zu %zu\n", (size_t)root->value, (size_t)value);
        lower_bound(root->left, value, minimum, minimum_adr, size);
    }
    else{
        *minimum = root->adr_struct;
        *minimum_adr = root->value;
        *size = root->size;
        //printf("RIGHT %zu %zu\n", (size_t)root->value, (size_t)value);
        lower_bound(root->right, value, minimum, minimum_adr, size);
    }
    

}

Root* delete(Root* root, void* value)
{
    if(root == NULL)
    {
        printf("miss\n");
        return root;
    }
    if(root->value > value)
    {
        root->left = delete(root->left, value);
    }
    else if (root->value < value)
    {
        root->right = delete(root->right, value);
    }
    else
    {
        if(root->left == NULL)
        {
            Root* temp = root->right;
            free(root);
            printf("removed\n");
            return temp;
        }
        else if (root->right == NULL)
        {
            Root* temp = root->left;
            free(root);
            printf("removed\n");
            return temp;
        }
        Root* step = root->right;
        while (step->left != NULL)
        {
            step = step->left;
        }
        root->value = step->value;
        root->right = delete(root->right, step->value);
    }
    return rebalance(root); 
}


Root* add(Root* root, void* value, void* adr_struct, size_t size)
{
    if(root == NULL)
    {   
        Root* new = (Root*)malloc(sizeof(Root));
        new->value = value;
        new->adr_struct = adr_struct;
        new->height = 0;
        new->size = size;
        new->left = new->right = NULL;
        //printf("added\n");
        return new;
    }
    
    if((size_t)root->value > (size_t)value)
    {
        root->left = add(root->left, value, adr_struct, size);
    }
    else if ((size_t)root->value <(size_t) value)
    {
        root->right = add(root->right, value, adr_struct, size);
    }
    else
    {
        printf("dupe\n");
        return root;
    }
    
    return rebalance(root);
}

void freeTree(Root* root)
{
    if (root == NULL)
    {
        return;
    }
    
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
