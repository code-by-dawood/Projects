#include<stdio.h>
#define max 100
int parent;

void swap(int *ele1,int *ele2)
{
    int temp=*ele1;
    *ele1=*ele2;
    *ele2=temp;
}
void insert(int arr[],int *n,int val)
{
    *n=(*n)+1;
    arr[*n]=val;
    int i=*n;
    
    while(i>1)
    {
        parent=i/2;
        if(arr[parent]>arr[i]) //< for max heap , > for min heap
        {
            swap(&arr[parent],&arr[i]);
            i=parent;
        }
        
        else{
            break;
        }
    }
}
int main()
{
    int arr[max];int size;
    int heapsize=0;
    printf("Enter Capacity:");
    scanf("%d",&size);
    
    printf("Enter insertion elements:");printf("\n");
    for(int i=0;i<size;i++)
    {
        int val;
        scanf("%d",&val);
        insert(arr,&heapsize,val);
    }

    printf("Final Max heap:\n");
    for(int i=1;i<=heapsize;i++)
    {
        printf("%d\n",arr[i]);
    }
    
    return 0;
}