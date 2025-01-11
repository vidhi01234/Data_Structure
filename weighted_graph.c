#include<stdio.h>
#include<stdlib.h>

typedef struct graph
{
    int data;
    int weight;
    struct graph*next;
}graph;

void read(graph* [],int);
void display(graph* [],int);

int main()
{
    int i,n;
    graph* adj[10];
    printf("ENter no of vertices: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        adj[i]=NULL;

    read(adj,n);
    display(adj,n);
    return 0;
}

void read(graph* adj[],int n)
{
    int i,j,k;
    graph*p=NULL;
    for(i=0;i<n;i++)
    {
        graph*temp=NULL;
        printf("Enter no. of adjacent vertices of %d: ",i);
        scanf("%d",&k);
        for(j=0;j<k;j++)
        {
            p=(graph*)malloc(sizeof(graph));
            printf("Enter data and weight: ");
            scanf("%d %d",&p->data,&p->data);
            p->next=NULL;
            if(adj[i]==NULL)
                adj[i]=p;
            else
                temp->next=p;
            temp=p;
        }
    }
}

void display(graph* adj[],int n)
{
    int i;
    graph*temp=NULL;
    for(i=0;i<n;i++)
    {
        temp=adj[i];
        printf("\nVertices adjacent to %d is: ",i);
        while(temp!=NULL)
        {
            printf("(%d weight:%d) ",temp->data,temp->weight);
            temp=temp->next;
        }
    }
}
