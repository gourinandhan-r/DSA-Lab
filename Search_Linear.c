#include <stdio.h>
int main()
{
    int i, n, item, flag = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements: ");
    for (i = 0; i < n; i++) 
        scanf("%d", &arr[i]);
    printf("The given array: ");
    for (i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
    printf("Enter the item to search for: ");
    scanf("%d", &item);
    for (i = 0; i < n; i++) 
	{
        if (arr[i] == item) 
		{
            printf("Item found at index: %d\n", i);
            flag = 1;
            break; 
        }
    }
    if (!flag)
        printf("Item not found\n");
    return 0;
}
