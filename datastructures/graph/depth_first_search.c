#include <assert.h>
#define VERTEX_NUM 5
typedef char ElemType;
#include <stdio.h>
typedef struct {
    ElemType vertex[VERTEX_NUM];
    int edge[VERTEX_NUM][VERTEX_NUM];
}Graph;

void initVertex(Graph *graph) {
    for (int i = 0; i < VERTEX_NUM; ++i) {
        graph->vertex[i] = '\0';
    }
}

void initEdge(Graph *graph)  {
    for (int i = 0; i < VERTEX_NUM; ++i) {
        for (int j = 0; j < VERTEX_NUM; ++j) {
            graph->edge[i][j] = 0;
        }
    }
}

void initGraph(Graph *graph) {
    initVertex(graph);
    initEdge(graph);
}

/**
 * Insert vertexes graph with example vertexes, see images/adjacency_matrix_graph.jpeg
 * @param graph the graph store vertexes.
 */
void insertVertex(Graph *graph) {
    for (int i = 0; i < VERTEX_NUM; ++i) {
        graph->vertex[i] = 'A' + i;
    }
}

/**
 * Insert edges with example graph. See images/adjacency_matrix_graph.jpeg
 * @param graph graph the graph store edges.
 */
void insertEdge(Graph *graph) {
    int matrix[VERTEX_NUM][VERTEX_NUM] = {
            {0, 1, 1, 1, 0},
            {1, 0, 0, 1, 1},
            {1, 0, 0, 1, 0},
            {1, 1, 1, 1, 1},
            {0, 1, 0, 1, 0}
    };
    for (int i = 0; i < VERTEX_NUM; ++i) {
        for (int j = 0; j < VERTEX_NUM; ++j) {
            graph->edge[i][j] = matrix[i][j];
        }
    }
}

int visited[VERTEX_NUM];

void depthFirstSearch(Graph *graph, int start) {
    printf("%c\t", graph->vertex[start]);
    visited[start] = 1;
    for (int i = 0; i < VERTEX_NUM; ++i) {
        if (graph->edge[start][i] == 1 && visited[i] == 0) {
            depthFirstSearch(graph, i);
        }
    }
}

void test() {
    Graph graph;
    initGraph(&graph);
    insertVertex(&graph);
    insertEdge(&graph);
    depthFirstSearch(&graph, 0);
}

int main() {
    test();
    return 0;
}