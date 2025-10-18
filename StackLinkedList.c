#include <stdio.h>
#include <stdlib.h>
struct Node
	{
		int data;
		struct Node * next;
		};
struct Node * top = NULL;
void push(int value)
	{
		struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
		if(newNode == NULL)
		{
		printf("Stack overflow\n");
		return;	
		}
		newNode -> data = value;
		newNode -> next = top;
		top = newNode;
		printf("Pushed onto stack %d\n", value);
	}
void pop()
	{
		if(top == NULL)
		{
		printf("Stack underflow\n");
		return;
		}
		struct Node * temp = top;
		printf("Popped from stack %d\n", top->data);
		top = top -> next;
		free(temp);
	}
void peek()
	{
			if(top == NULL)
			{
			printf("Stack underflow\n");
			return;	
			}
			else
				printf("Top of stack is %d", top->data);
	}
void display()
	{
			if(top == NULL)
			{
			printf("Stack underflow\n");
			return;	
			}
			struct Node * temp = top;
			while(temp != NULL)
			{
				printf("%d\t", temp -> data);
				temp = temp -> next;
			}
			printf("\n");
	}
int main()
	{
		push(25);
		push(50);
		push(75);
		display();
		pop();
		pop();
		peek();
		return 0;
	}
