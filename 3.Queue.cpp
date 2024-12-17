#include <stdio.h> 
#define MAX 100 
int queue[MAX], front = -1, rear = -1; 
void enqueue(int value) { 
    if (rear == MAX - 1) printf("Queue Overflow!\n"); 
    else { 
        if (front == -1) front = 0; 
        queue[++rear] = value; 
        printf("%d enqueued\n", value); 
    } 
}  void dequeue() { 
    if (front == -1 || front > rear) printf("Queue Underflow!\n"); 
    else printf("%d dequeued\n", queue[front++]); 
}         void search(int value) { 
    for (int i = front; i <= rear; i++) { 
        if (queue[i] == value) { 
            printf("%d found at position %d\n", value, i - front); 
            return;      }   } 
  printf("%d not found\n", value); 
}       void display() { 
    if (front == -1 || front > rear) printf("Queue is empty\n"); 
    else { 
        printf("Queue elements: "); 
        for (int i = front; i <= rear; i++) printf("%d ", queue[i]); 
        printf("\n"); 
    } 
}         int main() { 
    enqueue(10); enqueue(20); enqueue(30); display(); 
    dequeue(); display(); 
    search(20); search(40);                  return 0;          }
