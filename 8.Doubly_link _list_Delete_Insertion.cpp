#include <stdio.h> 
#include <stdlib.h> 
struct Node { 
    int data; 
    struct Node* next;     struct Node* prev; 
};     void insert(struct Node** head, int value) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = value; 
    newNode->next = NULL; 
    if (*head == NULL) { 
        newNode->prev = NULL; 
        *head = newNode; 
    } else { 
        struct Node* temp = *head; 
        while (temp->next) temp = temp->next; 
        temp->next = newNode; 
        newNode->prev = temp; 
    }    } 
void deletee(struct Node** head) { 
    if (*head == NULL) return; 
    struct Node* temp = *head; 
    *head = temp->next; 
    if (*head) (*head)->prev = NULL; 
    free(temp); 
} 
void display(struct Node* head) { 
    while (head) { 
        printf("%d ", head->data); 
        head = head->next; 
    }     printf("\n");    } 
int main() {   struct Node* head = NULL; 
 insert(&head, 10);   insert(&head, 20);    insert(&head, 30);     display(head);   deletee(&head); 
    display(head);    return 0;   }
