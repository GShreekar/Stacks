#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* Stack;
int top = -1;

void push(char c) {
    Stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return '\0';
    }
    return Stack[top--];
}

void reverseString(char str[]) {
    int i;
    int size = strlen(str);
    Stack = (char *)malloc(size * sizeof(char));
    if (Stack == NULL) {
        printf("Memory allocation failed for stack!\n");
        return;
    }
    for (i = 0; i < size; i++) {
        push(str[i]);
    }
    for (i = 0; i < size; i++) {
        str[i] = pop();
    }
    free(Stack);
}

int main() {
    char str[20];
    printf("Enter a string: ");
    scanf("%s", str);
    reverseString(str);
    printf("Reversed string: %s\n", str);

    return 0;
}
