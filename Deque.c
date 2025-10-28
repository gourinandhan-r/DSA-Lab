#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
int deque[SIZE];
int front = -1, rear = -1;
int n; 
int isFull() 
{
    return ((front == 0 && rear == n - 1) || (front == rear + 1));
  }
int isEmpty() 
{
    return (front == -1);
  }
void insertFront(int item) 
{
    if (isFull()) 
    {
        printf("Deque overflow\n");
        return;
      }
    if (front == -1) 
    {
        front = rear = 0;
      } 
    else if (front == 0) 
    {
        front = n - 1;
      } 
    else 
    {
        front--;
      }
    deque[front] = item;
    printf("%d inserted at front\n", item);
  }
void insertRear(int item) 
{
    if (isFull()) 
    {
        printf("Deque overflow\n");
        return;
      }
    if (front == -1) 
    {
        front = rear = 0;
      } 
    else if (rear == n - 1) 
    {
        rear = 0;
      } 
    else 
    {
        rear++;
      }
    deque[rear] = item;
    printf("%d inserted at rear\n", item);
  }
void deleteFront() 
{
    if (isEmpty()) 
    {
        printf("Deque underflow\n");
        return;
      }
    int item = deque[front];
    printf("%d deleted from front\n", item);
    if (front == rear) 
    {
        front = rear = -1;
      } 
    else if (front == n - 1) 
    {
        front = 0;
      } 
    else 
    {
        front++;
      }
  }
void deleteRear() 
{
    if (isEmpty()) 
    {
        printf("Deque underflow\n");
        return;
      }
    int item = deque[rear];
    printf("%d deleted from rear\n", item);
    if (front == rear) 
    {
        front = rear = -1;
      } 
    else if (rear == 0) 
    {
        rear = n - 1;
      } 
    else 
    {
        rear--;
      }
  }
void display() 
{
    if (isEmpty()) 
    {
        printf("Deque is empty\n");
        return;
      }
    printf("Deque elements: ");
    int i = front;
    while (1) 
    {
        printf("%d\t", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % n;
      }
    printf("\n");
  }
void getFront() 
{
    if (isEmpty())
        printf("Deque is empty\n");
    else
        printf("Front element: %d\n", deque[front]);
  }
void getRear() 
{
    if (isEmpty())
        printf("Deque is empty\n");
    else
        printf("Rear element: %d\n", deque[rear]);
  }
void menu() 
{
    printf("\n== Doubly Ended Queue Menu ==\n");
    printf("1. Insert at Front\n");
    printf("2. Insert at Rear\n");
    printf("3. Delete from Front\n");
    printf("4. Delete from Rear\n");
    printf("5. Display\n");
    printf("6. Get Front\n");
    printf("7. Get Rear\n");
    printf("8. Exit\n");
  }
int main() 
{
    int choice, item;

    printf("Enter the size of the deque (max %d): ", SIZE);
    scanf("%d", &n);
    if (n <= 0 || n > SIZE) 
    {
        printf("Invalid size!\n");
        return 0;
      }
    do 
    {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &item);
                insertFront(item);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &item);
                insertRear(item);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                getFront();
                break;
            case 7:
                getRear();
                break;
            case 8:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
          }
      } while (choice != 8);
    return 0;
  }
