#include "../includes/get_graph_edges.hpp"
#include "../includes/utils.hpp"
#include "../includes/get_adjacency_matrix.hpp"
//#include "../includes/algorithm.hpp"
#include "../includes/error_message.hpp"

int main(int argc, char *argv[])
{
//    size_t  len;
    try {
        if (argc < 2) {
            throw ErrorMessage ("\n\t[File ERROR]: No path file from which to read the Graph!");
        } else if (argc < 3) {
            throw ErrorMessage ("\n\t[Input ERROR]: No length of simple cycles was specified!");
        }
    } catch (ErrorMessage& error) {
        error.showErrorMessage();
        exit(1);
    }

    std::string  inputFile = argv[2];
    try {
        if (!isValidFilename(inputFile)){
            throw ErrorMessage("\n\t[Extension ERROR]: Not valid file extension. MUST BE [.txt]");
        }
    } catch (ErrorMessage& error) {
        error.showErrorMessage();
        exit(2);
    }
    
    vEdge edges;
    try {
        getUserInput(edges, inputFile);
        size_t  size = getMatrixSize(edges);
        size_t**  adjacencyMatrix = newDynamic(size);
        buildMatrix(adjacencyMatrix, edges, size);
        displayMatrix(adjacencyMatrix, size);
    } catch (ErrorMessage& error) {
        error.showErrorMessage();
        exit(3);
    }
//    len = *argv[1] - '0';
//    findSimpleCycles(adjacencyMatrix, len, size);

}
