/*Q3b. WAP in c language to simulate the working of a circular queue of integers using an array. Provide the following operations: 
Insert, Delete & Display
The program should print appropriate messages for queue empty and queue overflow conditions. */

#include <stdio.h>
#define MAX 5  

int queue[MAX];
int front = -1, rear = -1;

int isFull() {
    return (front == (rear + 1) % MAX);
}

int isEmpty() {
    return (front == -1);
}

void insert(int value) {
    if (isFull()) {
        printf("Queue overflow! Cannot insert %d\n", value);
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = value;
    printf("%d inserted into the queue\n", value);
}

void delete() {
    if (isEmpty()) {
        printf("Queue is empty! Cannot delete\n");
        return;
    }
    printf("%d deleted from the queue\n", queue[front]);
    if (front == rear) {
        front = rear = -1;  
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements are: ");
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", queue[rear]);  
}

int main() {
    int choice, value;
    do {
        printf("\nCircular Queue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
