#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
    int data;
    struct list*next;
}l;

void insert(l**,l**);
void display(l*);
void reverse(l**);
void print_rev(l*);

int main()
{
    l *r=NULL,*f=NULL;
    int ch;
    do
    {
        printf("\n1.insert\n2.display\n3.reverse");
        printf("\nEnter choice");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            insert(&r,&f);
            break;
        case 2:
            display(f);
            break;
        case 3:
            reverse(&f);
            break;
        case 4:
            print_rev(f);
            break;
        }
    }while(ch<5);
    return 0;
}

void insert(l** r,l** f)
{
    l*p=NULL;
    p=(l*)malloc(sizeof(l));
    if(p!=NULL)
    {
        printf("Enter data");
        scanf("%d",&p->data);
        if(*r==NULL &&*f==NULL)
            *r=*f=p;
        else
        {
            (*r)->next=p;
            *r=p;
        }
        (*r)->next=NULL;
    }
}

void display(l*f)
{
    if(f==NULL)
        printf("Empty list");
    else
    {
        while(f!=NULL)
        {
            printf("%d ",f->data);
            f=f->next;
        }
    }
}

void reverse(l**f)             //reverse the whole linkedlist
{
    l *next=NULL,*prev=NULL;
    while(*f!=NULL)
    {
        next=(*f)->next;
        (*f)->next=prev;
        prev=*f;
        *f=next;
    }
    *f=prev;
}

void print_rev(l*tp)          //only print reverse
{
    if(tp==NULL)
        return;
    print_rev(tp->next);
    printf("%d",tp->data);
}
