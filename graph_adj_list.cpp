#include "graph_adj_list.h"

GraphAdjList::GraphAdjList() = default;

GraphAdjList::GraphAdjList(int size) {
		for (int i = 0; i < size; i++)
			add_vertex(i);
	}

int GraphAdjList::vertex_weight(int v) {
	return v_list[v].v_weight;
}

int GraphAdjList::edge_weight(int st, int ed) {
	std::vector<edge_node> temp = v_list[st].edge_list;
	int ret = INF;

	for (auto i : temp) {
		if (i.e_num == ed) {
			ret = i.e_weight;
			break;
		}
	}

	return ret;
}

void GraphAdjList::add_vertex(int vertex_num, int vertex_weight) {
	auto &v = v_list;
	bool need_push = true;
	for (auto it = v.begin(); it != v.end(); ++it) {
		if (it->v_num == vertex_num) { // found
			it->v_weight = vertex_weight;
			need_push = false;
			break;
		} else if (it->v_num > vertex_num) {
			// not found, value is in the middle position
			v.insert(it, vertex_node(vertex_num, vertex_weight));
			need_push = false;
			break;
		}
	}
	if (need_push)
		v_list.push_back(vertex_node(vertex_num, vertex_weight));

	v_num++;
}

void GraphAdjList::add_edge(int st, int ed, int weight) {
	// find vertex node 'st' in order
	std::vector<edge_node> *temp_ptr = nullptr;
	for (auto &i : v_list) {
		if (i.v_num == st) {
			temp_ptr = &i.edge_list;
			break;
		}
	}

	if (temp_ptr == nullptr)
		return;

	auto &temp = *temp_ptr;

	// insert in order
	auto it = temp.begin();
	for (it = temp.begin(); it != temp.end(); ++it) {
		auto num = (*it).e_num;
		if (ed == num) {
			temp.insert(it, edge_node(ed, weight));
			break;
		}
		else if (ed < num) {
			if (it != temp.begin())
				it--;
			temp.insert(it, edge_node(ed, weight));
			break;
		}

	}

	// if not find, push back
	if (it == temp.end())
		temp.push_back(edge_node(ed, weight));

	e_num++;
}

void GraphAdjList::del_vertex(int vertex_num) {
	auto &v = v_list;

	// delete 'vertex_num' edge nodes in the adjacency list
	for (auto &i : v) {
		auto &edges = i.edge_list;
		for (auto it = edges.begin(); it != edges.end(); ++it) {
			if ((*it).e_num == vertex_num) {
				edges.erase(it);
				break;
			}
		}
	}

	// delete 'vertex_num' head node in adjacency list
	for (auto it = v.begin(); it != v.end(); ++it) {
		if ((*it).v_num == vertex_num) {
			v.erase(it);
			break;
		}
	}

	v_num--;
}

void GraphAdjList::del_edge(int st, int ed) {
	auto &e = v_list[st].edge_list;
	for (auto it = e.begin(); it != e.end(); ++it) {
		if ((*it).e_num == ed) {
			e.erase(it);
			break;
		}
	}

	e_num--;
}
