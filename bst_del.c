#include<stdio.h>
#include<stdlib.h>

typedef struct tree_type
{
    struct tree_type*left;
    int data;
    struct tree_type*right;
}tree;

void insert(tree**,int);
void inorder(tree*);
void delete (tree**,int);

int main()
{
    tree*root=NULL;
    int ch,num=0,key=0;
    do
    {
        printf("\n1.Insert\n2.Inorder\n3.Delete");
        printf("\nEnter choice");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\nEnter num:");
            scanf("%d",&num);
            insert(&root,num);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            printf("\nEnter key:");
            scanf("%d",&key);
            delete(&root,key);
            break;
        }
    }while(ch<4);
    return 0;
}

void insert(tree** rt,int n)
{
    if(*rt==NULL)
    {
        *rt=(tree*)malloc(sizeof(tree));
        (*rt)->data=n;
        (*rt)->left=NULL;
        (*rt)->right=NULL;
    }
    else
    {
        if(n<(*rt)->data)
            insert(&(*rt)->left,n);
        else
            insert(&(*rt)->right,n);
    }
}

void inorder (tree*rt)
{
    if(rt==NULL)
        return;
    else
    {
        inorder(rt->left);
        printf("%d ",rt->data);
        inorder (rt->right);
        return;
    }
}

void delete(tree**rt,int key)
{
    tree* temp;
    if(*rt==NULL)
        return;

    else
    {
        if(key<(*rt)->data)
            delete(&(*rt)->left,key);
        else if (key>(*rt)->data)
             delete(&(*rt)->right,key);
        else
        {
            if((*rt)->right==NULL && (*rt)->left==NULL)
            {
                free(*rt);
                *rt=NULL;
            }
            else if((*rt)->right!=NULL && (*rt)->left==NULL)
            {
                temp=(*rt);
                *rt=(*rt)->right;
                free(temp);
            }
            else if((*rt)->right==NULL && (*rt)->left!=NULL)
            {
                temp=(*rt);
                *rt=(*rt)->left;
                free(temp);
            }
            else if ((*rt)->right!=NULL && (*rt)->left!=NULL)
            {
                temp=(*rt)->right;
                while((temp)->left!=NULL)
                    temp=(temp)->left;

                (*rt)->data=temp->data;
                delete(&(*rt)->right,temp->data);
            }
        }
    }
}
