#include<stdio.h>

void mergesort(int[],int[],int ,int);
void merge(int[],int[],int,int,int);

int main()
{
    int arr[10],t[10],n,i;
    printf("Enter no. of data to wanna store: ");
    scanf("%d",&n);
    printf("\nENter data:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    mergesort(arr,t,0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}

void mergesort(int a[],int t[],int lb,int ub)
{
    int mid=0;
    if(lb<ub)
    {
        mid=(lb+ub)/2;
        mergesort(a,t,lb,mid);
        mergesort(a,t,mid+1,ub);
        merge(a,t,lb,mid,ub);
    }
}

void merge(int a[],int t[],int lb,int mid,int ub)
{
    int k=lb,i=lb,j=ub,le=mid;
    while(lb<=le && (mid+1)<=ub)
    {
        if(a[lb]<a[mid+1])
        {
            t[k++]=a[lb];
            lb++;
        }
        else
        {
            t[k++]=a[mid+1];
            mid++;
        }
    }
    while(lb<=le)
    {
        t[k++]=a[lb];
        lb++;
    }
    while((mid+1)<=ub)
    {
        t[k++]=a[mid+1];
        mid++;
    }
    for(i=0;i<=ub;i++)
    {
        a[i]=t[i];
    }
}
