#include<stdio.h>
#include<stdlib.h>

typedef struct graph
{
    int data;
    struct graph*next;
}graph;

void read(graph*[],int);
void print(graph*[],int);

int main()
{
    int i,n;
    graph *adj[10];
    printf("\nENter num. of vertices:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        adj[i]=NULL;
    }
    read(adj,n);
    print(adj,n);
    return 0;
}

void read(graph* adj[],int n)
{
    graph*p=NULL;
    int i,k,j;
    for(i=0;i<n;i++)
    {
        graph *last=NULL;
        printf("\nHow many adjacent vertices %d has: ",i);
        scanf("%d",&k);
        for(j=0;j<k;j++)
        {
            p=(graph*)malloc(sizeof(graph));
            printf("\nEnter data: ");
            scanf("%d",&p->data);
            p->next=NULL;
            if(adj[i]==NULL)
                adj[i]=p;
            else
            {
               last->next=p;
            }
            last=p;
        }
    }
}

void print(graph* adj[],int n)
{
    int i;
    graph*temp=NULL;
    for(i=0;i<n;i++)
    {
        temp=adj[i];
        printf("\nVertices adjacent to %d is: ",i);
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}
