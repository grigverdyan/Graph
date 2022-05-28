#include "utils.hpp"
#include "get_graph_edges.hpp"
#include "graph.hpp"
#include "error_message.hpp"
#include "simple_cycle.hpp"

int main(int argc, char *argv[])
{
    // alias
    using VertexType = size_t;

    try {
        size_t  len = parseFile(argc, argv);
    }   catch (ErrorMessage& error) {
        error.showErrorMessage();
    }

    vEdge edges;
    std::string  inputFile = argv[2];
    getUserInput(edges, inputFile);
    Graph<VertexType>   graph(edges);
    // graph.displayAdjacency();
    SimpleCycle<VertexType> cycle(len, graph);
    cycle.findSimpleCycles(graph);

}
