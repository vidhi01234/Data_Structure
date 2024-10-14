#include <stdio.h>
#define max 10
int pqenq(int [],int );
void pqdeq(int [],int* );
int main()
{
    int pq[max],r=0,ch;
    do{
        printf("\nMenu\n1.Enque\n2.Deque\n");
        printf("Enter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    r=pqenq(pq,r);
                    break;
            case 2:
                    pqdeq(pq,&r);
                    break;
        }
    }while(ch<=2);

    return 0;
}

int pqenq(int pq[],int r)
{
    int p,d;
    if(r>=max-1)
    {
        printf("Queue is full");
    }
    else
    {
        printf("Enter priority and data:");
        scanf("%d%d",&p,&d);
        pq[r]=p;
        pq[r+1]=d;
        r=r+2;
    }
    return r;
}

void pqdeq(int pq[],int *r)
{
    int i,j=0,x,min;
    if(*r==0)
    {
        printf("queue is empty");
        return;
    }
    min=pq[0];
    for(i=2;i<(*r)-1;i+=2)
    {
        if(min>pq[i])
        {
            min=pq[i];
            j=i;
        }
    }
    printf("priority value:%d",pq[j+1]);
    pq[j]=999;
    *r-=2;
}
