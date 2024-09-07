#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
  int data;
  struct stack *next;
}s;
s* push(s*);
s* pop(s*);
void display(s*);

int main()
{
  s*top=NULL;
  int ch;
  do
  {
    printf("\n1.push\n2.pop\n3.display\n4.Exit");
    printf("\nEnter choice");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
          top=push(top);
          break;
      case 2:
           top=pop(top);
           break;
      case 3:
           display(top);
           break;
    }
  }while(ch<4);
  return 0;
}

s*push(s*tp)
{
  int x;
  s*p=NULL;
  p=(s*) malloc (sizeof(s));
  if(p!=NULL)
  {
    printf("Enter value");
    scanf("%d",&x);
    p->data=x;
    p->next=tp;
    tp=p;
  }
  else
  {
    printf("memory not allocated");
  }
  return (tp);
}

s*pop(s *tp)
{
    s *p=NULL;
    if(tp==NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        p=tp;
        printf("%d",tp->data);
        tp=tp->next;
        free(p);
    }
    return tp;
}

void display(s *tp)
{
    if(tp==NULL)
    {
        printf("stack is empty");
    }
    else
    {
        while(tp!=NULL)
        {
            printf("%d ",tp->data);
            tp=tp->next;
        }
    }
}
