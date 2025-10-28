#include<stdio.h>
void main()
{
	int i, n, j, temp;
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter the array elements: ");
	for(i=0; i<n; i++)
	{
	scanf("%d", &arr[i]);
	}
	printf("The given array: ");
	for(i=0; i<n; i++)
		printf("%d \t", arr[i]);
	for(i=0; i<(n-1); i++)
	{
		for(j=0; j<(n-i-1); j++)
			{
			if(arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
			}
	}
	printf("\n");
	printf("The sorted array: ");
	for(i=0; i<n; i++)
		printf("%d \t", arr[i]);
	printf("\n");
	
	int key, low = 0, high = n -1, mid;
	printf("Enter the element to search for: ");
	scanf("%d", &key);	
	while(low <= high)
	{
		mid = (low + high)/2;
		if(arr[mid] == key)
		{
			printf("Key found at index: %d\n", mid);
			return;
		}
	if(key < arr[mid])
	{
		high = mid - 1;
	}
	else
	{
		low = mid + 1;
	}
	
		} 
	if(low > high)
	{
	printf("Item not found\n");
	}	
}
