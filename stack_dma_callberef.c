#include<stdio.h>
#include<stdlib.h>
#define max 10
void push(int *,int *);
void pop(int *,int *);
void peek(int *,int);
void dis(int *,int);
int main()
{
  int ch,*stack,top=-1;
  stack=(int*)malloc(max*sizeof(int));
  do
  {
    printf("\nMAIN MENU\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n");
    printf("enter choice");
    scanf("%d:",&ch);
    switch(ch)
    {
      case 1:
        push(stack,&top);
        break;
      case 2:
             pop(stack,&top);
             break;
      case 3:
             peek(stack,top);
             break;
      case 4:
             dis(stack,top);
             break;
    }
  }
  while(ch<=4);
  return 0;
}

void push(int *stack,int *top)
{
  int x;
  if((*top)==max-1)
  {
   printf("stack overflow");
  }
  else
  {
    printf("ENter value:");
    scanf("%d",&x);
    (*top)++;
    stack[*top]=x;
  }
}

void pop(int *stack,int *top)
{
  int x;
  if((*top)==-1)
  {
   printf("Stack underflow");
  }
  else
  {
   x=stack[*top];
   printf("%d",x);
   (*top)--;
  }
}

void peek(int *stack,int top)
{
 if((top)==-1)
 {
   printf("Stack underflow");
 }
 else
 {
   printf("\n%d",stack[top]);
 }
}

void dis(int *stack,int top)
{
 if((top)==-1)
 {
   printf("Stack underflow");
 }
 else
 {
   while((top)!=-1)
   {
     printf("\n%d,",stack[top]);
     (top)--;
   }
  }
}
