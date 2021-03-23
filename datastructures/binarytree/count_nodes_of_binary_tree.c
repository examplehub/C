#include <stdio.h>
#include <stdlib.h>
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
 * Return the count of nodes of binary tree.
 * @param root the root node of binary tree.
 * @return the count of nodes of binary tree.
 */
int countNodes(Node *root) {
    return root == NULL ? 0 : 1 + countNodes(root->left) + countNodes(root->right);
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

    assert(countNodes(root) == 5);
}

int main() {
    test();
    return 0;
}