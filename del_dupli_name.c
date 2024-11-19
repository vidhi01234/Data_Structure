#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct list
{
    int roll;
    char name[15];
    struct list*next;
}l;

void insert(l**,l**);
void display(l*);
void del_dupli(l**);

int main()
{
    l *r=NULL,*f=NULL;
    int ch;
    do
    {
        printf("\n1.insert\n2.display\n3.Delete duplicate");
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
            del_dupli(&f);
            break;
        }
    }while(ch<4);
    return 0;
}
void insert(l** r,l** f)
{
    l*p=NULL;
    p=(l*)malloc(sizeof(l));
    if(p!=NULL)
    {
        printf("Enter roll no.");
        scanf("%d",&p->roll);
        printf("Enter name:");
        scanf("%s",&p->name);
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
            printf("%d %s ",f->roll,f->name);
            printf("\n");
            f=f->next;
        }
    }
}

void del_dupli(l**f)
{
    l *temp=NULL;
    l *current=*f;
    l *flag=NULL;
    if(f==NULL)
        return;
    else
    {
        while(current!=NULL)
        {
            flag=current;
            temp=current->next;
            while(temp!=NULL)
            {
                if(strcmp(current->name,temp->name)==0)
                {
                    flag->next=temp->next;
                    free(temp);
                    temp=flag->next;
                }
                else
                {
                    flag=temp;
                    temp=temp->next;
                }
            }
            current=current->next;
        }
    }
}
