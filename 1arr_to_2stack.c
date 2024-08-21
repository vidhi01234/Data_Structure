#include <stdio.h>
# define max 5
#include <stdlib.h>
void push (int*,int*,int*,int*);
void pop (int*,int*,int*,int*);
void peek (int*,int*,int ,int );
void display (int* ,int* ,int ,int );
int main()
{
    int ch,*stack1,*stack2,top1=-1,top2=-1;
    stack1=(int*)malloc (max*sizeof(int));
    stack2=(int*)malloc (max*sizeof(int));
    do
    {
        printf("\nMAIN MENU\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n");
        printf("enter choice:");
        scanf("%d:",&ch);
        switch(ch)
        {
            case 1:
                    push (stack1,stack2, &top1, &top2);
                    break;
            case 2:
                    pop (stack1,stack2,&top1,&top2);
                    break;
            case 3:
                    peek(stack1,stack2,top1,top2);
                    break;
            case 4:
                    display (stack1,stack2,top1,top2);
                    break;
        }
    }while(ch<=4);

    return 0;
}
void push (int *stack1,int *stack2,int *top1,int *top2)
{
    int x,n;
    printf("Enter stack 1 or 2:");
    scanf("%d",&n);
    if(n==1)
    {
        if(*top1==max-1)
        {
            printf("Stack is full");
        }
        else
        {
            printf("Enter value:");
            scanf("%d",&x);
            (*top1)++;
            stack1[*top1]=x;
        }
    }
    if(n==2)
    {
        if(*top2==max-1)
        {
            printf("Stack is full");
        }
        else
        {
            printf("Enter value:");
            scanf("%d",&x);
            (*top2)++;
            stack2[*top2]=x;
        }
    }
}
void pop (int *stack1,int *stack2,int *top1 ,int *top2)
{
    int x,n;
    printf("Enter stack 1 or 2:");
    scanf("%d",&n);
    if(n==1)
    {
        if(*top1==-1)
        {
            printf("Stack is empty");
        }
        else
        {
            x=stack1[*top1];
            printf("%d",x);
            (*top1)--;
        }
    }
    if(n==2)
    {
        if(*top2==-1)
        {
            printf("Stack is empty");
        }
        else
        {
            x=stack2[*top2];
            printf("%d",x);
            (*top2)--;
        }
    }
}
void peek (int *stack1,int *stack2,int top1,int top2)
{
    int n;
    printf("Enter stack 1 or 2:");
    scanf("%d",&n);
    if(n==1)
    {
        if(top1==-1)
        {
            printf("Stack is empty");
        }
        else
        {
            printf("%d",stack1[top1]);
        }
    }
    if(n==2)
    {
        if(top2==-1)
        {
            printf("Stack is empty");
        }
        else
        {
            printf("%d",stack2[top2]);
        }
    }
}
void display (int *stack1 ,int *stack2,int top1,int top2)
{
    int n;
    printf("Enter stack 1 or 2:");
    scanf("%d",&n);
    if(n==1)
    {
        if(top1==-1)
        {
            printf("Stack is empty");
        }
        else
        {
            while(top1!=-1)
            {
                printf("%d,",stack1[top1]);
                (top1)--;
            }
        }
    }
    if(n==2)
    {
        if(top2==-1)
        {
            printf("Stack is empty");
        }
        else
        {
            while(top2!=-1)
            {
                printf("%d,",stack2[top2]);
                (top2)--;
            }
        }
    }
}
