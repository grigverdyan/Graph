#include "../includes/getGraphEdges.hpp"
#include "../includes/getAdjacencyMatrix.hpp"

int main()
{
    vector<edge> edges;
    getUserInput(edges);

    size_t  size = adjacencyMatrixSize(edges);
    size_t**  adjacency_matrix = newDynamic(size);
    buildAndSimplifyAdjacencyMx(adjacency_matrix, edges, size);
    
    displayMatrix(adjacency_matrix, size);
}