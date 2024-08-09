#include<stdio.h>
#define max 10
int enque(int[],int);
int deque(int[],int,int);
void dis(int[],int,int);
void peek(int[],int);
int main()
{
  int ch,q[max],F=-1,R=-1;
  do
  {
    printf("\nMAIN MENU\n1.enque\n2.deque\n3.display\n4.peek\n");
    printf("Enter choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
            R = enque(q,R);
            if(F==-1)
            {
              F=0;
            }
            break;
       case 2:
            F = deque(q,F,R);
            if(F==-1)
            {
              R=-1;
            }
            break;
      case 3:
            dis(q,F,R);
            break;
      case 4:
            peek(q,F);
            break;
      default:
             printf("Envalid choice"); 
    }
  }while(ch<=4);
  return 0;
}

int enque(int q[],int R)
{
  int x;
  if(R==max-1)
  { 
    printf("queue is full");
  }
  else
  {
    printf("\nENter value");
    scanf("%d",&x);
    R++;
    q[R]=x;
  }
  return R;
}

int deque(int q[],int F,int R)
{
  int x;
  if(F==-1 && R==-1)
  {
    printf("queue is empty");
  }
  else
  {
    x=q[F];
    printf("%d",x);
    if(F==R)
    {
      F=-1;
    }
    else
    {
      F++;
    }
  }
  return F;
}

void dis(int q[],int F,int R)
{
  if(R==-1 && F==-1)
  {
    printf("queue is empty");
  }
  else
  {
    while(F<=R)
    {
      printf("%d,",q[F]);
      F++;
    }
  }
}

void peek(int q[],int F)
{
  if(F==-1)
  {
    printf("queueis empty");
  }
  else
  {
    printf("%d",q[F]);
  }
  
}
