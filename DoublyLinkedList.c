#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct DNode {
    struct DNode *prev;
    int info;
    struct DNode *next;
};

struct DNode* Start = NULL;

struct DNode* getNode(int n) {
    struct DNode* p = (struct DNode*)malloc(sizeof(struct DNode));
    if (p == NULL) {
        printf("No memory alloted.\n");
        return NULL;
    } else {
        p->info = n;
        p->prev = NULL;
        p->next = NULL;
        return p;
    }
}

void insertFront(int n) {
    struct DNode* newNode = getNode(n);
    if (!newNode) return;
    if (Start == NULL) {
        Start = newNode;
    } else {
        newNode->next = Start;
        Start->prev = newNode;
        Start = newNode;
    }
}

void insertRear(int n) {
    struct DNode* newNode = getNode(n);
    if (!newNode) return;
    if (Start == NULL) {
        Start = newNode;
    } else {
        struct DNode* temp = Start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void deleteFront() {
    if (Start == NULL) {
        printf("List is empty.\n");
    } else if (Start->next == NULL) {
        free(Start);
        Start = NULL;
    } else {
        struct DNode* temp = Start;
        Start = Start->next;
        Start->prev = NULL;
        free(temp);
    }
}

void deleteRear() {
    if (Start == NULL) {
        printf("List is empty.\n");
    } else if (Start->next == NULL) {
        free(Start);
        Start = NULL;
    } else {
        struct DNode* temp = Start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
}


void printReverse() {
    if (Start == NULL) {
        printf("List is empty.\n");
    } else {
        struct DNode* temp = Start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        while (temp != NULL) {
            printf("%d ", temp->info);
            temp = temp->prev;
        }
    }
}

void insertAtLeft(int n, int key) {
    struct DNode* newNode = getNode(n);
    if (!newNode) return;
    if (Start == NULL) {
        Start = newNode;
    } else {
        struct DNode* temp = Start;
        while (temp != NULL && temp->info != key) {
            temp = temp->next;
        }
        if (temp != NULL) {
            newNode->next = temp;
            newNode->prev = temp->prev;
            temp->prev = newNode;
            if (newNode->prev != NULL) {
                newNode->prev->next = newNode;
            } else {
                Start = newNode;
            }
        } else {
            printf("Key not found.\n");
        }
    }
}

void deleteValue(int n) {
    if (Start == NULL) {
        printf("List is empty.\n");
    } else {
        struct DNode* temp = Start;
        while (temp != NULL && temp->info != n) {
            temp = temp->next;
        }
        if (temp != NULL) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            } else {
                Start = temp->next;
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            free(temp);
        } else {
            printf("Value not found.\n");
        }
    }
}

bool checkDuplicate() {
    if (Start == NULL) {
        printf("List is empty.\n");
    } else if (Start->next == NULL) {
        return false;
    } else {
        struct DNode* temp1;
        struct DNode* temp2;
        for (temp1 = Start; temp1 != NULL; temp1 = temp1->next) {
            for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next) {
                if (temp1->info == temp2->info) {
                    return true;
                }
            }
        }
        return false;
    }
}

void displayList() {
    if (Start == NULL) {
        printf("List is empty.\n");
    } else {
        struct DNode* temp = Start;
        while (temp != NULL) {
            printf("%d ", temp->info);
            temp = temp->next;
        }
    }
}

int main() {
    int choice, data;
    do {
        printf("\n1. Insert at Front.\n"
                "2. Insert at Rear.\n"
                "3. Delete from Front.\n"
                "4. Delete from Rear.\n"
                "5. Print in Reverse.\n"
                "6. Insert at Left of a Value.\n"
                "7. Delete a Value.\n"
                "8. Check Duplicate.\n"
                "9. Display List.\n"
                "100. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertFront(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertRear(data);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                printReverse();
                break;
            case 6:
                printf("Enter data: ");
                scanf("%d", &data);
                int key;
                printf("Enter key: ");
                scanf("%d", &key);
                insertAtLeft(data, key);
                break;
            case 7:
                printf("Enter data: ");
                scanf("%d", &data);
                deleteValue(data);
                break;
            case 8:
                if (checkDuplicate()) {
                    printf("Duplicate found.\n");
                } else {
                    printf("No duplicate found.\n");
                }
                break;
            case 9:
                displayList();
                break;
            case 100:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 100);
}