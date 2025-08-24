#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    float m;
    struct node* link;
};

// Function to search an element based on 'm'
void searching(struct node* head) {
    struct node* LOC = NULL;
    struct node* temp = head;
    float x;  // Searching for a float value

    printf("Enter the element which you want to find in the 'm' part: ");
    scanf("%f", &x);

    while (temp != NULL) {
        if (temp->m == x) {
            LOC = temp;
            printf("Element found: Info = %d, m = %.2f\n", LOC->info, LOC->m);
            break;
        } else {
            temp = temp->link;
        }
    }

    if (LOC == NULL)
        printf("Not found!\n");
}

// Function to insert a node at the head
void InsertAtHead(struct node** head) {
    struct node* NEW = (struct node*) malloc(sizeof(struct node));

    printf("Enter the element to insert in the 'info' part: ");
    scanf("%d", &NEW->info);
    printf("Enter the value for 'm': ");
    scanf("%f", &NEW->m);

    NEW->link = *head;
    *head = NEW;  // Update head to point to the new node
}

// Function to insert a node at the tail
void InsertAtTail(struct node* head) {
    struct node* newp = (struct node*) malloc(sizeof(struct node));
    struct node* temp = head;
    
    printf("Enter the element to insert in the 'info' part: ");
    scanf("%d", &newp->info);
    printf("Enter the value for 'm': ");
    scanf("%f", &newp->m);

    while (temp->link != NULL) {
        temp = temp->link;  // Move to the last node
    }
    temp->link = newp;  // Link the last node to the new node
    newp->link = NULL;  // Set the new node's link to NULL (last node)
}

// Function to insert a node at a specific index
void InsertAtIdx(struct node* head) {
    struct node* newp = (struct node*) malloc(sizeof(struct node));
    struct node* temp = head;
    int idx;

    printf("Enter the index where you want to insert: ");
    scanf("%d", &idx);

    printf("Enter the element to insert in the 'info' part: ");
    scanf("%d", &newp->info);
    printf("Enter the value for 'm': ");
    scanf("%f", &newp->m);

    int i = 1;
    while (i < idx && temp != NULL) {
        temp = temp->link;
        i++;
    }

    if (temp == NULL) {
        printf("Index out of range!\n");
        free(newp);
        return;
    }

    newp->link = temp->link;
    temp->link = newp;
}

// Function to delete a node at the head
void DeleteAtHead(struct node** head) { 
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node* temp = *head;
    *head = (*head)->link;  // Move head to the next node
    free(temp);  // Free the old head node
}

// Function to delete a node at a specific index
void DeleteAtIdx(struct node* head) {
    int idx;
    printf("Enter the index where you want to delete: ");
    scanf("%d", &idx);

    struct node* temp = head;
    int i = 1;
    while (i < idx - 1 && temp != NULL) {
        temp = temp->link;
        i++;
    }

    if (temp == NULL || temp->link == NULL) {
        printf("Index out of range!\n");
        return;
    }

    struct node* toDelete = temp->link;
    temp->link = temp->link->link;  // Skip the node to be deleted
    free(toDelete);  // Free the deleted node
}

// Function to delete the last node
void deleteAtTail(struct node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node* temp = head;
    while (temp->link != NULL && temp->link->link != NULL) {
        temp = temp->link;  // Traverse to the second-to-last node
    }

    free(temp->link);  // Free the last node
    temp->link = NULL;  // Set the second-to-last node's link to NULL
}

// Function to display the list
void display(struct node* head) {  
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d",temp->info);
        temp = temp->link;
    }
    printf("\n");
}

// Function to handle insertion options
void insertion(struct node** head) {
    int option;
    printf("Enter the operation: \n");
    printf("1. Insert At Head\n");
    printf("2. Insert At Tail\n");
    printf("3. Insert At Index\n");
    scanf("%d", &option);

    switch (option) {
        case 1: InsertAtHead(head); break;
        case 2: InsertAtTail(*head); break;
        case 3: InsertAtIdx(*head); break;
        default: printf("Invalid operation!\n");
    }
}

// Function to handle deletion options
void deletion(struct node** head) {
    int option;
    printf("Enter the deletion operation: \n");
    printf("1. Delete At Head\n");
    printf("2. Delete At Tail\n");
    printf("3. Delete At Index\n");
    scanf("%d", &option);

    switch (option) {
        case 1: DeleteAtHead(head); break;
        case 2: deleteAtTail(*head); break;
        case 3: DeleteAtIdx(*head); break;
        default: printf("Invalid operation!\n");
    }
}

int main() {
    struct node* head = NULL;  // Initialize head as NULL

    int operation;

    printf("Enter the operation: 1. Search, 2. Insertion, 3. Deletion\n");
    scanf("%d", &operation);

    switch (operation) {
        case 1: searching(head); break;
        case 2: insertion(&head); break;
        case 3: deletion(&head); break;
        default: printf("Invalid operation!\n");
    }

    display(head);

    return 0;
}
