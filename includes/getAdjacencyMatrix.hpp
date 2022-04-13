#ifndef ADJACENCY_MATRIX_H
# define ADJACENCY_MATRIX_H

#include "header.hpp"

size_t  adjacencyMatrixSize(vector<edge>& edges);
size_t  **newDynamic(size_t size);
void    deleteDynamic(size_t **mx, size_t size);
void    adjacencyMxFillZero(size_t **mx, size_t size);
void    buildAdjacencyMatrix(size_t **mx, vector<edge> edges);
void    simpleAdjacencyMatrix(size_t **mx, size_t size);
void    displayMatrix(size_t **mx, size_t size);

#endif /* ADJACENCY_MATRIX_H */