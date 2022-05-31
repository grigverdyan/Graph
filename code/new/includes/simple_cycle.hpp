#ifndef SIMPLECYCLE_HPP
#define SIMPLECYCLE_HPP

#include "header.hpp"
#include "graph.hpp"

//	aliases
template<typename T>
using vType   = std::vector<T>;
using vBool	  = std::vector<bool>;

template<typename T>
class	SimpleCycle {
public:
	SimpleCycle(size_t, Graph<T>);
	void    findSimpleCycles(Graph<T>);
	size_t  countSimpleCycles(Graph<T>);
	void    dfs(Graph<T>, size_t, size_t, size_t, size_t&);
    // for displaying some cycle
    bool    detectCycle(size_t, size_t, Graph<T>);
    void    findSomeSimpleCycle(Graph<T>);
private:
	size_t	mSimpleCyclesLength;
	vBool	mMarked;
    std::vector<T>	mCycleVertices;
    std::vector<T>   mSimpleCycle;

};

#include "simple_cycle_impl.hpp"

#endif // SIMPLECYCLE_HPP
