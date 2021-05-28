#include <assert.h>

#define MAX_SIZE 100
typedef char ElemType;
typedef struct TNode {
    ElemType data;
    int parent;
} TNode;

typedef struct PTree {
    TNode nodes[MAX_SIZE];
    int root; /* the index of root node in array, default 0 */
    int size; /* the number of nodes in tree */
} PTree;


ElemType searchParent(PTree *tree, ElemType target) {

    for (int i = 0; i < tree->size; ++i) {
        if (tree->nodes[i].data == target) {
            if (tree->nodes[i].parent == -1) {
                return '\0';
            }
            return tree->nodes[tree->nodes[i].parent].data;
        }
    }
    return '\0'; /* not found */
}

void test() {
    //A(0) B(1) C(2) D(3) E(4) F(5) G(6) H(7) I(8) J(9) K(10)
    PTree tree = {
            .nodes = {
                    {'A', -1},
                    {'B', 0},
                    {'C', 0},
                    {'D', 0},
                    {'E', 1},
                    {'F', 1},
                    {'G', 2},
                    {'H', 3},
                    {'I', 3},
                    {'J', 5},
                    {'K', 6},
            },
            .root = 0,
            .size = 11
    };
    char data[][2] = {
            {'A', '\0'},
            {'B', 'A'},
            {'C', 'A'},
            {'D', 'A'},
            {'E', 'B'},
            {'F', 'B'},
            {'G', 'C'},
            {'H', 'D'},
            {'I', 'D'},
            {'J', 'F'},
            {'K', 'G'}
    };
    for (int i = 0, size = sizeof(data) / sizeof(data[0]); i < size; ++i) {
        assert(searchParent(&tree, data[i][0]) == data[i][1]);
    }
}

int main() {
    test();
    return 0;
}