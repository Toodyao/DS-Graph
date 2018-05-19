cmake_minimum_required(VERSION 3.10)
project(DS_Graph)

set(CMAKE_CXX_STANDARD 11)

add_executable(DS_Graph main.cpp graph.h graph_adj_list.cpp graph_adj_list.h graph_algorithms.cpp graph_algorithms.h graph_adj_matrix.cpp graph_adj_matrix.h)