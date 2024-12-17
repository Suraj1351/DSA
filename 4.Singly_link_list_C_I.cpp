#include <stdio.h> 
#include <stdlib.h> 
typedef struct Node { 
    int data; 
    struct Node* next; 
} Node; 
Node* createNode(int value) { 
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    newNode->data = value; 
    newNode->next = NULL; 
    return newNode; 
} 
void insert(Node** head, int value) { 
    Node* newNode = createNode(value); 
    if (*head == NULL) { 
        *head = newNode;           return; 
    } 
    Node* temp = *head; 
    while (temp->next != NULL) temp = temp->next; 
    temp->next = newNode; 
} 
void display(Node* head) { 
    while (head != NULL) { 
        printf("%d -> ", head->data); 
        head = head->next; 
    }        printf("NULL\n"); 
}        int main() { 
    Node* head = NULL; 
    insert(&head, 10); 
    insert(&head, 20); 
    insert(&head, 30); 
    printf("Linked List: "); 
    display(head);                return 0;       }
