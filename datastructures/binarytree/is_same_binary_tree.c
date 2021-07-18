#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int ElemType;
typedef struct Node {
    ElemType data;
    struct Node *left;
    struct Node *right;
} Node;

/**
 * Create a new node with given data.
 * @param data the data store at node.
 * @return new node.
 */
Node *createNode(int data) {
    Node *newNode = (malloc(sizeof(Node)));
    newNode->data = data;
    return newNode;
}

/**
 * Test if two binary tree is same.
 * @param root1 the first binary tree.
 * @param root2 the second binary tree.
 * @return true if two binary trees is same, otherwise false.
 */
bool isSame(Node *root1, Node *root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    if (root1 == NULL || root2 == NULL) {
        return false;
    }
    if (root1->data != root2->data) {
        return false;
    }
    return isSame(root1->left, root2->left) && isSame(root1->right, root2->right);
}


void test() {
    /* see images/example_binary_tree.png */
    Node *root = createNode(1);
    Node *node2 = createNode(2);
    Node *node3 = createNode(3);
    Node *node4 = createNode(4);
    Node *node5 = createNode(5);

    root->left = node2;
    root->right = node3;

    node2->left = node4;
    node2->right = node5;

    node3->left = node3->right = NULL;
    node4->left = node4->right = NULL;
    node5->left = node5->right = NULL;

    assert(isSame(root, root));
    assert(!isSame(root, NULL));
}

int main() {
    test();
    return 0;
}