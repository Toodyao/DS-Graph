#include <iostream>
#include "graph_adj_list.h"
using namespace std;

int main() {
	GraphAdjList g;

	g.add_vertex(0);
	g.add_vertex(1);
	g.add_vertex(2);
	g.add_vertex(4);

	g.add_edge(0, 2, 4);
	g.add_edge(1, 0, 7);
//	g.add_edge(2, 3, 5);
	g.add_edge(4, 1, 9);

	g.add_vertex(3);
	g.add_edge(3, 1, 6);
	g.add_edge(2, 3, 5);

	g.add_edge(0, 1, 10);
//	g.del_vertex(0);
//	g.del_edge(1, 0);
//	cout << g.v_list[0].v_weight << endl;
	auto &v = g.v_list;
	for (auto i : v) {
		for (auto j : i.edge_list) {
			cout << j.e_num << "->";
		}
		cout << "X";
		cout << endl;
	}



	return 0;
}