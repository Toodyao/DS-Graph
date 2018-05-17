#include "gaph_adj_matrix.h"

GraphAdjMatrix::GraphAdjMatrix(int num) {
	// allocate matrix memory
	edge_matrix = new int *[num];
	for (int i = 0; i < num; i++)
		edge_matrix[i] = new int[num];

	//initiate matrix
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			edge_matrix[i][j] = INF;

	// experimental function for vertex weight
	auto &v = vertex_array;
	v = new int[num];
	for (int i = 0; i < num; i++)
		v[i] = -1;

	v_num = num;
}

GraphAdjMatrix::~GraphAdjMatrix() {
	delete edge_matrix;

	// experimental function for vertex weight
	delete vertex_array;
}

int GraphAdjMatrix::vertex_weight(int v) {
	return vertex_array[v];
}

int GraphAdjMatrix::edge_weight(int st, int ed) {
	return edge_matrix[st][ed];
}

void GraphAdjMatrix::add_vertex(int vertex_num, int vertex_weight) {
	// experimental function
	vertex_array[vertex_num] = vertex_weight;
}

void GraphAdjMatrix::add_edge(int st, int ed, int weight) {
	edge_matrix[st][ed] = weight;
}

void GraphAdjMatrix::del_vertex(int v) {
	// experimental function
	vertex_array[v] = -1;
}

void GraphAdjMatrix::del_edge(int st, int ed) {
	edge_matrix[st][ed] = INF;
}

int **GraphAdjMatrix::get_matrix() {
	// return the copied matrix
	int n = v_num;
	int **mat = new int *[n];
	for (int i = 0; i < n; i++)
		mat[i] = new int [n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				mat[i][j] = 0;
			else
				mat[i][j] = edge_matrix[i][j];
		}
	}
	return mat;
}

