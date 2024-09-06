#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
  int data;
  struct queue *next;
}q;

q* enq(q*);
q* deq(q*);
void disp(q *);

int main()
{
  q *f=NULL,*r=NULL;
  int ch;
  do
  {
    printf("\n1.Enqueuq\n2.Dequeue\n3.DIsplay");
    printf("\nENter choice");
    scanf("%d",&ch);
    switch(ch)
    { 
      case 1:
         r=enq(r);
         if(f==NULL)
           f=r;
         break;
      case 2:
         f=deq(f);
         if(f==NULL)
           r=NULL;
         break;
      case 3:
         disp(f);
         break;
    }
  }while(ch<4);
  return 0;
}

q* enq(q *r)
{
  q *p=NULL;
  int x;
  p=(q*) malloc (sizeof(q));
  if(p!=NULL)
  {
    printf("Enter value");
    scanf("%d",&x);
    p->data=x;
    if(r==NULL)
      r=p;
    else
    {
      r->next=p;
      r=p;
    }
    r->next=NULL;
  }
  else
    printf("Memory not allocated");
  return r;
}

q* deq(q *f)
{
  q *p=NULL;
  if(f==NULL)
    printf("Empty");
  else
  {
    p=f;
    printf("%d",f->data);
    f=f->next;
    free(p);
  }
  return f;
}

void disp(q *f)
{
  if(f==NULL)
     printf("Queue is empty");
  else
  {
    while(f!=NULL)
    {
      printf("%d ",f->data);
      f=f->next;
    }
  }
}
