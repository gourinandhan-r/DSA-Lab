#include <stdio.h>
#include <stdlib.h>
struct Node{
	int data;
	struct Node * next;
	};
struct Node * head = NULL;
struct Node * createNode(int value)
	{
		struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
		newNode -> data = value;
		newNode -> next = NULL;
		return newNode;
	}
void insertAtBeginning(int value)
	{
			struct Node * newNode = createNode(value);
			newNode -> next = head;
			head = newNode;
			printf("%d inserted at front\n", value);
	}
void insertAtEnd(int value)
	{
			struct Node * newNode = createNode(value);
			if(head == NULL)
				head = newNode;
			else
			{
					struct Node * temp = head;
					while(temp -> next != NULL)
						temp = temp -> next;
					temp -> next = newNode;
			}
			printf("%d inserted at end\n", value);
	}
void insertAfterKey(int value, int key)
	{
			struct Node * temp = head;
			while(temp != NULL && temp->data != key)
				temp = temp -> next;
			if(temp == NULL)
			{
				printf("Key not found\n");
				return;
			}
			struct Node * newNode = createNode(value);
			newNode -> next = temp -> next; 
			temp -> next = newNode; 
			printf("Added %d after key %d\n", value, key);	
	}
void deleteFromBeginning()
	{
			if(head == NULL)
			{
				printf("List is empty\n");
				return;
			}
			struct Node *  temp = head; //temp is assigned the value of head
			head = head -> next; //next node is made the head node
			printf("%d deleted from beginning\n", temp->data);
			free(temp);
	}
void deleteFromEnd()
	{
			if(head == NULL)
			{
				printf("List is empty\n");
				return;	
			}
			if(head -> next == NULL)
			{
				printf("%d deleted from end\n", head->data);
				free(head);
				head = NULL;
				return;
			}
			struct Node * temp = head;
			struct Node * prev = NULL;
			while(temp -> next != NULL)
			{
				prev = temp;
				temp = temp->next;
			}
			printf("%d deleted from end\n", temp->data);
			free(temp);
			prev->next = NULL;
	}
void deleteAfterKey(int value, int key)
	{
		if(head == NULL)
			{
				printf("List is empty\n");
				return;	
			}	
	}
void display()
	{
		if(head == NULL)
		{
				printf("List is empty\n");
				return;
		}
		struct Node * temp = head;
		while(temp != NULL)
		{
			printf("%d\t", temp->data);
			temp = temp -> next;
		}
	}
int main()
	{
		//insertAtBeginning(25);
		//insertAtEnd(50);
		//insertAtEnd(75);
		//insertAfterKey(100, 50);
		//insertAtEnd(100);
		//insertAtBeginning(0);
		//deleteFromBeginning();
		//deleteFromEnd();
		display();
		}

