#include "simple_cycle.hpp"

template<typename T>
SimpleCycle<T>::SimpleCycle(size_t	len, Graph<T> graph)
{
	mSimpleCyclesLength = len;
	mMarked.resize(graph.mAdjacencySize);
	for (size_t i = 0; i < mMarked.size(); ++i)
		mMarked[i] = 0;

	// memset(mMarked, 0, graph.mAdjacencySize);	// all vertex are marked unvisited initially.
}

template<typename T>
SimpleCycle<T>::~SimpleCycle()
{
	// delete [] mMarked;
	// mMarked = nullptr;
}

template<typename T>
void    SimpleCycle<T>::findSimpleCycles(Graph<T> graph)
{

    std::cout << "Total simple cycles of length " << mSimpleCyclesLength
			  << " are " << countSimpleCycles(graph);
}

template<typename T>
size_t	SimpleCycle<T>::countSimpleCycles(Graph<T> graph)
{
	// Searching for cycle by using v-n+1 vertices
	size_t  count = 0;
	for (size_t i = 1; i < graph.mAdjacencySize - mSimpleCyclesLength + 1; ++i) {
		dfs(graph, mSimpleCyclesLength - 1, i, i, count);
		// mCycleVertices.clear();
		// else
		// {
		// 	std::cout << "sizeMatrix == " << mCycleVertices.size() << std::endl;
		// 	if (mCycleVertices.size() >= cycleLen) {
		// 		std::cout << "sizeMatrix == " << mCycleVertices.size() << std::endl;
		// 		for (auto vert: mCycleVertices) {
		// 			std::cout << vert << " ";
		// 		}
		// 		std::cout << std::endl;
		// 		mCycleVertices.clear();
		// 	}
		// }

		// ith vertex is marked as visited and will not be visited again.
		mMarked[i] = true;
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
			// if (mCycleVertices.size() >= 3) {
			// 	std::cout << "size == " << mSimpleCyclesLength<< std::endl;
			// 	for (auto& vert: mCycleVertices) {
			// 		std::cout << vert << " ";
			// 	}
			// 	std::cout << std::endl;
			// }
			// mCycleVertices.clear();
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
