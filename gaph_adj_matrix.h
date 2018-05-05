#ifndef DS_GRAPH_GRAPHADJMATRIX_H
#define DS_GRAPH_GRAPHADJMATRIX_H

#include "graph.h"

class GraphAdjMatrix : public Graph {
private:
	typedef int ** matrix;
	typedef int *  array;
	matrix edge_matrix;
	array vertex_array; // experimental, array stores vertex_weight

public:
	//GraphAdjMatrix();
	explicit GraphAdjMatrix(int num);
	~GraphAdjMatrix();
	int vertex_weight(int v) override;
	int edge_weight(int st, int ed) override;
	void add_vertex(int vertex_num, int vertex_weight = INF) override;
	void add_edge(int st, int ed, int weight) override;
	void del_vertex(int v) override;
	void del_edge(int st, int ed) override;

};


#endif //DS_GRAPH_GRAPHADJMATRIX_H
