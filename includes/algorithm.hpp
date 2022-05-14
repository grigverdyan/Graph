#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

#include "header.hpp"

void    findSimpleCycles(size_t **mx, size_t len, size_t size);
size_t  countSimpleCycles(size_t **mx, size_t len, size_t size);
void    dfs(size_t **mx, bool *marked, size_t len, size_t vert, size_t start, size_t& count, size_t size, vector<size_t>& cycleVertices);

#endif // ALGORITHM_HPP
