#include <stdio.h>
#include <stdlib.h>
#define size 100
int stack[size];
int top = -1;
void push(int item)
	{
			if(top == size-1)
			{
				printf("Stack overflow\n");
				}
			else
			{	
				top++;
				stack[top] = item;
				printf("%d pushed onto stack\n", item);
				}
		}
void pop()
	{
		if(top == -1)
		{
			printf("Stack underflow\n");
			}
		else
		{
			int value = stack[top];
			top --;
			printf("%d popped from stack\n", value);
			}
		}
void peek()
	{
		if(top == -1)
		{
			printf("Stack underflow\n");
			}
		else
		{
			printf("Top element is %d\n", stack[top]);
			}
		}
void display()
	{
		if(top == -1)
		{
			printf("Stack underflow\n");
			}
		else{
				printf("Stack: ");
				for(int i = top; i >= 0; i--)
					printf("%d\t", stack[i]);
				printf("\n");
			}
		}
void menu()
	{
		printf("==Stack Menu==\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Peek\n");
		printf("4. Display\n");
		printf("5. Exit\n");
		}
int main()
{
	int choice, n, item;
	printf("Enter the size of the stack[100]: ");
	scanf("%d",&n);
	menu();
	do
	{
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter an element to push: ");
				scanf("%d",&item);
				push(item);
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
			case 5:
				exit(0);
			default:
				printf("Inavlid choice! Try again!\n");
			}
		}while(choice != 5);
	return 0;
	}
