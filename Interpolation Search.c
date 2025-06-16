#include<stdio.h>
int Interpolation(int arr[],int low,int high,int key)
{
    while(low<=high && key>=arr[low] && key<=arr[high])
    {
        if(arr[low]==arr[high])
        {
            if(arr[low]==key)
            {
                return low;
            }
            else
            {return -1;}
        }
        int pos=low+(((key-arr[low])*(high-low))/(arr[high]-arr[low]));
        if(pos<low || pos>high || (pos<low && pos>high))
        {
            return -1;
        }
        if(arr[pos]<key)
        {
            low=pos+1;
        }
        if(arr[pos]>key)
        {
            high=pos-1;
        }
        if(arr[pos]==key)
        {
            return pos;
        }
    }
    return -1;
}
int isSort(int sort[],int size)
{
    for(int i=0;i<size;i++)
    {
        if(sort[i]>sort[i+1])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n;
    printf("Capacity:");scanf("%i",&n);
    printf("Enter array element in sorted manner:\n");int arr[n];
    int i=0;
    for(;i<n;i++)
    {
        printf("arr[%d] = ",i);
        scanf("%d",&arr[i]);
        printf("\n");
    }
    int ele;
    if(isSort(arr,n))
    {
    printf("Enter element you want to search:");
    scanf("%d",&ele);
    int result=Interpolation(arr,0,n-1,ele);
    (result!=-1)?printf("%d found at index %d",ele,result):printf("Element not found!");
    }
    else {
        printf("Array must be in sorted manner!\n");
    }
    return 0;
}