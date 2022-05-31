#ifndef HEADER_HPP
#define HEADER_HPP

// library includes
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <queue>

struct edge {
    size_t  left;
    size_t  right;
    edge() {
        this->left = 0;
        this->right = 0;
    }
};

using vEdge             = std::vector<edge>;
using VertexType        = size_t;
using QueueVertexType   = std::queue<VertexType>;

#endif // HEADER_HPP
