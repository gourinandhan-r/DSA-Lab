#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node * next;
	struct Node * prev;
	};
struct Node * createNode(int value)
{
	struct Node * newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode -> data = value;
	newNode -> next = NULL;
	newNode -> prev = NULL;
	return newNode;
	}
struct Node * head = NULL;
void insertAtBeginning(int value)
{
	struct Node * newNode = createNode(value);
	if(head == NULL)
	{
		head = newNode;
		}
	else
	{
		newNode -> next = head;
		head -> prev = newNode;
		head = newNode;
		}
	printf("%d inserted at beginning\n", value);
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
		newNode -> prev = temp;
		}
	printf("%d inserted at end\n", value);
	}
void deleteFromBeginning()
{
	if(head == NULL)
	{
		printf("List is empty\n");
		return;
		}
	struct Node *temp = head;
    head = head->next;
    if(head != NULL)
        head->prev = NULL;
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
    struct Node *temp = head;
    if(temp->next == NULL) 
    {
        printf("%d deleted from end\n", temp->data);
        free(temp);
        head = NULL;
        return;
		}
    while(temp->next != NULL)
        temp = temp->next;
    printf("%d deleted from end\n", temp->data);
    temp->prev->next = NULL;
    free(temp);
	}
void display()
{
	if(head == NULL) 
	{
        printf("List is empty\n");
        return;
		}
    struct Node *temp = head;
    printf("List (forward): ");
    while(temp != NULL) 
    {
        printf("%d\t", temp->data);
        temp = temp->next;
		}
    printf("\n");
	}
void displayBackward() 
{
    if(head == NULL) 
    {
        printf("List is empty\n");
        return;
		}
    struct Node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    printf("List (backward): ");
    while(temp != NULL) 
    {
        printf("%d\t", temp->data);
        temp = temp->prev;
		}
    printf("\n");
	}
int main()
{
	insertAtBeginning(50);
	insertAtBeginning(25);
	display();
	insertAtEnd(75);
	insertAtEnd(100);
	display();
	displayBackward();
	deleteFromBeginning();
	display();
	deleteFromEnd();
	display();
	return 0;
	}
