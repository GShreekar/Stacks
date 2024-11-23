#include <stdio.h>
#include <stdlib.h>

int size;
int* Stack;
int top = -1;

void push(int value) {
    if (top == size - 1) {
        printf("\nStack overflow!\n");
    } else {
        Stack[++top] = value;
        printf("Pushed %d onto stack\n", value);
    }
}

int pop() {
    if (top == -1) {
        printf("\nStack underflow!\n");
        return -1000;
    }
    return Stack[top--];
}

int peek() {
    if (top == -1) {
        printf("Stack is empty. No element to peek.\n");
        return -1;
    }
    return Stack[top];
}

void display() {
    if (top == -1) {
        printf("\nStack is empty.\n");
        return;
    }
    printf("\nStack elements:\n");
    for (int i = 0; i <= top; i++) {
        printf("%d\n", Stack[i]);
    }
    printf("\n");
}

int main() {
    printf("Enter the size of the stack: ");
    scanf("%d", &size);
    if (size <= 0) {
        printf("Invalid size. Exiting program.\n");
        return 1;
    }

    Stack = (int *)malloc(size * sizeof(int));
    if (Stack == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        return 1;
    }

    int choice, value;

    do {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("100. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter value to push: ");
                if (scanf("%d", &value) != 1) {
                    printf("\nInvalid input! Please enter an integer.\n");
                    while (getchar() != '\n');
                } else {
                    push(value);
                }
                break;
            case 2:
                value = pop();
                if (value != -1000) {
                    printf("\nPopped element: %d\n", value);
                }
                break;
            case 3:
                value = peek();
                if (value != -1) {
                    printf("\nPeek top element: %d\n", value);
                }
                break;
            case 4:
                display();
                break;
            case 100:
                free(Stack);
                printf("\nExiting program.\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 100);

    return 0;
}
