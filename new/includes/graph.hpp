#ifndef	GRAPH_HPP
#define GRAPH_HPP

#include "header.hpp"

template<typename T>
class Graph {
public:
	Graph(vEdge);
	Graph(const Graph&);
	typedef 	std::vector<std::vector<T> > Matrix;
	Matrix		mAdjacencyMatrix;
	size_t		mAdjacencySize;

	void		displayAdjacency();
private:
	void		buildMatrix(vEdge);
	void		fillMatrixZero(Matrix, size_t);
	void		simplifyMatrix();
	Matrix		newDynamic(size_t);
	size_t		getMatrixSize(vEdge&);
};

#include "graph_impl.hpp"
#endif
