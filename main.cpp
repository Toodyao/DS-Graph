#include <iostream>
#include <cstdio>
#include "graph_adj_list.h"
#include "graph_algorithms.h"
using namespace std;


int main() {
	freopen("../input.txt", "r", stdin);


	int vertex_num;
	cin >> vertex_num;
	GraphAdjList g(vertex_num);

	int start, end = 0, weight = 0;
	while (cin >> start >> end >> weight) {
		g.add_edge(start, end, weight);
		g.add_edge(end, start, weight);
	}

	auto &v = g.v_list;
	for (auto i : v) {
		for (auto j : i.edge_list) {
			cout << j.e_num << "->";
		}
		cout << "X";
		cout << endl;
	}
	int n = g.vertex_num();
	auto dist = new int[n];
	auto path = new int[n];
	dijkstra_not_use_heap(g, 0, dist, path);
	for (int i = 0; i < n; i++)
		printf("%d ", dist[i]);
	printf("\n");
	for (int i = 0; i < n; i++)
		printf("%d ", path[i]);
	printf("\n");

	dijkstra(g, 0, dist, path);
	for (int i = 0; i < n; i++)
		printf("%d ", dist[i]);
	printf("\n");
	for (int i = 0; i < n; i++)
		printf("%d ", path[i]);

	return 0;
}

