#ifndef ADJACENCY_MATRIX_HPP
# define ADJACENCY_MATRIX_HPP

#include "header.hpp"

size_t  adjacencyMatrixSize(vector<edge>& edges);
size_t  **newDynamic(size_t size);
void    deleteDynamic(size_t **mx, size_t size);
void    adjacencyMxFillZero(size_t **mx, size_t size);
void    buildAndSimplifyAdjacencyMx(size_t **mx, vector<edge> edges, size_t size);
void    displayMatrix(size_t **mx, size_t size);

#endif // ADJACENCY_MATRIX_HPP
