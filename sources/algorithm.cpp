#include "../includes/algorithm.hpp"

size_t  countSimpleCycles(size_t **mx, size_t len, size_t size)
{
    // all vertex are marked un-visited initially.
	bool    marked[size];
	memset(marked, 0, sizeof(marked));

	// Searching for cycle by using v-n+1 vertices
	size_t  count = 0;
	for (size_t i = 0; i < size - (len - 1); i++) {
		dfs(mx, marked, len - 1, i, i, count, size);
		// ith vertex is marked as visited and
		// will not be visited again.
		marked[i] = true;
	}
	return count/2;
}

void    dfs(size_t **mx, bool *marked, size_t len, size_t vert, size_t start, size_t& count, size_t size)
{
	// mark the vertex vert as visited
	marked[vert] = true;
	// if the path of length (n-1) is found
	if (!len)
    {
		// mark vert as un-visited to make
		// it usable again.
		marked[vert] = false;

		// Check if vertex vert can end with
		// vertex start
		if (mx[vert][start])
		{
			count++;
			return;
		} 
        else
			return;
	}

	// For searching every possible path of
	// length (n-1)
	for (size_t i = 0; i < size; i++)
		if (!marked[i] && mx[vert][i])

			// DFS for searching path by decreasing
			// length by 1
			dfs(mx, marked, len - 1, i, start, count, size);

	// marking vert as unvisited to make it
	// usable again.
	marked[vert] = false;
}

void    findSimpleCycles(size_t **mx, size_t len, size_t size)
{
    cout << "Total simple cycles of length " << len << " are " 
         << countSimpleCycles(mx, len, size);
}
