#include "graph_algorithms.h"
#include <algorithm>

void dijkstra(Graph &g, int start, int *&dist, int *&path) {
	int n = g.vertex_num();
	int *visit = new int[n];
	dist = new int[n];
	path = new int[n];

	//initiate arrays
	for (int i = 0; i < n; i++) {
		dist[i] = g.edge_weight(start, i); // update weight nearing 'start'
		path[i] = dist[i] == INF ? -1 : start; // update path nearing 'start'
		visit[i] = false;
	}

	dist[start] = 0;
	visit[start] = true;

	while (1) {
		int v = find_min(n, dist, visit);
		if (v == -1)
			break;
		visit[v] = true;
		for (int u = 0; u < n; u++) {
			int weight = g.edge_weight(v, u);
			if (!visit[u] && weight < INF) {
				if (dist[v] + weight < dist[u]) {
					dist[u] = dist[v] + weight;
					path[u] = v;
				}
			}
		}
	}
}

int find_min(int size, int *dist, int *visit) {
	// liner search, O(n)
	int min_num = INF;
	int min_pos = -1;
	for (int i = 0; i < size; i++)
		if (!visit[i] && min_num > dist[i]) {
			min_num = std::min(min_num, dist[i]);
			min_pos = i;
		}

	return min_pos;
}
