#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
int queue[SIZE];
int front = -1;
int rear = -1;
int n; // user-defined queue size

void enqueue(int item) {
    if (rear == n - 1) {
        printf("Queue overflow\n");
    } else {
        if (front == -1 && rear == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = item;
        printf("%d inserted in queue\n", item);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        int value = queue[front];
        front++;
        printf("%d dequeued from queue\n", value);
    }
}

void atFront() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Front element is %d\n", queue[front]);
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++)
            printf("%d\t", queue[i]);
        printf("\n");
    }
}

void menu() {
    printf("\n== Queue Menu ==\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Front\n");
    printf("4. Display\n");
    printf("5. Exit\n");
}

int main() {
    int choice, item;
    printf("Enter the size of the queue [max %d]: ", SIZE);
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
                printf("Enter an element to insert: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                atFront();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again!\n");
        }
    } while (choice != 5);

    return 0;
}

