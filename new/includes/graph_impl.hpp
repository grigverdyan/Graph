#include "graph.hpp"
#include "error_message.hpp"

template<typename T>
Graph<T>::Graph(vEdge edges)
{
	mAdjacencySize = getMatrixSize(edges);
    mAdjacencyMatrix = newDynamic(mAdjacencySize);
	fillMatrixZero(mAdjacencyMatrix, mAdjacencySize);
    buildMatrix(edges);
}

template<typename T>
Graph<T>::Graph(const Graph& graph)
{
    if (&graph != this) {
        mAdjacencyMatrix = graph.mAdjacencyMatrix;
        mAdjacencySize = graph.mAdjacencySize;
    }
}

template<typename T>
size_t	Graph<T>::getMatrixSize(vEdge& edges)
{
	size_t	size = edges[0].left;
	for (size_t i = 0; i < edges.size(); i++) {
		if (edges[i].left > size) {
			size = edges[i].left;
		}
		if (edges[i].right > size) {
			size = edges[i].right;
		}
	}
	return size + 1;
}

template<typename T>
typename Graph<T>::Matrix   Graph<T>::newDynamic(size_t size)
{
    typename Graph<T>::Matrix matrix(size);
    for (size_t i = 0; i < mAdjacencySize; i++)
        matrix[i].resize(mAdjacencySize);
    return matrix;
}

template<typename T>
void	Graph<T>::fillMatrixZero(typename Graph<T>::Matrix matrix, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            matrix[i][j] = 0;
        }
    }
}

template<typename T>
void    Graph<T>::buildMatrix(vEdge edges)
{
    for (size_t i = 0; i < edges.size(); ++i) {
        if (edges[i].left != edges[i].right) {
            mAdjacencyMatrix[edges[i].left][edges[i].right] += 1;
        }
        mAdjacencyMatrix[edges[i].right][edges[i].left] += 1;
    }
    simplifyMatrix();
}

template<typename T>
void    Graph<T>::simplifyMatrix()
{
    for (size_t i = 1; i < mAdjacencySize; ++i) {
        for (size_t j = 1; j < mAdjacencySize; ++j) {
            if (i == j) {
                mAdjacencyMatrix[i][j] = 0;
            } else if (mAdjacencyMatrix[i][j] > 1) {
                mAdjacencyMatrix[i][j] = 1;
            }
        }
    }
}

template<typename T>
void    Graph<T>::displayAdjacency()
{
    for (size_t i = 0; i < mAdjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < mAdjacencyMatrix[i].size(); ++j) {
            std::cout << mAdjacencyMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
