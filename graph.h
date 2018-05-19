#ifndef DS_GRAPH_GRAPH_HPP
#define DS_GRAPH_GRAPH_HPP

static const int INF = 0x3F3F3F3F;

class Graph	{
protected:
	int e_num; // edge number
	int v_num; // vertex number
public:
	Graph() {
		e_num = 0;
		v_num = 0;
	};

	~Graph() {}

	bool empty() {
		return e_num == 0;
	}
	int vertex_num() {
		return v_num;
	}
	int edge_num() {
		return e_num;
	}

	virtual int vertex_weight(int v)=0;
	virtual int edge_weight(int st, int ed)=0;
	virtual void add_vertex(int vertex_num, int vertex_weight = INF)=0;
	virtual void add_edge(int st, int ed, int weight)=0;
	virtual void del_vertex(int v)=0;
	virtual void del_edge(int st, int ed)=0;
	virtual int **get_matrix()=0;
	virtual void dfs()=0;
	virtual void bfs(int start)=0;

};

#endif //DS_GRAPH_GRAPH_HPP
