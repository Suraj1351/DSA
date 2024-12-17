#include <stdio.h> 
#include <stdlib.h> 
struct Node { 
    int key; 
    struct Node* left; 
    struct Node* right; 
};  struct Node* insert(struct Node* root, int key) { 
    if (!root) { 
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
        newNode->key = key; 
        newNode->left = newNode->right = NULL; 
        return newNode; 
    } 
    if (key < root->key) root->left = insert(root->left, key); 
    else root->right = insert(root->right, key); 
    return root; 
} 
struct Node* deleteNode(struct Node* root, int key) { 
    if (!root) return root; 
if (key < root->key) root->left = deleteNode(root->left, key); 
    else if (key > root->key) root->right = deleteNode(root->right, key); 
    else { 
        if (!root->left) { 
            struct Node* temp = root->right; 
            free(root); 
            return temp; 
        } else if (!root->right) { 
            struct Node* temp = root->left; 
            free(root); 
            return temp; 
        } 
        struct Node* temp = root->right; 
        while (temp && temp->left) temp = temp->left; 
        root->key = temp->key; 
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
} 
void inorder(struct Node* root) { 
    if (root) { 
        inorder(root->left); 
        printf("%d ", root->key); 
        inorder(root->right); 
    }    } 
int main() { 
    struct Node* root = NULL; 
    root = insert(root, 50); 
    insert(root, 30);     insert(root, 20);    insert(root, 40); 
    insert(root, 70);   insert(root, 60);    insert(root, 80); 
 printf("BST Inorder before deletion: "); 
    inorder(root); 
    printf("\n"); 
root = deleteNode(root, 20); 
    root = deleteNode(root, 30); 
 
    printf("BST Inorder after deletion: "); 
    inorder(root); 
    printf("\n"); 
 
    return 0; 
}
