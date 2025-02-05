#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* next;
};

struct Node* Start = NULL;

void insertNode(int info, int position);
void displayList();
void deleteNode(int position);
int countNodes();
void sortList();
void insert_into_sorted(int info);
void getList();
struct Node* getNode(int n);
void mergeLists();
void reverseList();

int main() {
    int choice, info, position;
    struct Node* Start2 = NULL;

    do {
        printf("\n1. Get List from User\n");
        printf("2. Insert Node\n");
        printf("3. Display List\n");
        printf("4. Delete Node\n");
        printf("5. Count Nodes\n");
        printf("6. Sort List\n");
        printf("7. Insert into Sorted List\n");
        printf("8. Merge with Another List\n");
        printf("9. Reverse the List\n");
        printf("100. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                getList();
                break;
            case 2:
                printf("Enter info to insert: ");
                scanf("%d", &info);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertNode(info, position);
                break;
            case 3:
                printf("Current List: ");
                displayList();
                break;
            case 4:
                printf("Enter position to delete from: ");
                scanf("%d", &position);
                deleteNode(position);
                printf("Node deleted from position %d.\n", position);
                break;
            case 5:
                printf("Count of nodes: %d\n", countNodes());
                break;
            case 6:
                sortList();
                printf("List sorted.\n");
                break;
            case 7:
                printf("Enter info to insert into sorted list: ");
                scanf("%d", &info);
                insert_into_sorted(info);
                break;
            case 8:
                mergeLists();
                break;
            case 9:
                reverseList();
                printf("List reversed.\n");
                break;
            case 100:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 100);

    while (Start != NULL) {
        struct Node* temp = Start;
        Start = Start->next;
        free(temp);
    }

    return 0;
}

void getList() {
    int n, info;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter info for node %d: ", i + 1);
        scanf("%d", &info);
        insertNode(info, i);
    }
}

struct Node* getNode(int n) {
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL) {
        printf("No memory allocated\n");
        return NULL;
    } else {
        p->info = n;
        p->next = NULL;
        return p;
    }
}

void insertNode(int info, int position) {
    struct Node* newNode = getNode(info);
    if (!newNode) {
        return;
    }

    if (position == 0) {
        newNode->next = Start;
        Start = newNode;
        return;
    }

    struct Node* current = Start;
    for (int i = 0; current != NULL && i < position - 1; i++) {
        current = current->next;
    }

    if (current == NULL) {
        free(newNode);
        printf("Position out of bounds.\n");
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void displayList() {
    struct Node* current = Start;
    while (current != NULL) {
        printf("%d -> ", current->info);
        current = current->next;
    }
    printf("NULL\n");
}

void deleteNode(int position) {
    if (Start == NULL) return;
    struct Node* temp = Start;
    if (position == 0) {
        Start = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) return;
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

int countNodes() {
    int count = 0;
    struct Node* current = Start;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void sortList() {
    if (Start == NULL) return;
    struct Node *current, *nextNode;
    int temp;
    for (current = Start; current != NULL; current = current->next) {
        for (nextNode = current->next; nextNode != NULL; nextNode = nextNode->next) {
            if (current->info > nextNode->info) {
                temp = current->info;
                current->info = nextNode->info;
                nextNode->info = temp;
            }
        }
    }
}

void insert_into_sorted(int info) {
    struct Node* newNode = getNode(info);
    if (!newNode) {
        return;
    }

    if (Start == NULL || Start->info >= newNode->info) {
        newNode->next = Start;
        Start = newNode;
        return;
    }
    struct Node* current = Start;
    while (current->next != NULL && current->next->info < newNode->info) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void mergeLists() {
    struct Node* newList = NULL;
    printf("Getting new list from user...\n");
    getList();

    if (Start == NULL) {
        Start = newList;
    } else {
        struct Node* current = Start;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newList;
    }

    sortList();
    printf("Combined and sorted list: ");
    displayList();
}


void reverseList() {
    struct Node *previous = NULL, *current = Start, *nextNode;
    while (current != NULL) {
        nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }
    Start = previous;
}
