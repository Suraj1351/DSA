#include <stdio.h> 
#include <stdlib.h> 
#define SIZE 10  // Size of the hash table 
struct HashTable { 
    int* table; 
};   void initHashTable(struct HashTable* ht) { 
    ht->table = (int*)malloc(SIZE * sizeof(int)); 
    for (int i = 0; i < SIZE; i++) { 
        ht->table[i] = -1;  // Initialize all entries as -1 (empty) 
    } 
} 
int hash(int key) { 
    return key % SIZE; 
} 
void insert(struct HashTable* ht, int key) { 
    int index = hash(key); 
    if (ht->table[index] == -1) { 
        ht->table[index] = key;  // Insert the key if the spot is empty 
    } else { 
        printf("Collision occurred at index %d\n", index); 
    } 
} 
int search(struct HashTable* ht, int key) { 
    int index = hash(key); 
    if (ht->table[index] == key) { 
        return index; 
    } 
    return -1; 
} 
void display(struct HashTable* ht) { 
    for (int i = 0; i < SIZE; i++) { 
        printf("Index %d: %d\n", i, ht->table[i]); 
    } 
} 
int main() { 
struct HashTable ht; 
initHashTable(&ht); 
insert(&ht, 12); 
insert(&ht, 22); 
insert(&ht, 32); 
display(&ht); 
int key = 22; 
int result = search(&ht, key); 
if (result != -1) { 
printf("Key %d found at index %d\n", key, result); 
} else { 
printf("Key %d not found\n", key); 
} 
return 0; 
}
