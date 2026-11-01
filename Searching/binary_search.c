#include<stdio.h>
int main()
{
    int arr[20],i,mid,high,n,low,key,found=0;
    printf("Enter the number of element:");
    scanf("%d",&n);
    if(n<=0 || n>20)
  {
    printf("Invalid number of elements");
    return 0;
  }
    printf("Enter the %d sorted element: ",n);
 // Enter elements in ascending order
    for(i=0;i<n;i++)
    {
     scanf("%d",&arr[i]);
    }
    printf("Enter the element to be searched:");
    scanf("%d",&key);
    low=0,high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==key)
        {
         printf("Element found at the position %d",mid+1);
         found=1;
         break;
        }
        else if(arr[mid]>key)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    if(found==0)
    {
        printf("Element not present");
    }
    return 0;
}

