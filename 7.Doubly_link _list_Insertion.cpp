#include <stdio.h> 
#include <stdlib.h> 
struct Node { 
    int data; 
    struct Node* next; 
    struct Node* prev; 
}; 
void insert(struct Node** head, int value) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = value; 
    newNode->next = NULL; 
 
    if (*head == NULL) { 
        newNode->prev = NULL; 
        *head = newNode; 
        return; 
    } 
   struct Node* temp = *head; 
    while (temp->next) temp = temp->next; 
    temp->next = newNode; 
    newNode->prev = temp; 
} 
void display(struct Node* head) { 
    while (head) { 
        printf("%d <-> ", head->data); 
        head = head->next; 
    } 
    printf("NULL\n"); 
} 
int main() { 
    struct Node* head = NULL; 
   insert(&head, 10);    insert(&head, 20);      insert(&head, 30); 
    display(head);   return 0;    } 

