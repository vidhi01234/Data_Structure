#include<stdio.h>
#include<stdlib.h>

typedef struct graph
{
    int data;
    struct graph*next;
}graph;

void read(graph*[],int);
void print(graph*[],int);
void dfs(graph*[],int[],int);

int main()
{
    int i,n,start;
    graph* adj[10];
    int visited[10]={0};
    printf("Enter num. of vertices: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        adj[i]=NULL;
    }
    read(adj,n);
    print(adj,n);

    printf("\nEnter the starting vertex for DFS: ");
    scanf("%d",&start);
    printf("Starting vertices of DFS %d: ",start);
    dfs(adj,visited,start);

    return 0;
}

void read(graph* adj[],int n)
{
    int i,j,k;
    graph* p=NULL;
    for(i=0;i<n;i++)
    {
        graph*last=NULL;
        printf("Enter total adjacent vertices of %d: ",i);
        scanf("%d",&k);
        for(j=0;j<k;j++)
        {
            p=(graph*)malloc(sizeof(graph));
            printf("Enter data: ");
            scanf("%d",&(p->data));
            p->next=NULL;
            if(adj[i]==NULL)
            {
                adj[i]=p;
            }
            else
            {
                last->next=p;
            }
            last=p;
        }
    }
}

void print(graph*adj[],int n)
{
    int i;
    graph*temp;
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

void dfs(graph* adj[],int visited[],int i)
{
    graph*p=NULL;
    visited[i]=1;
    printf("%d ",i);
    p=adj[i];
    while(p!=NULL)
    {
        i=p->data;
        if(!visited[i])
            dfs(adj,visited,i);
        p=p->next;
    }
}
