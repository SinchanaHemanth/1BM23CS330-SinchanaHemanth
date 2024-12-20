//WAP to Implement Single Link List to simulate Stack & Queue Operations.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head, int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
}

int pop(struct Node** head) {
    if (*head == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    struct Node* temp = *head;
    int popped_value = temp->data;
    *head = (*head)->next;
    free(temp);
    return popped_value;
}

void enqueue(struct Node** head, struct Node** tail, int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;
    if (*tail != NULL) {
        (*tail)->next = new_node;
    }
    *tail = new_node;
    if (*head == NULL) {
        *head = new_node;
    }
}

int dequeue(struct Node** head, struct Node** tail) {
    if (*head == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    struct Node* temp = *head;
    int dequeued_value = temp->data;
    *head = (*head)->next;
    if (*head == NULL) {
        *tail = NULL;
    }
    free(temp);
    return dequeued_value;
}

void display(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* stack_head = NULL; 
    struct Node* queue_head = NULL;
    struct Node* queue_tail = NULL; 
    int choice, value;

    while(1) {
        printf("\nMenu:\n");
        printf("1. Push to Stack\n");
        printf("2. Pop from Stack\n");
        printf("3. Enqueue to Queue\n");
        printf("4. Dequeue from Queue\n");
        printf("5. Display Stack\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to push to Stack: ");
                scanf("%d", &value);
                push(&stack_head, value);
                break;
            case 2:
                printf("Popped value from Stack: %d\n", pop(&stack_head));
                break;
            case 3:
                printf("Enter value to enqueue to Queue: ");
                scanf("%d", &value);
                enqueue(&queue_head, &queue_tail, value);
                break;
            case 4:
                printf("Dequeued value from Queue: %d\n", dequeue(&queue_head, &queue_tail));
                break;
            case 5:
                printf("Stack: ");
                display(stack_head);
                break;
            case 6:
                printf("Queue: ");
                display(queue_head);
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
