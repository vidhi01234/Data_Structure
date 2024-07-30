#include <stdio.h>
#define max 10
int push(int[],int);
int pop(int[],int);
void dis(int[],int);
void peek(int[],int);
int main()
{
    int choice,top=-1,stack[max];
    do
    {
        printf("\n*******MAIN MENU********");
        printf("\n1.PUSH");
        printf("\n2.POP");
        printf("\n3.DISPLAY");
        printf("\n4.PEEK");
        printf("\n5.EXIT\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    top=push(stack,top);
                    break;
            case 2:
                    top=pop(stack,top);
                    break;
            case 3:
                    dis(stack,top);
                    break;
            case 4:
                    peek(stack,top);
                    break;
        }
    }while(choice<=4);

    return 0;
}

int push(int stack[],int top)
{
    int x;
    if(top==max-1)
    {
        printf("stack is overflow\n");
    }
    else
    {
        printf("Enter value to be inserted\n");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
    return top;
}

int pop(int stack[],int top)
{
    int x;
    if (top==-1)
    {
        printf("stack is underflow\n");
    }
    else
    {
        x=stack[top];
        top--;
    }
    return top;
}

void dis(int stack[],int top)
{
    int i;
    if(top==-1)
    {
        printf("stack is underflow\n");
    }
    else
    {
        while(top!=-1)
        {
            printf("elements:%d,",stack[top]);
            top--;
        }
    }
}

void peek(int stack[],int top)
{
    if(top==-1)
    {
        printf("stack is underflow\n");
    }
    else
    {
        printf("top element:%d",stack[top]);
    }
}
