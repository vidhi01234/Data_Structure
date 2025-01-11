#include<stdio.h>
#include<stdlib.h>

typedef struct clist
{
    int data;
    struct clist*next;
}cl;

void cenq(cl**,cl**);
void cdeq(cl**,cl**);
void display(cl*);

int main()
{
    cl*f=NULL,*r=NULL;
    int ch;
    do
    {
        printf("\n1.Enque\n2.Deque\n3.Display");
        printf("\nEnter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            cenq(&f,&r);
            break;
        case 2:
            cdeq(&f,&r);
            break;
        case 3:
            display(f);
            break;
        }
    }while(ch<3);
    return 0;
}

void cenq(cl**f1,cl**r1)
{
    cl*p=NULL;
    p=(cl*)malloc(sizeof(cl));
    if(p!=NULL)
    {
        printf("ENter data:");
        scanf("%d",&p->data);
        if(*f1==NULL && *r1==NULL)
            *f1=*r1=p;
        else
        {
            (*r1)->next=p;
            *r1=p;
        }
        (*r1)->next=*f1;
    }
}

void cdeq(cl**f1,cl**r1)
{
    cl *p=NULL;
    if(*f1==NULL && *r1==NULL)
        printf("Empty");
    else
    {
        p=*f1;
        printf("%d",(*f1)->data);
        *f1=(*f1)->next;
        (*r1)->next=*f1;
        if(*f1==*r1)
            *f1=*r1=NULL;
        free(p);
    }
}

void display(cl*f)
{
    cl *p=f;
    if(f==NULL)
        printf("EMpty list");
        return;
    do
    {
        printf("%d ",p->data);
        p=p->next;
    }while(p!=f);
}
