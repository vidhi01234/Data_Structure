#include<stdio.h>
#define max 5
void enque(int[],int*,int*);
void deque(int[],int*,int*);
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
            enque(q,&R,&F);
            /*if(*F==-1)
            {
              *F=0;
            }*/
            break;
       case 2:
            deque(q,&F,&R);
            /*if((*F)==-1)
            {
              *R=-1;
            }*/
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

void enque(int q[],int *R,int *F)
{
  int x;
  if((*R)==max-1)
  { 
    printf("queue is full");
  }
  else
  {
    printf("\nENter value");
    scanf("%d",&x);
    (*R)++;
    q[*R]=x;
  }
  if((*F)==-1)
    {
        (*F)=0;
    }
  
}

void deque(int q[],int *F,int *R)
{
  int x;
  if((*F)==-1 && (*R)==-1)
  {
    printf("queue is empty");
  }
  else
  {
    x=q[*F];
    printf("%d",x);
    if((*F)==(*R))
    {
      (*F)=-1;
    }
    else
    {
      (*F)++;
    }
    if((*F)==-1)
        {
            (*R)=-1;
        }
  }
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
    printf("queue is empty");
  }
  else
  {
    printf("%d",q[F]);
  }
  
}
