#include <stdio.h>
#include <stdlib.h>
struct Node
	{
		int data;
		struct Node * next;
		};
struct Node * front = NULL;
struct Node * rear = NULL;
struct Node * createNode(int value)
	{
		struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
		newNode -> data = value;
		newNode -> next = NULL;
		return newNode;
	}
void enqueue(int value)
	{
		struct Node * newNode = createNode(value);
		if(rear == NULL) //empty queue
		{
		front = rear = newNode;
		//return;	
		}
		rear->next = newNode;
		rear = newNode;
		printf("%d equeued to queue\n", value);
	}
void dequeue()
	{
		if(front == NULL)
		{
		printf("Queue is empty\n");
		return;	
		}
		struct Node * temp = front;
		printf("Dequeued %d\n", temp->data);
		front = front -> next;
		if(front == NULL) //if queue becomes empty
			rear = NULL;
		free(temp);
	}
void peek()
	{
	if(front == NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	struct Node * temp = front;
	printf("Front is %d\n", temp -> data);
	}
void display()
	{
		if(front == NULL)
		{
		printf("Queue is empty\n");
		return;	
		}
		struct Node * temp = front;
		while(temp != NULL)
		{
			printf("%d\t", temp-> data);
			temp = temp -> next;
		}
		printf("\n");
	}
int main()
	{
		enqueue(25);
		enqueue(50);
		enqueue(75);
		peek();
		enqueue(100);
		display();
		dequeue();
		dequeue();
		display();
		return 0;
		}
