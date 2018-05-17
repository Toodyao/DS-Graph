#include <iostream>
#include <cstdio>
#include "graph_adj_list.h"
#include "graph_algorithms.h"
#include "gaph_adj_matrix.h"
using namespace std;
// TODO: get_matrix()返回问题，是引用还是重新拷贝？

void floyd_test(Graph &g);
void dijkstra_test(Graph &g);

void prime_test(Graph &g);

int main() {
	freopen("../input.txt", "r", stdin);


	int vertex_num;
	cin >> vertex_num;
	GraphAdjList g_list(vertex_num);
	GraphAdjMatrix g_matrix(vertex_num);

	int start, end = 0, weight = 0;
	while (cin >> start >> end >> weight) {
		g_list.add_edge(start, end, weight);
		g_list.add_edge(end, start, weight);
		g_matrix.add_edge(start, end, weight);
		g_matrix.add_edge(end, start, weight);
	}
//	cout << "\n-----Dijkstra Adj List-----" << endl;
//	dijkstra_test(g_list);
//	cout << "\n----Dijkstra Adj Matrix-----" << endl;
//	dijkstra_test(g_matrix);
//	cout << "\n------Floyd Adj List-------" << endl;
//	floyd_test(g_list);
//	cout << "\n-----Floyd Adj Matrix-------" << endl;
//	floyd_test(g_matrix);

	cout << "\n-----Prime-------" << endl;
	prime_test(g_list);
	cout << "\n-----Prime-------" << endl;
	// adj_list print:
	//	auto &v = g_list.v_list;
	//	for (auto i : v) {
	//		for (auto j : i.edge_list) {
	//			cout << j.e_num << "->";
	//		}
	//		cout << "X";
	//		cout << endl;
	//	}

	return 0;
}

void prime_test(Graph &g) {
	int MST_weight;

	MST_weight = prime(g, 0); // start from 0

	cout << "weight: " << MST_weight << endl;
	cout << "tree in bfs: " << endl;

}

void floyd_test(Graph &g) {
	int n = g.vertex_num();
	int **dist;
	int **path;
	floyd(g, dist, path);
	cout << "dist: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%-2d ", dist[i][j]);
		}
		printf("\n");
	}
	cout << "path: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (path[i][j] == INF)
				printf("-1 ");
			else
				printf("%2d ", path[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < n; i++)
		delete[] dist[i];
	delete dist;
	for (int i = 0; i < n; i++)
		delete[] path[i];
	delete path;
}

void dijkstra_test(Graph &g) {
	int n = g.vertex_num();
	auto dist = new int[n];
	auto path = new int[n];

	dijkstra(g, 0, dist, path);
	printf("dist: ");
	for (int i = 0; i < n; i++)
		printf("%d ", dist[i]);
	printf("\npath: ");
	for (int i = 0; i < n; i++)
		printf("%d ", path[i]);

	delete dist;
	delete path;
}
