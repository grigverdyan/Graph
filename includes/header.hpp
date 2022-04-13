#ifndef HEADER_H
# define HEADER_H

// library includes
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

// usings
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::fstream;
using std::cerr;

struct edge
{
    size_t  left;
    size_t  right;
    edge() {
        this->left = 0;
        this->right = 0;
    }
};

#endif /* HEADER_H */