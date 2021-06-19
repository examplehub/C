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
 * Search child node of binary tree.
 * @param root the root of binary tree.
 * @param parent the parent node.
 * @return the first child of parent node.
 */
ElemType searchChildNode(Node *root, ElemType parent) {
    if (root == NULL) {
        return -1;
    } else if (root->data == parent) {
        if (root->left != NULL) {
            return root->left->data;
        } else if (root->right != NULL) {
            return root->right->data;
        } else {
            return -1;
        }
    } else {
        ElemType leftChild = searchChildNode(root->left, parent);
        ElemType rightChild = searchChildNode(root->right, parent);
        if (leftChild != -1) {
            return leftChild;
        } else if (rightChild != -1) {
            return rightChild;
        } else {
            return -1;
        }
    }
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

    assert(searchChildNode(root, 1) == 2);
    assert(searchChildNode(root, 2) == 4);
    assert(searchChildNode(root, 3) == -1);
    assert(searchChildNode(root, 4) == -1);
    assert(searchChildNode(root, 5) == -1);
}

int main() {
    test();
    return 0;
}