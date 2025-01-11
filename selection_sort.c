#include<stdio.h>

void selection(int[],int);

int main()
{
    int arr[10],n,i;
    printf("Enter no. of data to wanna store: ");
    scanf("%d",&n);
    printf("\nENter data");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    selection(arr,n);
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}

void selection(int a[],int n)
{
    int i,j,pos,min;
    for(i=0;i<n-1;i++)
    {
        min=a[i];
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(min>a[j])
            {
                min=a[j];
                pos=j;
            }
        }
        if(pos!=i)
        {
            a[pos]=a[i];
            a[i]=min;
        }
    }
}
