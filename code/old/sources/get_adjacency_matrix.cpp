#include "get_adjacency_matrix.hpp"
#include "error_message.hpp"

size_t   **newDynamic(size_t size)
{
    size_t**    mxAdjacency = new size_t* [size];
    if (!mxAdjacency) {
        throw ErrorMessage("\n\t[Memory ERROR]: Couldn't allocate mamory for adjacency matrix!");
    }

    for (size_t i = 0; i < size; i++) {
        mxAdjacency[i] = new size_t [size];
        if (!mxAdjacency[i]) {
            deleteDynamic(mxAdjacency, i);
            throw ErrorMessage ("\n\t[Memory ERROR: Couldn't allocate memory for adjacency matrix in row!", i);
        }
    }
    fillMatrixZero(mxAdjacency, size);
    return mxAdjacency;
}

void    deleteDynamic(size_t **mxAdjacency, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        delete [] mxAdjacency[i];
    }

    delete [] mxAdjacency;
    mxAdjacency = nullptr;
}

void    fillMatrixZero(size_t **mxAdjacency, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            mxAdjacency[i][j] = 0;
        }
    }
}

size_t  getMatrixSize(vEdge& edges)
{
    size_t    size = edges[0].left;
    for (size_t i= 0; i < edges.size(); i++) {
        if (edges[i].left > size) {
            size = edges[i].left;
        }
        if (edges[i].right > size) {
            size = edges[i].right;
        }
    }

    return size + 1;
}

void    buildMatrix(size_t **mxAdjacency, vEdge edges, size_t size)
{
    for (size_t i = 0; i < edges.size(); i++) {
        if (edges[i].left != edges[i].right) {
            mxAdjacency[edges[i].left][edges[i].right] += 1;
        }
        mxAdjacency[edges[i].right][edges[i].left] += 1;
    }

    // simplifies the graph, whether it is simple or not
    simplifyMatrix(mxAdjacency, size);
}

void    simplifyMatrix(size_t** mxAdjacency, size_t size)
{
    for (size_t i = 1; i < size; ++i) {
        for (size_t j = 1; j < size; ++j) {
            if (i == j) {
                mxAdjacency[i][j] = 0;
            } else if (mxAdjacency[i][j] > 1) {
                mxAdjacency[i][j] = 1;
            }
        }
    }

}

void    displayMatrix(size_t **mxAdjacency, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            std::cout << mxAdjacency[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
