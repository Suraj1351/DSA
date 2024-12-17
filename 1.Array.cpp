#include <stdio.h> 
void insert(int arr[], int *size, int pos, int value) { 
    for (int i = (*size)++; i > pos; i--) arr[i] = arr[i - 1]; 
    arr[pos] = value; 
} 
void deletee(int arr[], int *size, int pos) { 
    for (int i = pos; i < (*size) - 1; i++) arr[i] = arr[i + 1]; 
    (*size)--; 
} 
void display(int arr[], int size) { 
    for (int i = 0; i < size; i++) printf("%d ", arr[i]); 
    printf("\n"); 
} 
int main() { 
    int arr[100] = {10, 20, 30, 40, 50}, size = 5; 
display(arr, size);                   
    insert(arr, &size, 2, 25);            
    display(arr, size);                   
    deletee(arr, &size, 3);                
    display(arr, size);                  
 return 0;  
} 

