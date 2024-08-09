#include<stdio.h>
#define max 5
int cenque(int[],int,int);
int cdeque(int[],int,int);
void dis(int[],int,int);
void peek(int[],int,int);
int main()
{
  int ch,R=-1,F=-1,cq[max];
  do
  {
    printf("\nMAIN MENU\n1.enqueue\n2.dequeue\n3.display\n4.peek\n");
    printf("ENter choice:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
            R=cenque(cq,F,R);
            if(F==-1)
            {
              F=0;
            }
            break;
      case 2:
            F=cdeque(cq,F,R);
            if(F==-1)
            R=-1;
            break;
      case 3:
            dis(cq,F,R);
            break;
      case 4:
            peek(cq,F,R);
            break;
    }
    }while(ch<=4);
  return 0;
}

int cenque(int cq[],int F,int R)
{
  int x;
  if((R+1)%max==F)
  {
    printf("circular queue is full");
  }
  else
  {
    printf("\nEnter value:");
    scanf("%d",&x);
    R=(R+1)%max;
    cq[R]=x;
  }
  return R;
}

int cdeque (int cq[],int F,int R)
{
  int x;
  if(R==-1&&F==-1)
  {
    printf("QUeue is Empty");
  }
  else
  {
    x=cq[F];
    printf("\nDequeue value is:%d",x);
    if(F==R)
       F=-1;
    else
       F=(F+1)%max;
  }
  return F;
}

void dis(int cq[],int F,int R)
{
  if(F==-1 && R==-1)
    printf("Queue is Empty");
  else
  {
    while(F!=R)
    {
      printf("\n%d,",cq[F]);
      F=(F+1)%max;
    }
    printf("%d",cq[F]);
  }
}

void peek(int cq[],int F,int R)
{
   if(R==-1&&F==-1)
  {
    printf("QUeue is Empty");
  }
  else
    printf("Peek value:%d",cq[F]);
}
