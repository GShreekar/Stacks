#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* Last = NULL;

struct Node* getNode(int info) {
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL) {
        printf("No memory allocated\n");
        return NULL;
    } else {
        p->data = info;
        p->next = NULL;
        return p;
    }
}

void insertFront(int info) {
    struct Node* newNode = getNode(info);
    if (Last == NULL) {
        newNode->next = newNode;
        Last = newNode;
    } else {
        newNode->next = Last->next;
        Last->next = newNode;
    }
    printf("Done.\n");
    displayList();
    printf("\n");
}

void insertRear(int info) {
    struct Node* newNode = getNode(info);
    if (Last == NULL)
    {
        newNode->next = newNode;
        Last = newNode;
    } else {
        newNode->next = Last->next;
        Last->next = newNode;
        Last = newNode;
    }
    printf("Done.\n");
    displayList();
    printf("\n");
}

void deleteFront() {
    if (Last == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (Last->next == Last) {
        free(Last);
        Last = NULL;
    } else {
        struct Node* temp = Last->next;
        Last->next = Last->next->next;
        free(temp);
    }
    printf("Done.\n");
    displayList();
    printf("\n");
}

void deleteRear() {
    if (Last == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (Last->next == Last) {
        free(Last);
        Last = NULL;
    } else {
        struct Node* temp = Last->next;
        while (temp->next != Last)
        {
            temp = temp->next;
        }
        temp->next = Last->next;
        free(Last);
        Last = temp;
    }
    printf("Done.\n");
    displayList();
    printf("\n");
}

void displayList() {
    if (Last == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = Last->next;
    printf("List Contents: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != Last->next);
    printf("\n");
}

struct Node* concatenateLists(struct Node* Last1, struct Node* Last2) {
    if (Last1 == NULL) return Last2;
    if (Last2 == NULL) return Last1;
    struct Node* temp;
    temp = Last1->next;
    Last1->next = Last2->next;
    Last2->next = temp;
    Last1 = Last2;
    return Last1;
}

int main() {
    int info, choice;
    do {
        printf("\n1. Display the list.\n"
            "2. Insert at the beginning.\n"
            "3. Insert at the end.\n"
            "4. Delete at front.\n"
            "5. Delete at end.\n"
            "6. Concatenate two lists.\n"
            "100. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayList();
                break;
            case 2:
                printf("\nEnter data to insert: ");
                scanf("%d", &info);
                insertFront(info);
                break;
            case 3:
                printf("\nEnter data to insert: ");
                scanf("%d", &info);
                insertRear(info);
                break;
            case 4:
                deleteFront();
                break;
            case 5:
                deleteRear();
                break;
            case 6:
                print("Enter number of elements in second list: ");
                int n;
                scanf("%d", &n);
                struct Node* Last2 = NULL;
                for (int i = 0; i < n; i++) {
                    printf("Enter element %d: ", i + 1);
                    scanf("%d", &info);
                    insertRear(info);
                }
                Last = concatenateLists(Last, Last2);
                displayList();
                break;
            case 100:
                printf("\nExiting...\n");
                break;
            default:
                printf("Invalid choice.");
                break;
        }
    } while (choice != 100);
}