#include <iostream>
#include <vector>

class Graph {
	public:
		int vertices;   // Gagatneri qanak
		std::vector <std::vector <int> > adjacencyMatrix; // Harevanutyan matric
	
		Graph(int vertices) { 
			this->vertices = vertices;
			for (int i = 0; i < this->vertices; i++)
				this->adjacencyMatrix.push_back(std::vector <int>());
		}

		void	addEdge(int u, int v) {
			if (u < 0 || u >= this->vertices || v < 0 || v >= this->vertices)
				return;
			this->adjacencyMatrix.at(u).push_back(v);
			this->adjacencyMatrix.at(v).push_back(u);
		}

		void	printGraph() {
			for (int i = 0; i < this->vertices; ++i) {
				std::cout << "\n Graph ";
				for (int j = 0; j < this->adjacencyMatrix.at(i).size(); j++)
					std::cout << "   " << this->adjacencyMatrix.at(i).at(j);
			}
		}

		void countSubGraph() {
			bool	visited[this->vertices];
			int	result = 0;
			for (int i = 0; i < this->vertices; i++)
				visited[i] = false;
			for (int i = 0; i < this->vertices; i++)
				if (!visited[i]) {
					result++;
					this->dfs(visited, i);
				}
			std::cout << "\n Number of Subgraphs in given Grapsh is : " << result;
		}

		void	dfs(bool visited[], int start) {
			if (start < 0 || start >= this->vertices)
				return;
			visited[start] = true;
			int	i = 0;
			while (i < this->adjacencyMatrix.at(start).size()) {
				if (!visited[this->adjacencyMatrix.at(start).at(i)])
					this->dfs(visited, this->adjacencyMatrix.at(start).at(i));
							i++;
			}
		}
};

int	main() {
	Graph *graph = new Graph(13);
	graph->addEdge(0, 1);
	graph->addEdge(1, 5);
	graph->addEdge(2, 3);
	graph->addEdge(2, 4);
	graph->addEdge(6, 7);
	graph->addEdge(7, 8);
	graph->addEdge(7, 12);
	graph->addEdge(9, 10);
	// Display graph element
	graph->printGraph();
	// Display number of subgraphs
	graph->countSubGraph();
	return 0;
}
