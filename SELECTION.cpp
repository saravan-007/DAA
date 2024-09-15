#include<stdio.h>
void selectionsort(int arr[],int n)
{
    int i,j,min;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        int temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
}
int main()
{
    int n,i;
    printf("Enter the array size:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements:-\n");
    for(i=0;i<n;i++)
    {
        printf("Enter the array element:");
        scanf("%d",&arr[i]);
    }
    printf("array before sorted:");
    for(i=0;i<n;i++)
    {
        printf("%d,",arr[i]);
    }
    selectionsort(arr,n);
    printf("\narray after sorted:");
    for(i=0;i<n;i++)
    {
        printf("%d,",arr[i]);
    }
}
