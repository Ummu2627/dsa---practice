#include<stdio.h>
int main()
{
    int arr[30],i,j,n,key;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    if(n<=0 || n>30)
    {
        printf("Invalid number of elements");
        return 0;
    }
    printf("Enter the %d elements:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
    
     while(j>=0&& arr[j]>key)
     {
        arr[j+1]=arr[j];
        j--;
     }
     arr[j+1]=key;
    }
    printf("Sorted Array:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
