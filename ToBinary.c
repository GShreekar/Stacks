#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

int* Stack;
int top = -1;

void push(int value) {
    if (top == SIZE - 1) {
        printf("\nStack overflow!\n");
        return;
    }
    Stack[++top] = value;
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

void toBinary(int num) {
    while (num > 0) {
        push(num % 2);
        num /= 2;
    }
    for (int i = top; i >= 0; i--) {
        printf("%d", pop());
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    Stack = (int *)malloc(SIZE * sizeof(int));
    if (Stack == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        return 1;
    }
    toBinary(num);
    return 0;
}