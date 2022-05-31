#ifndef SIMPLE_CYCLE_H
#define SIMPLE_CYCLE_H

#include "header.hpp"
#include "graph.hpp"

namespace GraphNamespace {

    template<typename T>
    class	SimpleCycle {
    public:
	    SimpleCycle(size_t, Graph<T>);
    	void    findSimpleCycles(Graph<T>);
    	size_t  countSimpleCycles(Graph<T>);
    	void    dfs(Graph<T>, size_t, size_t, size_t, size_t&);
    private:
    	size_t	mSimpleCyclesLength;
    	vBool	mMarked;
        std::vector<T>  mCycleVertices;
        std::vector<T>  mSimpleCycle;

    };  // class SimpleCycle

}   // namespace GraphNamespace

#include "simple_cycle_impl.hpp"

#endif // SIMPLE_CYCLE_HPP
