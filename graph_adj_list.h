#ifndef DS_GRAPH_GRAPH_ADJ_LIST_H
#define DS_GRAPH_GRAPH_ADJ_LIST_H

#include <vector>
#include "graph.h"

class GraphAdjList : public Graph {
private:
	struct edge_node {
		//int st, ed;
		int e_num;
		int e_weight;
		edge_node():e_num(-1), e_weight(INF) {};
		edge_node(int num, int weight): e_num(num), e_weight(weight) {};
		//edge_node():st(-1), ed(-1), e_weight(INF) {}
		//edge_node(int s, int e, int w):st(s), ed(e), e_weight(w) {}
	};

	struct vertex_node {
		int v_num;
		int v_weight;
		std::vector<edge_node> edge_list;
		vertex_node():v_weight(INF) {}
		vertex_node(int num, int weight):v_num(num), v_weight(weight) {}
	};
	std::vector<vertex_node> v_list;

public:
	GraphAdjList();
	GraphAdjList(int num);
	~GraphAdjList() {};
	int vertex_weight(int v) override;
	int edge_weight(int st, int ed) override;
	void add_vertex(int vertex_num, int vertex_weight = INF) override;
	void add_edge(int st, int ed, int weight) override;
	void del_vertex(int v) override;
	void del_edge(int st, int ed) override;
	int **get_matrix() override;
	void dfs() override;
	void bfs(int start) override;

	void dfs_recursion(int n, bool *&visit);


};


#endif //DS_GRAPH_GRAPH_ADJ_LIST_H
