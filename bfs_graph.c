#include<stdio.h>
#include<stdlib.h>

typedef struct graph
{
    int data;
    struct graph*next;
}graph;

void read(graph*[],int);
void print(graph*[],int);
void bfs(graph*[],int[],int);

int main()
{
    int i,n,start;
    graph *adj[10];
    int visited[10]={0};
    printf("ENter num. of vertices:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        adj[i]=NULL;
    }

    read(adj,n);
    print(adj,n);

    printf("\nEnter the starting vertex for BFS: ");
    scanf("%d",&start);
    printf("\nStarting vertices of BFS %d: ",start);
    bfs(adj,visited,start);

    return 0;
}

void read(graph* adj[],int n)
{
    graph*p=NULL;
    int i,k,j;
    for(i=0;i<n;i++)
    {
        graph *last=NULL;
        printf("How many adjacent vertices %d has: ",i);
        scanf("%d",&k);
        for(j=0;j<k;j++)
        {
            p=(graph*)malloc(sizeof(graph));
            printf("Enter data: ");
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

void bfs(graph* adj[],int visited[],int start)
{
    int queue[10],f=0,r=0;
    graph*temp=NULL;

    visited[start]=1;
    queue[r++]=start;
    while(f<r)
    {
        int current=queue[f++];
        printf("%d ",current);

        temp=adj[current];
        while(temp!=NULL)
        {
            if(!visited[temp->data])
            {
                visited[temp->data]=1;
                queue[r++]=temp->data;
            }
        temp=temp->next;
        }
    }
}
