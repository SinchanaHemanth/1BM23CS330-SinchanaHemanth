#include <stdio.h>
#include <stdlib.h>

// Define a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to sort the linked list
void sortList(struct Node** head) {
    struct Node* i, *j;
    int temp;
    for (i = *head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// Function to reverse the linked list
void reverseList(struct Node** head) {
    struct Node *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Function to concatenate two linked lists
struct Node* concatenate(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
   
    struct Node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int n1, n2, data, i;

    // Input for List 1
    printf("Enter the number of elements in List 1: ");
    scanf("%d", &n1);
    printf("Enter the elements of List 1:\n");
    for (i = 0; i < n1; i++) {
        scanf("%d", &data);
        append(&list1, data);
    }

    // Input for List 2
    printf("Enter the number of elements in List 2: ");
    scanf("%d", &n2);
    printf("Enter the elements of List 2:\n");
    for (i = 0; i < n2; i++) {
        scanf("%d", &data);
        append(&list2, data);
    }

    printf("List 1: ");
    display(list1);

    printf("List 2: ");
    display(list2);

    // Sorting List 1
    sortList(&list1);
    printf("Sorted List 1: ");
    display(list1);

    // Reversing List 1
    reverseList(&list1);
    printf("Reversed List 1: ");
    display(list1);

    // Concatenating List 1 and List 2
    struct Node* mergedList = concatenate(list1, list2);
    printf("Concatenated List: ");
    display(mergedList);

    return 0;
}
