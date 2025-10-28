#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
int queue[SIZE];
int front = -1, rear = -1;
int n;
int isFull() {
    return ((front == 0 && rear == n - 1) || (rear + 1) % n == front);
}
int isEmpty() {
    return (front == -1);
}
void enqueue(int item) {
    if (isFull()) {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % n;
    }
    queue[rear] = item;
    printf("%d inserted into queue\n", item);
}
void dequeue() {
    if (isEmpty()) {
        printf("Queue underflow\n");
        return;
    }
    int value = queue[front];
    printf("%d deleted from queue\n", value);
    if (front == rear) {
        front = rear = -1; 
    } else {
        front = (front + 1) % n;
    }
}
void getFront() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}
void getRear() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Rear element: %d\n", queue[rear]);
    }
}
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d\t", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % n;
    }
    printf("\n");
}
void menu() {
    printf("\n== Circular Queue Menu ==\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Front Element\n");
    printf("4. Rear Element\n");
    printf("5. Display\n");
    printf("6. Exit\n");
}
int main() {
    int choice, item;
    printf("Enter the size of the circular queue (max %d): ", SIZE);
    scanf("%d", &n);
    if (n <= 0 || n > SIZE) {
        printf("Invalid size!\n");
        return 0;
    }
    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                getFront();
                break;
            case 4:
                getRear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);
    return 0;
}
