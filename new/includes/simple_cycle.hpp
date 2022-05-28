#ifndef SIMPLECYCLE_HPP
#define SIMPLECYCLE_HPP

#include "header.hpp"
#include "graph.hpp"

using vSize_t = std::vector<size_t>;
using vBool	  = std::vector<bool>;

template<typename T>
class	SimpleCycle {
public:
	SimpleCycle(size_t, Graph<T>);
	~SimpleCycle();
	void    findSimpleCycles(Graph<T>);
	size_t  countSimpleCycles(Graph<T>);
	void    dfs(Graph<T>, size_t, size_t, size_t, size_t&);
private:
	size_t	mSimpleCyclesLength;
	vBool	mMarked;
	vSize_t	mCycleVertices;
};

#include "simple_cycle_impl.hpp"

#endif // SIMPLECYCLE_HPP
