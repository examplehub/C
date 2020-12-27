#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Node {
    ElemType data;
    struct Node *left;
    struct Node *right;
} Node;

void preOrder(Node *root) {
    if (root != NULL) {
        printf("%d", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node *root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d", root->data);
    }
}

void inOrder(Node *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d", root->data);
        inOrder(root->right);
    }
}

void test() {
    /* see images/example_binary_tree.png */
    Node *root = malloc(sizeof(Node));
    root->data = 1;

    Node *node2 = malloc(sizeof(Node));
    node2->data = 2;

    Node *node3 = malloc(sizeof(Node));
    node3->data = 3;

    Node *node4 = malloc(sizeof(Node));
    node4->data = 4;

    Node *node5 = malloc(sizeof(Node));
    node5->data = 5;

    root->left = node2;
    root->right = node3;

    node2->left = node4;
    node2->right = node5;

    node3->left = node3->right = NULL;
    node4->left = node4->right = NULL;
    node5->left = node5->right = NULL;

    preOrder(root); /* output: 12453 */
    printf("\n");

    inOrder(root); /* output: 42513 */
    printf("\n");

    postOrder(root); /* output:  45231 */
    printf("\n");
}

int main() {
    test();
    return 0;
}