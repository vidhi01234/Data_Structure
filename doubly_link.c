#include<stdio.h>
#include<stdlib.h>

typedef struct dlist
{
  struct dlist *pre;
  int data;
  struct dlist *next;
}dl;

dl*insert (dl*);
dl* delete (dl*);
void display (dl*);

int main()
{
  dl *f=NULL,*r=NULL;
  int ch;
  do
  {
   printf("\n1.Insert\n2.Deletion\n3.Display");
   printf("\nEnter Choice:");
   scanf("%d",&ch);
   switch(ch)
   {
     case 1:
            r=insert(r);
            if(f==NULL)
            {
              f=r;
            }
            break;
     case 2:
            f=delete(f);
            if(f==NULL)
               r=NULL;
            break;
     case 3:
            display(f);
            break;
   }
 }while(ch<4);
 return 0;
}

dl*insert(dl* r)
{
  dl *p=NULL;
  p=(dl*) malloc (sizeof(dl));
  if(p!=NULL)
  {
    printf("Insert data");
    scanf("%d",&(p->data));
    if(r==NULL)
    {
      r=p;
      p->pre=NULL;
    }
    else
    {
      p->pre=r;
      r->next=p;
      r=p;
    }
    r->next=NULL;
    return r;
  }
}

dl* delete(dl* f)
{
  dl *p=NULL;
  if(f==NULL)
      printf("LinkList is Empty");
  else
  {
    p=f;
    printf("%d",p->data);
    f=f->next;
    if(f!=NULL)
    {
      f->pre=NULL;
    }
    free(p);
    return f;
  }
}

void display(dl*f)
{
  if(f==NULL)
     printf("Empty");
  else
  {
    while(f!=NULL)
    {
      printf("%d ",f->data);
      f=f->next;
    }
  }
}
