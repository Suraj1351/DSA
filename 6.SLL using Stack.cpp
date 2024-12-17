#include <stdio.h> 
#include <stdlib.h> 
struct Node { 
    int data; 
    struct Node* next; 
}; 
void push(struct Node** top, int value) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = value; 
    newNode->next = *top; 
    *top = newNode; 
    printf("%d pushed\n", value); 
} 
void pop(struct Node** top) { 
    if (*top == NULL) { 
        printf("Stack is empty\n");       return; 
    }      struct Node* temp = *top; 
    *top = (*top)->next; 
    printf("%d popped\n", temp->data); 
    free(temp);      
} 
void display(struct Node* top) { 
    if (top == NULL) { 
        printf("Stack is empty\n");   return; 
    } 
    struct Node* temp = top; 
    while (temp) { 
        printf("%d ", temp->data); 
        temp = temp->next; 
    }     printf("\n"); 
}   int main() { 
    struct Node* top = NULL;  push(&top, 10); push(&top, 20);push(&top, 30);display(top);pop(&top);display(top); 
  return 0;}
