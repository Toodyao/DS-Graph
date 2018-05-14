#ifndef DS_GRAPH_GRAPH_ALGORITHMS_H
#define DS_GRAPH_GRAPH_ALGORITHMS_H

#include "graph.h"

void dijkstra_not_use_heap(Graph &g, int start, int *&dist, int *&path);
void dijkstra(Graph &g, int start, int *&dist, int *&path);
void floyd(Graph &g, int **&dist, int **&path);
#endif //DS_GRAPH_GRAPH_ALGORITHMS_H
