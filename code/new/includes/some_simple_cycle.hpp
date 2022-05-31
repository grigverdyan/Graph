#ifndef SOME_SIMPLE_CYCLE_H
#define SOME_SIMPLE_CYCLE_H

#include "header.hpp"
#include "graph.hpp"

namespace GraphNamespace {

    template<typename T>
    class SomeSimpleCycle {
    public:
        typedef std::vector<std::vector<T>> Matrix;

        SomeSimpleCycle(Graph<T>);
        void    displayAdjacency();
        void    displaySimpleCycle();
        bool    detectSimpleCycle(T, T);
        void    findSimpleCycle();
    private:
       size_t   mAdjacencySize;
       Matrix   mAdjacencyMatrix;
       vBool    mVisited;
       T        a, b;
       std::vector<T>    mSimpleCycle;
    };  // class SomeSimpleCycle

}   // namespace GraphNamespace

#include "some_simple_cycle_impl.hpp"

#endif  // SOME_SIMPLE_CYCLE_H
