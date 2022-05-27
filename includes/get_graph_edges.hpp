#ifndef GET_GRAPH_EDGES_HPP
# define GET_GRAPH_EDGES_HPP

#include "header.hpp"

void    getUserInput(vEdge& edges, std::string file);
bool    lineHasVertices(std::string& str);
size_t  getVertice(std::string& str, size_t& idx);

#endif // GET_GRAPH_EDGES_HPP
