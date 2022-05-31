#ifndef	GRAPH_H
#define GRAPH_H

#include "header.hpp"

namespace GraphNamespace {

    template<typename T>
    class Graph {
    public:
	    typedef std::vector<std::vector<T>> Matrix;

        Graph(vEdge);
    	Graph(const Graph&);
    	Matrix		mAdjacencyMatrix;
    	size_t		mAdjacencySize;

    	void		displayAdjacency(std::fstream& output);
    private:
    	void		buildMatrix(vEdge);
    	void		fillMatrixZero(Matrix, size_t);
    	void		simplifyMatrix();
    	Matrix		newDynamic(size_t);
    	size_t		getMatrixSize(vEdge&);

    };  // class Graph

}   // namespace GraphNamespace

#include "graph_impl.hpp"

#endif  // GRAPH_H
