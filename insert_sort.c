#include<stdio.h>

void insert(int[],int);

int main()
{
    int arr[10],n,i;
    printf("Enter no. of data to wanna store: ");
    scanf("%d",&n);
    printf("\nENter data:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    insert(arr,n);
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}

void insert(int a[],int n)
{
    int i,j,t;
    for(i=1;i<n;i++)
    {
        t=a[i];
        j=i-1;
        while(j>=0 && t<a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=t;
    }
}
