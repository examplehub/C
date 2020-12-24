#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef char ElemType;
typedef struct CTNode {
    int child;
    struct CTNode *next;
} CTNode;

typedef struct CTBox {
    ElemType data;
    CTNode *firstChild;
} CTBox;

typedef struct CTree {
    CTBox nodes[MAX_SIZE];
    int root; /* the root node index */
    int size; /* the number of nodes in list */
} CTree;

void initTree(CTree *pTree, int size) {
    pTree->size = size;
    pTree->root = 0;
    for (int i = 0; i < size; ++i) {
        getchar();
        printf("Input %dst node value:", i + 1);
        scanf("%c", &pTree->nodes[i].data);

        printf("Input the number of child nodes: ");
        int numberOfChild;
        scanf("%d", &numberOfChild);

        CTNode *tail = pTree->nodes[i].firstChild = NULL;
        for (int j = 1; j <= numberOfChild; ++j) {
            CTNode *childNode = malloc(sizeof(CTNode));
            childNode->next = NULL;
            printf("Input %dst child index: ", j);
            scanf("%d", &childNode->child);
            if (pTree->nodes[i].firstChild == NULL) {
                tail = pTree->nodes[i].firstChild = childNode;
            } else {
                tail->next = childNode;
                tail = tail->next;
            }
        }
    }
}

void printTree(const CTree *pTree) {
    for (int i = 0; i < pTree->size; ++i) {
        printf("Parent node: %c\t", pTree->nodes[i].data);
        printf("Child nodes: ");
        CTNode *temp = pTree->nodes[i].firstChild;
        while (temp != NULL) {
            printf("%c\t", pTree->nodes[temp->child].data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void test() {
    CTree tree;
    printf("Input size of tree: ");
    int size;
    scanf("%d", &size);
    initTree(&tree, size);
    printTree(&tree);
}

int main() {
    test();
    return 0;
}