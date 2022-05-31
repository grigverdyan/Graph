#include "simple_cycle.hpp"

size_t  a = 0;
size_t  b = 0;

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
    for (size_t i = 0; i < mMarked.size(); ++i) {	// all vertex are marked unvisited initially.
		mMarked[i] = 0;
    }*/	    
    mMarked = std::vector<bool>(graph.mAdjacencySize, false);
    if (detectCycle(1, -1, graph) == true) {  // if cycle is present resetting the visited array for simple cycle finding
	    mMarked = std::vector<bool>(graph.mAdjacencySize, false);
        findSomeSimpleCycle(graph);

		// Printing the simple cycle
		std::cout << "A simple cycle: ";
		for (size_t i = 0; i < mSimpleCycle.size(); ++i) {
			std::cout << mSimpleCycle[i] << " => ";
		}
		std::cout << a;
		std::cout << "\n";
	}
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
template<typename T>
bool    SimpleCycle<T>::detectCycle(size_t node, size_t par, Graph<T> graph)
{
	mMarked[node] = 1;  // Marking the current node visited
	for (size_t child : graph.mAdjacencyMatrix[node]) {  // Traversing to the childs of the current node Simple DFS approach
		if (mMarked[child] == 0) {
			if (detectCycle(child, node, graph))
				return true;
		} else if (child != par) {  // Checking for a back-edge
			// A cycle is detected marking the end-vertices of the cycle
			a = child;
			b = node;
			return true;
		}
	}
	return false;
}

// Function to get the simple cycle from the end-vertices of the cycle we found from DFS
template<typename T>
void    SimpleCycle<T>::findSomeSimpleCycle(Graph<T> graph)
{
	// Parent array to get the path
    std::vector<size_t>   par(graph.mAdjacencySize, -1);

	// Queue for BFS
	QueueVertexType queue;
	queue.push(a);
	bool ok = true;
	while (!queue.empty()) {
		size_t node = queue.front();
		queue.pop();
		mMarked[node] = 1;
		for (size_t child : graph.mAdjacencyMatrix[node]) {
			if (node == a && child == b)
				continue;           // Ignoring the direct edge between a and b
			if (mMarked[child] == 0) {
				par[child] = node;  // Updating the parent array
				if (child == b) {   // If b is reached, we've found the shortest path from a to b already
					ok = false;
					break;
				}
				queue.push(child);
				mMarked[child] = 1;
			}
		}
		if (ok == false)            // If required task is done
			break;
	}

	// Cycle starting from a
	mSimpleCycle.push_back(a);
	size_t x = b;

	while (x != a) {                // Until we reach a again
		mSimpleCycle.push_back(x);
		x = par[x];
	}
}
