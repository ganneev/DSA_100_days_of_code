#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// insert into BST
struct Node* insert(struct Node* root, int data) {
    if(root == NULL)
        return createNode(data);

    if(data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

// find LCA in BST
struct Node* LCA(struct Node* root, int n1, int n2) {
    if(root == NULL)
        return NULL;

    // both nodes in left subtree
    if(n1 < root->data && n2 < root->data)
        return LCA(root->left, n1, n2);

    // both nodes in right subtree
    if(n1 > root->data && n2 > root->data)
        return LCA(root->right, n1, n2);

    // split point → this is LCA
    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* root = NULL;

    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    int n1, n2;
    scanf("%d %d", &n1, &n2);

    struct Node* lca = LCA(root, n1, n2);

    if(lca)
        printf("%d", lca->data);

    return 0;
}