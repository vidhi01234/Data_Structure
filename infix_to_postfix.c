#include<stdio.h>
#include<ctype.h>
#include<string.h>

void push(char*);
int pop();
int priorty (char);

int stack[50],top=0;

int main()
{
  char infix[30],postfix[30];
  char *i,x,ch=')';
  int j=0,l;
  
  printf("Enter expression:");
  scanf("%s",infix);
  l=strlen(infix);
  infix[l]=ch;
  infix[l+1]='\0';
  
  i=infix;
  while(*i!='\0')
  {
    if(*i=='(')
       push(i);
    else if(isalnum(*i))
    {
      postfix[j]=*i;
      j++;
    }
    else if(*i==')')
    {
      while((x = pop())!='(')
      {
        postfix[j]=x;
        j++;
      }
    }
    else
    {
      while(priorty(stack[top])>=priorty(*i))
      {
        x=pop();
        postfix[j]=x;
        j++;
     }
    push(i);
  }
  i++;
 }
 
 postfix[j]='\0';
 printf("Postfix Equation is:%s",postfix);
  return 0;
}

void push(char *i)
{
    stack[0]='(';
    top++;
    stack[top]= *i;
}

int pop()
{
   return stack[top--];
}    
    
int priorty(char y)
{
  if(y=='(')
   return 0;
  else if(y=='+' ||y=='-')
    return 1;
  else if(y=='*'||y=='/'||y=='^')
    return 2;
  return 0;
}
