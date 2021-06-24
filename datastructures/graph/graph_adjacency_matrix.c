#include <assert.h>
#include <stdio.h>
#define VERTEX_NUM 5
typedef int ElemType;
typedef struct {
    ElemType vertex[VERTEX_NUM];
    int edge[VERTEX_NUM][VERTEX_NUM];
}Graph;

void initGraph(Graph *graph) {
    /* init vertex */
    for (int i = 0; i < VERTEX_NUM; ++i) {
        graph->vertex[i] = -1;
    }

    /* init edge */
    for (int i = 0; i < VERTEX_NUM; ++i) {
        for (int j = 0; j < VERTEX_NUM; ++j) {
            graph->edge[i][j] = 0;
        }
    }
}

int getOutOfDegree(Graph *graph, ElemType vertex) {
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

int getInOfDegree(Graph *graph, ElemType vertex) {
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
        sum = sum + graph->edge[i][vertexIndex];
    }
    return sum;
}

void test() {
    Graph graph;
    initGraph(&graph);

    /* init vertexes */
    for (int i = 0; i < VERTEX_NUM; ++i) {
        graph.vertex[i] = i;
    }

    /* init edges: see images/adjacency_matrix.png */
    int matrix[VERTEX_NUM][VERTEX_NUM] = {
            {0, 1, 1, 0, 0},
            {0, 0, 1, 0, 1},
            {0, 0, 0, 1, 0},
            {0, 0, 0, 0, 1},
            {0, 0, 0, 0, 0}
    };
    for (int i = 0; i < VERTEX_NUM; ++i) {
        for (int j = 0; j < VERTEX_NUM; ++j) {
            graph.edge[i][j] = matrix[i][j];
        }
    }

    assert(2 == getOutOfDegree(&graph, 0));
    assert(1 == getOutOfDegree(&graph, 2));
    assert(2 == getOutOfDegree(&graph, 1));
    assert(1 == getOutOfDegree(&graph, 3));
    assert(0 == getOutOfDegree(&graph, 4));

    assert(0 == getInOfDegree(&graph, 0));
    assert(1 == getInOfDegree(&graph, 1));
    assert(2 == getInOfDegree(&graph, 2));
    assert(1 == getInOfDegree(&graph, 3));
    assert(2 == getInOfDegree(&graph, 4));
}

int main() {
    test();
    return 0;
}

