#include "utils.hpp"
#include "get_graph_edges.hpp"
#include "graph.hpp"
#include "error_message.hpp"
#include "simple_cycle.hpp"

using namespace GraphNamespace;

int main(int argc, char *argv[]) try
{
	if (argc < 2) {
        throw ErrorMessage ("\n\t[File ERROR]: No path file from which to read the Graph!");
    } else if (argc < 3) {
        throw ErrorMessage ("\n\t[Input ERROR]: No length of simple cycles was specified!");
    }

	std::string file = argv[2];
    if (!isValidFilename(file)){
        throw ErrorMessage("\n\t[Extension ERROR]: Not valid file extension. MUST BE [.txt]");
    }
	size_t  len = atoi(argv[1]);
    if (!len) {
        throw ErrorMessage("\n\t[Input ERROR]: Not valid length of simple cycles specified!");
    }

    vEdge edges;
    getUserInput(edges, file);
    Graph<VertexType>   graph(edges);
    std::fstream out;
    out.open("data/out.txt", std::ios::out);
    if (!out.is_open()) {
        throw ErrorMessage ("\n\t[File ERROR]: Couldn't open file to write the Adjacency Matrix!");
    }
    graph.displayAdjacency(out);
    
    SimpleCycle<VertexType> cycle(len, graph);
    cycle.findSimpleCycles(graph);
   
    // Visualize input graph and adjacency matrix 
    system("python3 sources/visualization.py");
    return 0;

} catch (ErrorMessage& error) {
    error.showErrorMessage();
}
