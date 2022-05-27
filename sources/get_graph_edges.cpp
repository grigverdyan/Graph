#include "../includes/get_graph_edges.hpp"
#include "../includes/error_message.hpp"

void    getUserInput(vEdge& edges, std::string file)
{
    std::fstream    inFile;
    std::string     inputPath ="data/" + file;
    inFile.open(inputPath);
    if (!inFile.is_open()) {
        throw ErrorMessage("\n\t[File ERROR]: Can not open \"file\" file!");
    }

    size_t      idx;
    size_t      edgeCount = 0;
    size_t      left;
    size_t      right;
    std::string str;

    // line-by-line getting edges of graph
    while (getline(inFile, str)) {
        idx = 0;
        if (!lineHasVertices(str)) {
            continue;
        }
        left = getVertice(str, idx);
        right = getVertice(str, idx);

        if (left && right) {
            edges.push_back(edge());
            edges[edgeCount].left = left;
            edges[edgeCount].right = right;
            edgeCount++;
        }
    }

    if (!edges.size()) {
        throw ("\n\t[Input ERROR]: Incorrect input file. Edges not found!");
    }
    inFile.close();
}

bool    lineHasVertices(std::string& str)
{
    for (size_t i = 0; i < str.size(); i++) {
        if (isdigit(str[i])) {
            return true;
        }
    }
    return false;
}

size_t  getVertice(std::string& str, size_t& idx)
{
    size_t  vertex = 0;

    // skip non-digit characters
    while (str[idx] && !isdigit(str[idx])) {
        idx++;
    }

    size_t      i = 0;
    const short MaxVerticeDigit = 3; // maximum digits in a vertice

    // get a vertice from a string
    while (str[idx] && isdigit(str[idx]) && i < MaxVerticeDigit) {
        vertex = vertex * 10 + (str[idx++] - '0');
        i++;
    }

    // skip spaces
    while (str[idx] && str[idx] != ' ') {
        idx++;
    }

    return vertex;
}
