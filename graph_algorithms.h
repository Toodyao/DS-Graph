#ifndef DS_GRAPH_GRAPH_ALGORITHMS_H
#define DS_GRAPH_GRAPH_ALGORITHMS_H

#include "graph.h"
#include "graph_adj_list.h"

void dijkstra_not_use_heap(Graph &g, int start, int *&dist, int *&path);
void dijkstra(Graph &g, int start, int *&dist, int *&path); // optimized using heap
void floyd(Graph &g, int **&dist, int **&path);
void print_path_floyd(int i, int j, int **path);
int prime(Graph &g, int start, GraphAdjList *mst);
#endif //DS_GRAPH_GRAPH_ALGORITHMS_H
