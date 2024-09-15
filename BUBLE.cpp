#include<stdio.h>
int main()
{
    int n,i,j,temp;
    printf("Enter the array size:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elments:-\n");
    for(i=0;i<n;i++)
    {
        printf("Enter the element:");
        scanf("%d",&arr[i]);
    }
    printf("Array before sorted:");
    for(i=0;i<n;i++)
    {
        printf("%d,",arr[i]);
    }
    for(i=0;i<n;i++)
    {
       for(j=i+1;j<n;j++)
       {
           if(arr[i]>arr[j])
           {
               temp=arr[j];
               arr[j]=arr[i];
               arr[i]=temp;
           }
       }
    }
    printf("\nArray after sorted:");
    for(i=0;i<n;i++)
    {
        printf("%d,",arr[i]);
    }
}
