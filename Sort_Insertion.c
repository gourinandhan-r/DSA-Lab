#include <stdio.h>
void display(int arr[], int n)
	{
		for(int i = 0; i < n; i++)
			printf("%d\t", arr[i]);
		printf("\n");
	}
void insertionSort(int arr[], int n)
	{
		int i, temp, j;
		for(i = 1; i < n; i++)
			{
				temp = arr[i];
				j = i - 1;
				while(j >= 0 && arr[j] > temp)
				{
					arr[j+1] = arr[j];
					j --;	
				}
			arr[j+1] = temp;
			}
	}
int main()
	{
	int n;
	printf("Enter the no. of elements: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter the array elements: ");
	for(int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
	printf("Unsorted Array: ");
	display(arr, n);
	insertionSort(arr, n);
	printf("Sorted array: ");
	display(arr, n);
	return 0;
	}


