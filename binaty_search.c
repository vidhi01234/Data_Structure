#include<stdio.h>

int binary(int[],int,int,int);

int main()
{
    int arr[10],n,lb=0,ub,i,key,f;
    printf("Enter number: ");
    scanf("%d",&n);
    printf("Enter data:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    ub=n-1;
    printf("Enter key you wanna search:");
    scanf("%d",&key);
    f=binary(arr,lb,ub,key);
    if(f==1)
        printf("Found");
    else
        printf("not found");
}

int binary(int a[],int lb,int ub,int key)
{
    int mid=0;
    while(lb<=ub)
    {
        mid=(lb+ub)/2;
        if(a[mid]==key)
            return 1;
        else if(a[mid]<key)
            lb=mid+1;
        else
            ub=mid-1;
    }
    return 0;
}
