#include <assert.h>
#include <stdio.h>

#define VERTEX_NUM 5
typedef char ElemType;
typedef struct {
    ElemType vertex[VERTEX_NUM];
    int edge[VERTEX_NUM][VERTEX_NUM];
} Graph;

void initGraph(Graph *graph) {
    /* init vertex */
    for (int i = 0; i < VERTEX_NUM; ++i) {
        graph->vertex[i] = '\0';
    }

    /* init edge */
    for (int i = 0; i < VERTEX_NUM; ++i) {
        for (int j = 0; j < VERTEX_NUM; ++j) {
            graph->edge[i][j] = 0;
        }
    }
}

int getDegree(Graph *graph, ElemType vertex) {
    int vertexIndex = -1;
    for (int i = 0; i < VERTEX_NUM; ++i) {
        if (vertex == graph->vertex[i]) {
            vertexIndex = i;
            break;
        }
    }
    if (vertexIndex == -1) {
        perror("vertex not found.");
    }
    int sum = 0;
    for (int i = 0; i < VERTEX_NUM; ++i) {
        sum = sum + graph->edge[vertexIndex][i];
    }
    return sum;
}

void test() {
    Graph graph;
    initGraph(&graph);

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

    assert(2 == getDegree(&graph, 'A'));
    assert(3 == getDegree(&graph, 'B'));
    assert(2 == getDegree(&graph, 'C'));
    assert(3 == getDegree(&graph, 'D'));
    assert(2 == getDegree(&graph, 'E'));
}

int main() {
    test();
    return 0;
}