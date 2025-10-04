#include <stdio.h>
int size;
int queue[100];
int front = -1, rear = -1;
int isFull()
{
	return rear == size -1;
}
int isEmpty()
{
return front == -1 || front > rear;
}
void enqueue(int value)
{
if(isFull())
	{
		printf("Queue Overflow\n");
		return;
	}
if(front == -1) front=0;
	{
		rear++;
		queue[rear] = value;
		printf("Enqueued %d\n", value);
	}
}
int dequeue()
{
if(isEmpty())
	{
		printf("Queue Underflow\n");
		return -1;
	}
	int value = queue[front];
	front++;
	printf("Dequeued %d\n", value);
	return value;
}
void display()
{
if(isEmpty())
	{
		printf("Queue Underflow\n");
		return;
	}
	printf("Queue Elements: ");
	for(int i = front; i <= rear; i++)
		printf("%d ", queue[i]);
	printf("\n");
}
int main()
{
printf("Enter the size of queue (max 100): ");
scanf("%d", &size);    
if(size <= 0 || size > 100) 
{
	printf("Invalid size! Using default size 10\n");
        size = 10;
}
int choice, value;
while(1)
{
	printf("--- Queue Menu ---\n");
	printf("1. Enqueue\n");
	printf("2. Dequeue\n");
	printf("3. Display\n");
	printf("4. Exit\n");
	printf("Enter a choice: ");
	scanf("%d", &choice);
	switch(choice){
	case 1: 
		printf("Enter a value to enqueue: ");
		scanf("%d", &value);
		enqueue(value);
		break;
	case 2: 
		dequeue();
		break;
	case 3:
		display();
		break;
	case 4:
		printf("Exiting...\n");
		return 0;
	default: 
		printf("Invalid choice!\n");
	}
}

}

