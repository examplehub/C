#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef char ElemType;
typedef struct TNode {
    ElemType data;
    int parent;
} TNode;

typedef struct PTree {
    TNode nodes[MAX_SIZE];
    int root; /* the index of root node in array */
    int size; /* the number of nodes in tree */
} PTree;

void initTree(PTree *pTree, int size) {
    pTree->size = size;
    printf("Input node's data and parent index\n");
    pTree->root = 0; /* default store root node at 0 index */
    for (int i = 0; i < size; ++i) {
        getchar();
        scanf("%c %d", &pTree->nodes[i].data, &pTree->nodes[i].parent);
    }
}

void printTree(const PTree *pTree) {
    printf("index\tvalue\tp_index\tp_value\n");
    for (int i = 0; i < pTree->size; ++i) {
        printf("%d\t%c\t%d\t%c\n", i, pTree->nodes[i].data,
               pTree->nodes[i].parent, pTree->nodes[pTree->nodes[i].parent].data);
    }
}

ElemType searchParent(PTree *tree, ElemType target) {
    for (int i = 0; i < tree->size; ++i) {
        if (tree->nodes[i].data == target) {
            return tree->nodes[tree->nodes[i].parent].data;
        }
    }
    return '\0'; /* not found */
}

void test() {
    PTree tree;
    int size;
    printf("Input the number of nodes of tree:");
    scanf("%d", &size);
    initTree(&tree, size);
    assert(searchParent(&tree, 'B') == 'A');
    printTree(&tree);
}

int main() {
    test();
    return 0;
}

