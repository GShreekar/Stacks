#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isFull() {
    return rear == MAX - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue Overflow.\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = data;
    printf("Element %d inserted into the queue.\n", data);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow.\n");
        return;
    }
    printf("Element %d deleted from the queue.\n", queue[front++]);
    if (front > rear)
        front = rear = -1;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty! Nothing to display.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    
    do {
        printf("\nQueue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        int data;
        
        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
