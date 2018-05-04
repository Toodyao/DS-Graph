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

int find_min(int size, int *dist, int *visit);

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


