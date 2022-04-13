#include <iostream>
#include <vector>
// CPP Program to count cycles of length n
// in a given graph.
using namespace std;

// Number of vertices
const int V = 7;

void DFS(bool graph[][V], bool marked[], int n, int vert, int start, int &count)
{
	// mark the vertex vert as visited
	marked[vert] = true;

	// if the path of length (n-1) is found
	if (n == 0) {

		// mark vert as un-visited to make
		// it usable again.
		marked[vert] = false;

		// Check if vertex vert can end with
		// vertex start
		if (graph[vert][start])
		{
			count++;
			return;
		} else
			return;
	}

	// For searching every possible path of
	// length (n-1)
	for (int i = 0; i < V; i++)
		if (!marked[i] && graph[vert][i])

			// DFS for searching path by decreasing
			// length by 1
			DFS(graph, marked, n-1, i, start, count);

	// marking vert as unvisited to make it
	// usable again.
	marked[vert] = false;
}

// Counts cycles of length N in an undirected
// and connected graph.
int countCycles(bool graph[][V], int n)
{
	// all vertex are marked un-visited initially.
	bool marked[V];
	memset(marked, 0, sizeof(marked));

	// Searching for cycle by using v-n+1 vertices
	int count = 0;
	for (int i = 0; i < V - (n - 1); i++) {
		DFS(graph, marked, n-1, i, i, count);

		// ith vertex is marked as visited and
		// will not be visited again.
		marked[i] = true;
	}

	return count/2;
}

int main()
{
	bool graph[][V] = { {0, 1, 0, 0, 0, 0, 1},
					    {1, 0, 1, 1, 1, 0, 0},
					    {0, 1, 0, 1, 0, 0, 0},
					    {0, 1, 1, 0, 1, 1, 0},
					    {0, 1, 0, 1, 0, 1, 0},
                        {0, 0, 0, 0, 1, 0, 1},
                        {1, 0, 0, 1, 1, 1, 0} };
	int n = 4;
	cout << "Total cycles of length " << n << " are "
		<< countCycles(graph, n);
	return 0;
}

// int main()
// {

// 	addEdge(1, 2);
// 	addEdge(2, 3);
// 	addEdge(3, 5);
// 	addEdge(4, 5);
// 	addEdge(5, 6);
// 	addEdge(4, 6);
// 	addEdge(2, 4);
// 	int color[N];
// 	int par[N];
// 	int mark[N];
// 	int cyclenumber = 0;
// 	int edges = 7;

// 	dfs_cycle(1, 0, color, mark, par, cyclenumber);
// 	printCycles(edges, mark, cyclenumber);
// }
