#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
  int data;
  struct list* next;
}list;

list* insert(list*);
void sort(list*);
void display(list*);

int main()
{
  int ch;
  list *f=NULL,*r=NULL;
  do
  {
    printf("\n1.Insert\n2.Sort\n3.Display");
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
         sort(f);
         break;
      case 3:
         display(f);
         break;
    }
  }while(ch<4);
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

void sort(list* f)
{
  int t;
  list *i,*j;
  for(i=f;i->next!=NULL;i=i->next)
  {
   for(j=f;j->next!=NULL;j=j->next)
   {
     if((j->data) > (j->next->data))
     {
       t=j->data;
       j->data=j->next->data;
       j->next->data=t;
     }
   }
 }
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
