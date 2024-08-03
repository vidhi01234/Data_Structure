#include<stdio.h>
#define max 5
void push(int[],int *);
void pop(int[],int *);
void peek(int[],int);
void display(int[],int);
int main()
{
  int stack[max],top=-1,ch;
  do
  {
    printf("\n*MAIN MENU*");
    printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit");
    printf("\nEnter choice");
    scanf("%d",&ch);
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
             display(stack,top);
             break;
    }
  }while(ch<=4);
   return 0;
}

void push(int stack[],int *top)
{
  int x;
  if((*top)==max-1)
  {
    printf("Stack overflow");
  }
  else
  {
  printf("Enter value\n");
  scanf("%d",&x);
    (*top)++;
    stack[*top]=x;
  }
}

void pop(int stack[],int *top)
{
  int x;
  if((*top)==-1)
  {
    printf("Stack is underflow");
  }
  else
  { 
    x=stack[*top];
    printf("%d",x);
    (*top)--;
  }
}

void peek(int stack[],int top)
{
  if((top)==-1)
  {
    printf("Stack is underflow");
  }
  else
  {
    printf("%d",stack[top]);
  }
}

void display(int stack[],int top)
{
  if((top)==-1)
  {
    printf("Stack is underflow");
  }
  else
  {
    while((top)!=-1)
    {
      printf("elements is:%d",stack[top]);
      (top)--;
    }
  }
}
