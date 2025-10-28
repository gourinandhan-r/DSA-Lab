#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node * next;
	};
struct Node * top = NULL;
struct Node * createNode(int value)
{
	struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode -> data = value;
	newNode -> next = NULL;
	return newNode;
	}
void push(int value)
{
	struct Node * newNode = createNode(value);
	if(newNode == NULL)
	{
		printf("Stack overflow\n");
		return;
		}
	newNode -> next = top;
	top = newNode;
	printf("%d pushed to stack\n", value);
	}
void pop()
{
	struct Node * temp = top;
	printf("%d popped from stack\n", temp->data);
	top = top -> next;
	free(temp);
	}
void display()
{
	struct Node * temp = top;
	while(temp != NULL)
	{
		printf("%d\t", temp->data);
		temp = temp -> next;
		}
	printf("\n");
	}
void peek()
{
	printf("Top of stack is %d\n", top->data);
	}
int main()
{
	push(10);
	push(20);
	push(30);
	display();
	peek();
	pop();
	display();
	pop();
	display();
	return 0;
	}
