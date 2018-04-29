#ifndef DS_GRAPH_GRAPH_HPP
#define DS_GRAPH_GRAPH_HPP

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
	virtual void add_vertex(int vertex)=0;
	virtual void add_edge(int st, int ed, int weight)=0;
	virtual void del_vertex(int v)=0;
	virtual void del_edge(int st, int ed)=0;

};

#endif //DS_GRAPH_GRAPH_HPP
