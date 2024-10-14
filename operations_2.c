#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
  int data;
  struct list* next;
}list;

list* insert(list*);
void display(list*);
void count(list*);
void pos_ins(list*);
void alter(list*);

int main()
{
  int ch;
  list *f=NULL,*r=NULL;
  do
  {
    printf("\n1.Insert\n2.Display\n3.count\n4.insert_pos\n5.Alternate");
    printf("\nEnter choices:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
         r=insert(r);
         if(f==NULL)
            f=r;
         break;
      case 2:
         display(f);
         break;
      case 3:
        count(f);
        break;
      case 4:
        pos_ins(f);
        break;
      case 5:
        alter(f);
        break;
    }
  }while(ch<6);
  return 0;
}

list* insert(list*r)
{
  list* p=NULL;
  p=(list*) malloc(sizeof(list));
  if(p!=NULL)
  {
    printf("Enter data:");
    scanf("%d",&p->data);
    if(r==NULL)
      r=p;
    else
    {
      r->next=p;
      r=p;
    }
    r->next=NULL;
  }
  return r;
}

void display(list *f)
{
  if(f==NULL)
    printf("List is empty");
  else
  {
    while(f!=NULL)
    {
      printf("%d ",f->data);
      f=f->next;
     }
   }
}

void count(list*tp)
{
    int c=0,e=0,o=0;
    while(tp!=NULL)
    {
        c++;
        if(tp->data%2==0)
            e++;
        else
            o++;
        tp=tp->next;
    }
    printf("total number of nodes are:%d\n",c);
    printf("Even nodes:%d\nOdd nodes:%d:",e,o);
}

void pos_ins(list* tp)
{
    int x,i;
    list*p=NULL;
    p=(list*)malloc (sizeof(list));
    printf("Enter data:");
    scanf("%d",&p->data);
    printf("Enter position:");
    scanf("%d",&x);
    for(i=1;i<x-1&&tp!=NULL;i++)
        tp=tp->next;
    p->next=tp->next;
    tp->next=p;

}

void alter(list *tp)
{
    while(tp!=NULL)
    {
        printf("%d ",tp->data);
        if(tp->next==NULL)
            break;
        tp=tp->next->next;
    }
}
