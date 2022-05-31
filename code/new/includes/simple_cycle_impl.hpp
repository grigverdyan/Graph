#include "simple_cycle.hpp"
#include "some_simple_cycle.hpp"

using namespace GraphNamespace;

template<typename T>
SimpleCycle<T>::SimpleCycle(size_t	len, Graph<T> graph)
{
	mSimpleCyclesLength = len;
	mMarked.resize(graph.mAdjacencySize);

	for (size_t i = 0; i < mMarked.size(); ++i) {	// all vertex are marked unvisited initially.
		mMarked[i] = 0;
	}
}

template<typename T>
void    SimpleCycle<T>::findSimpleCycles(Graph<T> graph)
{
	size_t	cycleCount = countSimpleCycles(graph);
	if (cycleCount == 0) {
		std::cout << "\nThere is NO simple cycle of length " << mSimpleCyclesLength << " in your graph!\n\n";
	} else if (cycleCount == 1) {
        std::cout << "\nThere is 1 simple cycle of length " << mSimpleCyclesLength << "!\n\n";
    } else {
        std::cout << "\nThere are "<< cycleCount << " simple cycles of length " << mSimpleCyclesLength << "!\n\n";
	}
/*
    SomeSimpleCycle simpleCycle(graph);
    simpleCycle.displayAdjacency();
    if (simpleCycle.detectSimpleCycle(1, -1) == true) {
        simpleCycle.findSimpleCycle();
        std::cout << "\nSimple Cycle: ";
        simpleCycle.displaySimpleCycle();
    } 
    */
}

template<typename T>
size_t	SimpleCycle<T>::countSimpleCycles(Graph<T> graph)
{
	// Searching for cycle by using v-n+1 vertices
	size_t  count = 0;
	for (size_t i = 1; i < graph.mAdjacencySize - mSimpleCyclesLength + 1; ++i) {
        dfs(graph, mSimpleCyclesLength - 1, i, i, count);
		mMarked[i] = true;		// i-th vertex is marked as visited and will not be visited again
	}
	return count / 2;
}

template<typename T>
void	SimpleCycle<T>::dfs(Graph<T> graph, size_t len, size_t vert, size_t start, size_t& count)
{
	mMarked[vert] = true;			// mark the vertex vert as visited
	mCycleVertices.push_back(vert);

	if (!len) {						// if the path of length (n-1) is found
		mMarked[vert] = false;		// mark vert as unvisited to make it usable again.
		if (graph.mAdjacencyMatrix[vert][start]) {	// check if vertex vert can end with vertex start
			count++;       
        }
		return;
	}

	for (size_t i = 1; i < graph.mAdjacencySize; ++i) {	// for searching every possible path of length (n-1)
		if (!mMarked[i] && graph.mAdjacencyMatrix[vert][i]) {
			dfs(graph, len - 1, i, start, count);		// DFS for searching path by decreasing length by 1        
        }
	}
	mMarked[vert] = false;								// marking vert as unvisited to make it usable again
}
