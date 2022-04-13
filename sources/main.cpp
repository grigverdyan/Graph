#include "../includes/getGraphEdges.hpp"
#include "../includes/getAdjacencyMatrix.hpp"
#include "../includes/algorithm.hpp"

int main(int argc, char **argv)
{
    size_t  len;
    if (argc < 2)
    {
        cerr << "ERROR: please specify which length of simple cycles you want to find!\n"
             << "By default length is chosen as 3\n";
        len = 3;
    }
    vector<edge> edges;
    getUserInput(edges);

    size_t  size = adjacencyMatrixSize(edges);
    size_t**  adjacency_matrix = newDynamic(size);
    buildAndSimplifyAdjacencyMx(adjacency_matrix, edges, size);
    displayMatrix(adjacency_matrix, size);

    len = *argv[1] - '0';
    findSimpleCycles(adjacency_matrix, len, size);
}