#include<stdio.h>

void bubble(int[],int);

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
    bubble(arr,n);
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}

void bubble(int arr[],int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        int f=0;
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                f=1;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        if(f==0)
            break;
    }
}
