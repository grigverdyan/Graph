#include "../includes/getGraphEdges.hpp"

void    getUserInput(vector<edge>& edges)
{
    fstream     input_file;
    string      input_file_path = "../data/input.txt";
    input_file.open(input_file_path);
    if (!input_file.is_open())
    {
        cerr << "ERROR: can not open \"input.txt\" file\n";
        exit(1);
    }

    size_t  idx;
    size_t  edge_count = 0;
    size_t  left, right;
    string  str;

    // Line by line getting edges of graph
    while (getline(input_file, str))
    {
        idx = 0;
        if (!lineHasVertices(str))
            continue;
        left = getVertice(str, idx);
        right = getVertice(str, idx);

        if (left && right)
        {
            edges.push_back(edge());
            edges[edge_count].left = left;
            edges[edge_count].right = right;
            edge_count++;
        }
    }

    if (!edges.size())
    {
        cerr << "ERROR: Incorrect input file!\n";
        exit(2);
    }
    input_file.close();
}

bool    lineHasVertices(string& str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (isdigit(str[i]))
            return true;
    }
    return false;
}

size_t  getVertice(string& str, size_t& idx)
{
    size_t  vertex = 0;
    
    // escape non digit characters
    while (str[idx] && !isdigit(str[idx]))
        idx++;
    
    size_t      i = 0;
    const short vertice_max_digit = 3; // maximum digits in a vertice

    // getting a vertice from a string 
    while (str[idx] && isdigit(str[idx]) && i < vertice_max_digit)
    {
        vertex = vertex * 10 + (str[idx++] - '0');
        i++;
    }

    // skip spaces
    while (str[idx] && str[idx] != ' ')
        idx++;

    return vertex;
}