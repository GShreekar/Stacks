#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

int top = -1;
char* Stack;

void push(char c) {
    Stack[++top] = c;
}

char pop() {
    return Stack[top--];
}

int precedence(char c) {
    if (c == '*' || c == '/') {
        return 3;
    } else if (c == '+' || c == '-') {
        return 2;
    } else if (c == '(') {
        return 1;
    } else {
        return 0;
    }
}

char* toPostfix(char str[]) {
    char* postfix = (char *)malloc(strlen(str) * sizeof(char) + 1);
    int len = 0;
    push('#');
    
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'z') {
            postfix[len++] = str[i];
        } else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            while (precedence(str[i]) <= precedence(Stack[top])) {
                postfix[len++] = pop();
            }
            push(str[i]);
        } else if (str[i] == '(') {
            push(str[i]);
        } else if (str[i] == ')') {
            while (Stack[top] != '(') {
                postfix[len++] = pop();
            }
            pop();
        } else {
            printf("Invalid character\n");
            exit(0);
        }
    }
    while (Stack[top] != '#') {
        postfix[len++] = pop();
    }
    
    postfix[len] = '\0';
    return postfix;
}

int main() {
    Stack = (char *)malloc(MAX * sizeof(char));
    char str[MAX];
    
    printf("Enter the infix expression: ");
    scanf("%s", str);
    
    char* postfix = toPostfix(str);
    
    printf("The postfix expression is: %s\n", postfix);
    
    free(Stack);
    free(postfix);
    
    return 0;
}
