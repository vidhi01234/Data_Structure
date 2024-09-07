#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
  int data;
  struct list *next;
}sl;
int main()
{
  int x,t;
  sl *p=NULL,*l=NULL,*r=NULL;
  do
  {
    p=(sl*) malloc (sizeof(sl));
    if(p!=NULL)
    {
    printf("Enter value");
    scanf("%d",&x);
      p->data=x;
      if(l==NULL&&r==NULL)
      {
        l=p;
        r=p;
      }
      else
      {
        r->next=p;
        r=p;
      }
    }
    printf("Do you wish to continue:");
    scanf("%d",&t);
  }while (t!=0);
  r->next=NULL;
  p=l;
  while(p!=NULL)
  {
    printf("%d",p->data);
    p=p->next;
  }
  return 0;
}
