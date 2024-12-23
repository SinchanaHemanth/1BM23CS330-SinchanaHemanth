/*Q7. WAP to implement doubly linked list with operations 
-Create a doubly linked list
-Insert a new node to the left of the node
-Delete a node based on a specific value
-Display the contents of a list*/

#include<stdio.h>
#include<stdlib.h>
struct Node 
{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *head = NULL;
void create() 
{
    int data;
    printf("Enter data to be inserted(press -1 to exit)\n");
    scanf("%d",&data);
    while(data!=-1)
    {
        struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data=data;
        struct Node *ptr;
        if(head==NULL) 
        {
            head=newnode;
            newnode->next=NULL;
            newnode->prev=NULL;
        }
        else 
        {
            ptr = head;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            newnode->prev=ptr;
            ptr->next=newnode;
            newnode->next=NULL;
        }
        printf("Enter data to be inserted\n");
        scanf("%d",&data);
    }
}

void display()
{
    struct Node *ptr = head;
    while(ptr->next!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("%d\n",ptr->data);
}

void insertAtEnd() 
{
    int data;
    printf("Enter data that you want to insert at the end\n");
    scanf("%d",&data);
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    struct Node* ptr = head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    newnode->prev=ptr;
    ptr->next=newnode;
    newnode->next=NULL;
}

void insertAtBeginning() 
{
    int data;
    printf("Enter data to be inserted at the beginning of linked list\n");
    scanf("%d",&data);
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
}

void insertAtPosition() 
{
    int data,pos;
    printf("Enter position where you want to insert in your linked list\n");
    scanf("%d",&pos);
    printf("Enter data you want to insert at position %d\n",pos);
    scanf("%d",&data);
    struct Node *ptr,*newnode;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    ptr = head;
    if(pos==1)
    {
        insertAtBeginning();
    }
    for(int i=1;i<(pos-1);i++) 
    {
        ptr=ptr->next;
    }
    newnode->next=ptr->next;
    newnode->prev=ptr;    
    ptr->next=newnode;
    ptr->next->prev=newnode;
}

int main()
{
    int choice;
    while(1)
    {
        printf("Doubly linked list operations\n");
        printf("1. Create linked list\n");
        printf("2. Insert node at beginning\n");
        printf("3. Insert node at a particular position\n");
        printf("4. Insert node at end\n");
        printf("5. Display linked list\n");
        printf("6. Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            insertAtBeginning();
            break;
        case 3:
            insertAtPosition();
            break;
        case 4:
            insertAtEnd();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}
