#ifndef DS_GRAPH_GRAPH_ALGORITHMS_H
#define DS_GRAPH_GRAPH_ALGORITHMS_H

#include "graph.h"

void dijkstra(Graph &g, int start, int *&dist, int *&path);
int find_min(int size, int *dist, int *visit);

#endif //DS_GRAPH_GRAPH_ALGORITHMS_H
