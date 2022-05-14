#include "../includes/get_graph_edges.hpp"
#include "../includes/utils.hpp"
#include "../includes/get_adjacency_matrix.hpp"
#include "../includes/algorithm.hpp"

int main(int argc, char *argv[])
{
    size_t  len;
    if (argc < 2) {
        cerr << "ERROR: No path file from which to read the Graph and no specified length of graph\n";
        exit(1);
    } else if (argc < 3) {
        cerr << "ERROR: please specify which length of simple cycles you want to find!\n"
             << "By default length is chosen as 3\n";
        len = 3;
    }

    string  file = argv[2];
    if (!isValidFilename(file))
    {
        cerr << "ERROR: Not Valid file extension. MUST BE .txt\n";
        exit(2);
    }
    vector<edge> edges;
    getUserInput(edges, file);

    size_t  size = adjacencyMatrixSize(edges);
    size_t**  adjacency_matrix = newDynamic(size);
    buildAndSimplifyAdjacencyMx(adjacency_matrix, edges, size);
    displayMatrix(adjacency_matrix, size);

    len = *argv[1] - '0';
    findSimpleCycles(adjacency_matrix, len, size);

}
