#include <stdio.h> 
#include <stdlib.h> 
struct Node { 
    int data; 
    struct Node* next; 
}; 
void insert(struct Node** head, int value) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = value; 
    newNode->next = NULL; 
    if (*head == NULL) *head = newNode; 
    else { 
        struct Node* temp = *head; 
        while (temp->next) temp = temp->next; 
        temp->next = newNode; 
    }  }   
void deletee(struct Node** head, int value) { 
    struct Node* temp = *head, *prev = NULL; 
    if (temp && temp->data == value) { 
        *head = temp->next; 
        free(temp);    return;    } 
    while (temp && temp->data != value) { 
        prev = temp; 
        temp = temp->next; 
    } 
    if (temp) { 
        prev->next = temp->next; 
        free(temp); 
    }    } 
void display(struct Node* head) { 
    while (head) { 
        printf("%d -> ", head->data); 
        head = head->next; 
    } 
    printf("NULL\n"); 
} 
 
int main() { 
    struct Node* head = NULL; 
    insert(&head, 10); 
    insert(&head, 20); 
    insert(&head, 30); 
    display(head); 
 
    deletee(&head, 20); 
    display(head); 
 
    return 0; 
}
