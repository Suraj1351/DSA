#include <stdio.h>
#define MAX 100

int stack[MAX], top = -1;

void push(int val) {
    if (top == MAX - 1)
        printf("Stack Overflow!\n");
    else
        stack[++top] = val, printf("%d pushed\n", val);
}

void pop() {
    if (top == -1)
        printf("Stack Underflow!\n");
    else
        printf("%d popped\n", stack[top--]);
}

void search(int val) {
    int i; // Declare 'i' outside the loop
    for (i = top; i >= 0; i--) {
        if (stack[i] == val) {
            printf("%d found at %d\n", val, i);
            return;
        }
    }
    printf("%d not found\n", val);
}

void display() {
    if (top == -1)
        printf("Stack Empty\n");
    else {
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    search(20);
    search(40);
    return 0;
}

