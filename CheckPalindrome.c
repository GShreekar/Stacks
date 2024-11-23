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

bool checkPalindrome(char str[]) {
    int i;
    int size = strlen(str);
    bool isPalindrome = true;
    Stack = (char *)malloc(size * sizeof(char));
    if (Stack == NULL) {
        printf("Memory allocation failed for stack!\n");
        return false;
    }

    int mid = size / 2;
    for (i = 0; i < mid; i++) {
        push(str[i]);
    }
    if (size % 2 != 0) {
        mid++;
    }

    for (i = mid; i < size; i++) {
        if (str[i] != pop()) {
            free(Stack);
            return false;
        }
    }

    free(Stack);
    return true;
}

int main() {
    char str[20];
    printf("Enter a string: ");
    scanf("%s", str);
    if (checkPalindrome(str)) {
        printf("The string is a palindrome!\n");
    } else {
        printf("The string is not a palindrome!\n");
    }

    return 0;
}
