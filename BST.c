#include<stdio.h>
#include<stdlib.h>

typedef struct tree_type
{
    struct tree_type *left;
    int data;
    struct tree_type *right ;
}tree;

void insert (tree **,int);
void inorder(tree *);
void preorder(tree *);
void postorder(tree *);
void count (tree *,int *);
void count_leaf(tree* ,int* );
void count_singlechild(tree*,int*);

int main()
{
    tree * root=NULL;
    int ch,num,c,lf,sc;
    do
    {
        printf("\n1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Count nodes\n6.leaf nodes\n7.single child");
        printf("\nEnter choice");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("ENter num");
            scanf("%d",&num);
            insert (&root,num);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            c=0;
            count (root,&c);
            printf("%d",c);
            break;
        case 6:
            lf=0;
            count_leaf(root,&lf);
            printf("%d",lf);
            break;
        case 7:
            sc=0;
            count_singlechild(root,&sc);
            printf("%d",sc);
            break;
        }
    }while(ch<8);
    return 0;
}

void insert(tree** rt,int n)
{
    if(*rt==NULL)
    {
        *rt=(tree**) malloc (sizeof(tree));
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

void inorder (tree * rt)
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

void preorder(tree*rt)
{
    if(rt==NULL)
        return;
    else
    {
        printf("%d ",rt->data);
        preorder(rt->left);
        preorder(rt->right);
        return;
    }
}

void postorder(tree* rt)
{
    if(rt==NULL)
        return;
    else
    {
        postorder(rt->left);
        postorder(rt->right);
        printf("%d ",rt->data);
        return;
    }
}

void count(tree*rt,int *c)
{
    if(rt==NULL)
        return;
    else
    {
        (*c)++;
        count(rt->left,c);
        count(rt->right,c);
    }
}

void count_leaf(tree *rt,int*lf)
{
    if(rt==NULL)
        return;
    if(rt->left==NULL && rt->right==NULL)
    {
        (*lf)++;
    }
    count_leaf(rt->left,lf);
    count_leaf(rt->right,lf);
}

void count_singlechild(tree *rt,int*sc)
{
    if(rt==NULL)
        return;
    if((rt->left==NULL && rt->right!=NULL) || (rt->left!=NULL && rt->right==NULL))
    {
        (*sc)++;
    }
    count_singlechild(rt->left,sc);
    count_singlechild(rt->right,sc);
}

