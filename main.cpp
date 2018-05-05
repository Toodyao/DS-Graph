#include <iostream>
#include <cstdio>
#include "graph_adj_list.h"
#include "graph_algorithms.h"
#include "gaph_adj_matrix.h"
using namespace std;


int main() {
	freopen("../input.txt", "r", stdin);


	int vertex_num;
	cin >> vertex_num;
	GraphAdjList g_list(vertex_num);

	int start, end = 0, weight = 0;
	while (cin >> start >> end >> weight) {
		g_list.add_edge(start, end, weight);
		g_list.add_edge(end, start, weight);
	}

//	auto &v = g_list.v_list;
//	for (auto i : v) {
//		for (auto j : i.edge_list) {
//			cout << j.e_num << "->";
//		}
//		cout << "X";
//		cout << endl;
//	}

	int n = g_list.vertex_num();
	auto dist = new int[n];
	auto path = new int[n];
	dijkstra_not_use_heap(g_list, 0, dist, path);
	for (int i = 0; i < n; i++)
		printf("%d ", dist[i]);
	printf("\n");
	for (int i = 0; i < n; i++)
		printf("%d ", path[i]);
	printf("\n");

	dijkstra(g_list, 0, dist, path);
	for (int i = 0; i < n; i++)
		printf("%d ", dist[i]);
	printf("\n");
	for (int i = 0; i < n; i++)
		printf("%d ", path[i]);

	cout << "\n-----------------" << endl;

	cin >> vertex_num;
	GraphAdjMatrix g_matrix(vertex_num);

	while (cin >> start >> end >> weight) {
		g_matrix.add_edge(start, end, weight);
		g_matrix.add_edge(end, start, weight);
	}
	n = g_list.vertex_num();
	dist = new int[n];
	path = new int[n];
	dijkstra_not_use_heap(g_list, 0, dist, path);
	for (int i = 0; i < n; i++)
		printf("%d ", dist[i]);
	printf("\n");
	for (int i = 0; i < n; i++)
		printf("%d ", path[i]);
	printf("\n");

	dijkstra(g_list, 0, dist, path);
	for (int i = 0; i < n; i++)
		printf("%d ", dist[i]);
	printf("\n");
	for (int i = 0; i < n; i++)
		printf("%d ", path[i]);


	return 0;
}

