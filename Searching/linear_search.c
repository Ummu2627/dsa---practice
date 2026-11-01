#include<stdio.h>
int main()
{
    int arr[20],i,n,key,found=0;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    if(n<=0 || n>20)
   {
    printf("Invalid number of elements");
    return 0;
   }
    printf("enter the %d elements:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter the element to search:");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
    if(arr[i]==key)
      {
        printf("element found at the position %d\n",i+1);
        found=1;
        break;
      }
    } 
    if(found==0)
    {
        printf("Element not found");
    }
    return 0;
}
