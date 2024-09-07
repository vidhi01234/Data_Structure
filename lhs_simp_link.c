#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
  int data;
  struct list *next;
}
sl;
int main()
{
  sl*p=NULL,*l=NULL;
  int ch,v;
  while(1)
  {
    p=(sl*) malloc (sizeof(sl));
    if(p!=NULL)
    {
      printf("Enter value");
      scanf("%d",&v);
      p->data=v;
      p->next=l;
      l=p;
    }
    printf("do you want to continue");
    scanf("%d",&ch);
    if(ch==0)
      break;
   }
   p=l;
   while(p!=NULL)
   {
     printf("%d,",p->data);
     p=p->next;
   }
   return 0;
 }
