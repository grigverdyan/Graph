#ifndef ADJACENCY_MATRIX_HPP
# define ADJACENCY_MATRIX_HPP

#include "header.hpp"

size_t  getMatrixSize(vEdge& edges);
size_t  **newDynamic(size_t size);
void    deleteDynamic(size_t **mx, size_t size);
void    fillMatrixZero(size_t **mx, size_t size);
void    buildMatrix(size_t **mx, vEdge edges, size_t size);
void    simplifyMatrix(size_t** mx, size_t size);
void    displayMatrix(size_t **mx, size_t size);

#endif // ADJACENCY_MATRIX_HPP
