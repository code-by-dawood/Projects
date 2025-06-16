#include <stdio.h>
#define max 100

void linearsearch(int arr[], int element, int size)
{
    int found = 0;
    printf("Result:\n");
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == element)
        {
            printf("%d element found at %d position\n", arr[i], i);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Element not found!\n");
    }
}

int main()
{
    printf("Linear Search O(n)\n");
    int arr[max];
    int n, element;
    printf("Enter size:");
    scanf("%d", &n);
    printf("Enter elements\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Element you want to search:");
    scanf("%d", &element);
    printf("\n");
    linearsearch(arr, element, n);

    return 0;
}
