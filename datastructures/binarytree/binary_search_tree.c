#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef int ElemType;
#define SIZE 100

int RESULT_OF_IN_ORDER[SIZE];

typedef struct Node {
    ElemType data;
    struct Node *left;
    struct Node *right;
} Node;

/**
 * Create root node binary search tree.
 * @param data the data of root node.
 * @return root node.
 */
Node *createBST(ElemType data) {
    Node *root = malloc(sizeof(Node));
    root->data = data;
    if (root == NULL) {
        return NULL;
    }
    root->left = root->right = NULL;
    return root;
}

/**
 * Insert a node to binary search tree.
 * @param root the root node of binary search tree.
 * @param key the key of node.
 * @return 1 if insert successfully, otherwise 0 returned.
 */
int insertBST(Node *root, ElemType key) {
    if (key < root->data) {
        if (root->left == NULL) {
            Node *newNode = (Node *) malloc(sizeof(Node));
            newNode->data = key;
            newNode->left = newNode->right = NULL;
            root->left = newNode;
            return 1;
        } else {
            return insertBST(root->left, key);
        }
    } else if (key > root->data) {
        if (root->right == NULL) {
            Node *newNode = (Node *) malloc(sizeof(Node));
            newNode->data = key;
            newNode->left = newNode->right = NULL;
            root->right = newNode;
            return 1;
        } else {
            return insertBST(root->right, key);
        }
    } else {
        exit(1); /* invalid data */
    }
}

/**
 * Search a key at binary search tree.
 * @param root the root of binary search tree.
 * @param key the key value to be searched.
 * @return 1 if search successfully, otherwise 0 returned.
 */
int searchBST(Node *root, int key) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == key) {
        return 1;
    } else if (key < root->data) {
        return searchBST(root->left, key);
    } else {
        return searchBST(root->right, key);
    }
}

int count = 0;

void inOrder(Node *root) {
    if (root != NULL) {
        inOrder(root->left);
        RESULT_OF_IN_ORDER[count] = root->data;
        count++;
        inOrder(root->right);
    }
}

void test() {
    int nums[SIZE];
    for (int i = 0; i <= SIZE / 2; ++i) {
        *(nums + i) = i;
    }
    for (int i = SIZE / 2 + 1; i < SIZE; ++i) {
        *(nums + i) = -i;
    }

    Node *root = createBST(nums[0]);
    for (int i = 1; i < SIZE; ++i) {
        assert(insertBST(root, nums[i]) == 1);
    }

    inOrder(root);
    for (int i = 0; i < SIZE - 1; ++i) {
        assert(RESULT_OF_IN_ORDER[i] < RESULT_OF_IN_ORDER[i + 1]);
    }

    for (int i = 0; i < SIZE; ++i) {
        assert(searchBST(root, nums[i]) == 1);
    }
    assert(searchBST(root, 666) == 0);
}

int main() {
    test();
    return 0;
}

