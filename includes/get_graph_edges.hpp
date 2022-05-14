#ifndef GET_GRAPH_EDGES_HPP
# define GET_GRAPH_EDGES_HPP

#include "header.hpp"

void    getUserInput(vector<edge>& edges, string file);
bool    lineHasVertices(string& str);
size_t  getVertice(string& str, size_t& idx);

#endif // GET_GRAPH_EDGES_HPP
