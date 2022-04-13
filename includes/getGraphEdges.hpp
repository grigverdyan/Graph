#ifndef GET_GRAPH_EDGES_H
# define GET_GRAPH_EDGES_H

#include "header.hpp"

void    getUserInput(vector<edge>& edges);
bool    lineHasVertices(string& str);
size_t  getVertice(string& str, size_t& idx);

#endif /* GET_GRAPH_EDGES_H */