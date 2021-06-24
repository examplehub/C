#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

#define VERTEX_NUM 5
typedef char ElemType;
typedef struct {
    ElemType vertex[VERTEX_NUM];
    int edge[VERTEX_NUM][VERTEX_NUM];
} Graph;

bool visited[VERTEX_NUM];
ElemType dfsPath[VERTEX_NUM];
int count = 0;
void deepFirstSearch(Graph *g, int start) {
    dfsPath[count++] = g->vertex[start];
    visited[start] = true;
    for (int i = 0; i < VERTEX_NUM; ++i) {
        if (g->edge[start][i] == 1 && !visited[i]) {
            deepFirstSearch(g, i);
        }
    }
}

void test() {
    Graph graph;
    /* init vertexes */
    for (int i = 0; i < VERTEX_NUM; ++i) {
        graph.vertex[i] = 'A' + i;
    }

    /* init edges: see images/adjacency_matrix.png */
    int matrix[VERTEX_NUM][VERTEX_NUM] = {
            {0, 1, 0, 1, 0},
            {1, 0, 1, 1, 0},
            {0, 1, 0, 0, 1},
            {1, 1, 0, 0, 1},
            {0, 0, 1, 1, 0}
    };
    for (int i = 0; i < VERTEX_NUM; ++i) {
        for (int j = 0; j < VERTEX_NUM; ++j) {
            graph.edge[i][j] = matrix[i][j];
        }
    }

    ElemType path[] = {'A', 'B', 'C', 'E', 'D'};
    deepFirstSearch(&graph, 0);
    for (int i = 0; i < VERTEX_NUM; ++i) {
        assert(path[i] == dfsPath[i]);
    }
}

int main() {
    test();
    return 0;
}