#include "graph_algorithms.h"
#include <queue>
#include <algorithm>

class pair { // simple version of std::pair
public:
	// In this case, first stores weight, second stores to_edge
	int first;
	int second;
	pair(int fi, int se): first(fi), second(se) {}
	bool operator < (const pair &a) const {
		return a.first < first;
	}
};

typedef pair P;

int find_min_with_heap(std::priority_queue<P> & q, int *visit) {
	// using min_heap/priority_queue, O(log n)
	while (!q.empty()) {
		P temp = q.top();
		q.pop();
		if (!visit[temp.second]) {
			return temp.second;
		}
	}
	return -1;
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

void dijkstra(Graph &g, int start, int *&dist, int *&path) {
//	typedef std::pair<int, int> P; // first is weight, second is to_edge
	std::priority_queue<P> q;
	int n = g.vertex_num();
	int *visit = new int[n];
	dist = new int[n];
	path = new int[n];

	//initiate arrays
	for (int i = 0; i < n; i++) {
		dist[i] = g.edge_weight(start, i); // update weight nearing 'start'
		path[i] = dist[i] == INF ? -1 : start; // update path nearing 'start'
		visit[i] = false;
		q.push(P(g.edge_weight(start, i), i));
	}

	dist[start] = 0;
	visit[start] = true;
//	q.push(start);

	while (1) {
		int v = find_min_with_heap(q, visit);
		if (v == -1)
			break;
		visit[v] = true;
		for (int u = 0; u < n; u++) {
			int weight = g.edge_weight(v, u);
			if (!visit[u] && weight < INF) {
				if (dist[v] + weight < dist[u]) {
					dist[u] = dist[v] + weight;
					path[u] = v;
					q.push(P(dist[u], u));
				}
			}
		}
	}
}

void dijkstra_not_use_heap(Graph &g, int start, int *&dist, int *&path) {
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

void floyd(Graph &g, int **&dist, int **&path) {
	int n = g.vertex_num();
	int **adj_mat = g.get_matrix();
	dist = adj_mat;
	path = new int *[n];
	for (int i = 0; i < n; i++)
		path[i] = new int [n];

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = k;
				}
			}
		}
	}
}

int prime(Graph &g, int start) {
	std::priority_queue<P> q;
	GraphAdjList mst; // store MST in graph

	int n = g.vertex_num();
	int weight_sum = 0; // total weight of MST 
	int vertex_count = 0;

	int *dist = new int [n];
	int *visit = new int [n];
	int *path = new int [n];

	for (int i = 0; i < n; i++) {
		dist[i] = g.edge_weight(start,  i);
		path[i] = false;
		q.push(P(g.edge_weight(start, i), i));
	}

	dist[start] = 0;
	path[start] = -1; // start is the root of MST
	visit[start] = true;
	vertex_count = 1;

	while (1) {
		int v = find_min_with_heap(q, visit); // same as Dijkstra
		if (v == -1 || v == INF) // v == INF means graph is not connected
			break;

		// add 'v' into MST and marked as visited
		mst.add_edge(path[v], v, dist[v]);
		weight_sum += dist[v];
		vertex_count++;

		dist[v] = 0;
		visit[v] = true;

		// similar to Dijkstra
		for (int u = 0; u < n; u++) {
			int weight = g.edge_weight(v, u);
			if (dist[u] != 0 && weight < INF) {
				if (weight < dist[u]) {
					dist[u] = weight;
					path[u] = v;
					q.push(P(dist[u], u));
				}
			}
		}
	}

	// if not all vertex are included
	if (vertex_count < n) 
		weight_sum = -1;

	return weight_sum;
}


