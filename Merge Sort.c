#include<stdio.h>

void merge(int *arr,int l,int m,int r)
{
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    
    int L[n1],R[n2];
    
    for(i=0;i<n1;i++)
    {
        L[i]=arr[l+i];
    }
    for( j=0;j<n2;j++)
    {
        R[j]=arr[m+1+j];
    }
    i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k++]=L[i++];
        }
        else{
            arr[k++]=R[j++];
        }
    }
    
    while(i<n1)
    {
        arr[k++]=L[i++];
    }
    while(j<n2)
    {
        arr[k++]=R[j++];
    }
    
}
void mergeSort(int arr[],int l,int r)
{
    if(l<r)
    {
        int mid=l+(r-l)/2;
    
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
    
        merge(arr,l,mid,r);
    }
}

void print(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main()
{
   int size;
   printf("Enter capacity:");
   scanf("%d",&size);
   printf("Enter elements\n");int arr[size];
   for(int i=0;i<size;i++)
   {
       scanf("%d",&arr[i]);
   }
   
   printf("Original array: ");
   print(arr,size);
   
   mergeSort(arr,0,size-1);
   
   printf("Sorted array: ");
   print(arr,size);
   
   return 0;   
}