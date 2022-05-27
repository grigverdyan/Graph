#include "../includes/algorithm.hpp"

size_t  countSimpleCycles(size_t **mx, size_t cycleLen, size_t size)
{
    // all vertex are marked un-visited initially.
	bool    marked[size];
	memset(marked, 0, sizeof(marked));

	vector<size_t>	cycleVertices;
	// Searching for cycle by using v-n+1 vertices
	size_t  count = 0;
//	size_t  temp = 0;
	for (size_t i = 1; i < size - (cycleLen - 1); i++) {
	// 	temp = count;
		dfs(mx, marked, cycleLen - 1, i, i, count, size, cycleVertices);

		cycleVertices.clear();
		// else
		// {
		// 	std::cout << "size == " << cycleVertices.size() << std::endl;
		// 	if (cycleVertices.size() >= cycleLen) {
		// 		std::cout << "size == " << cycleVertices.size() << std::endl;
		// 		for (auto vert: cycleVertices) {
		// 			std::cout << vert << " ";
		// 		}
		// 		std::cout << std::endl;
		// 		cycleVertices.clear();
		// 	}
		// }

		// ith vertex is marked as visited and will not be visited again.
		marked[i] = true;
	}
	return count / 2;
}

void    dfs(size_t **mx, bool *marked, size_t cycleLen, size_t vert, size_t start, size_t& count, size_t size, vector<size_t>& cycleVertices)
{
	// mark the vertex vert as visited
	marked[vert] = true;
	cycleVertices.push_back(vert);

	// if the path of length (n-1) is found
	if (!cycleLen)
    {
		// mark vert as un-visited to make it usable again.
		marked[vert] = false;


		// Check if vertex vert can end with vertex start
		if (mx[vert][start]) {
			count++;
			if (cycleVertices.size() >= 3) {
				std::cout << "size == " << cycleLen<< std::endl;
				for (auto& vert: cycleVertices) {
					std::cout << vert << " ";
				}
				std::cout << std::endl;
			}
			cycleVertices.clear();
		}
		return;
	}

	// For searching every possible path of length (n-1)
	for (size_t i = 1; i < size; i++) {
		if (!marked[i] && mx[vert][i]) {

			// DFS for searching path by decreasing length by 1
			dfs(mx, marked, cycleLen - 1, i, start, count, size, cycleVertices);
		}
	}
	// marking vert as unvisited to make it usable again.
	marked[vert] = false;
}

void    findSimpleCycles(size_t **mx, size_t cycleLen, size_t size)
{
//     std::cout << "Total simple cycles of length " << cycleLen << " are "
//          <<
	countSimpleCycles(mx, cycleLen, size);
}
