#ifndef _SOURCE_HPP_
#define _SOURCE_HPP_

// Include header file
#include <iostream>
#include <vector>
using namespace std;

/*
    C++ Program
    Count number of subgraphs in a graph
*/
class Graph
{
	public:
	// Number of vertices in graph
	int vertices;
	// Use to collect edges information
	vector < vector < int > > adjacencylist;
	Graph(int vertices);
	void addEdge(int u, int v);
	void printGraph();
	void dfs(bool visited[], int start);
	void countSubGraph();
};

#endif
