#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

bool checkBrackets(char str[]) {
    bool isValid = false;
    int size = strlen(str);
    Stack = (char *)malloc(size * sizeof(char));
    if (Stack == NULL) {
        printf("Memory allocation failed for stack!\n");
        return false;
    }
    for (int i = 0; i < size; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            push(str[i]);
        } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (top == -1) {
                free(Stack);
                return false;
            }
            char c = pop();
            if ((str[i] == ')' && c != '(') || (str[i] == ']' && c != '[') || (str[i] == '}' && c != '{')) {
                free(Stack);
                return false;
            }
        }
    }
    if (top != -1) {
        free(Stack);
        return false;
    }
    free(Stack);
    return true;
}

int main() {
    char str[20];
    printf("Enter a string: ");
    scanf("%s", str);
    if (checkBrackets(str)) {
        printf("The brackets are balanced!\n");
    } else {
        printf("The brackets are not balanced!\n");
    }
    return 0;
}
