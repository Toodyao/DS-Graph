#ifndef DS_GRAPH_GRAPH_ADJ_LIST_H
#define DS_GRAPH_GRAPH_ADJ_LIST_H

#include <vector>
#include "graph.h"

const int INF = 0x3F3F3F3F;

class GraphAdjList : public Graph {
private:
	struct edge_node {
		int st, ed;
		int e_weight;
		edge_node():st(-1), ed(-1), e_weight(INF) {}
		edge_node(int s, int e, int w):st(s), ed(e), e_weight(w) {}
	};

	struct vertex_node {
		int v_weight;
		std::vector<edge_node> edge_list;
		vertex_node():v_weight(INF) {}
		vertex_node(int weight):v_weight(weight) {}
	};

	std::vector<vertex_node> v_list;
public:
	GraphAdjList();
	GraphAdjList(unsigned int num);
	~GraphAdjList() {};
	int vertex_weight(int v) override;
	int edge_weight(int st, int ed) override;
	void add_vertex(int vertex) override;
	void add_edge(int st, int ed, int weight) override;
	void del_vertex(int v) override;
	void del_edge(int st, int ed) override;

};


#endif //DS_GRAPH_GRAPH_ADJ_LIST_H
