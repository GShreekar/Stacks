#include <stdio.h>
#include <stdlib.h>

#define MAX 100

float stack[MAX];
int top = -1;

void push(float val) {
    if (top == MAX - 1) {
        printf("Stack is full\n");
        return;
    }
    stack[++top] = val;
}

float pop() {
    if (top == -1) {
        printf("Invalid expression\n");
        return -1;
    }
    return stack[top--];
}

int isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
        return 1;
    }
    return 0;
}

float evalPostfix(char *postfix) {
    char ch;
    float op1, op2, result;
    for (int i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];
        if (isOperator(ch) && top >= 1) {
            op2 = pop();
            op1 = pop();
            switch (ch) {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
            }
            push(result);
        } else {
            push(ch - '0');
        }
    }

    if (top == 0) {
        return pop();
    } else {
        printf("Invalid expression\n");
        exit(1);
    }
}

int main() {
    char postfix[MAX];
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);
    printf("Result: %.2f\n", evalPostfix(postfix));
    return 0;
}