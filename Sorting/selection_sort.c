#include<stdio.h>
int main()
{
    int arr[30],i,n,j,max,temp;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the %d elemnt:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n-1;i++)
    {
        max=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]>arr[max])
            {
                max=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[max];
        arr[max]=temp;
    }
    printf("Sorted Array\n");
    for(i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
