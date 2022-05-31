#include "some_simple_cycle.hpp"

using namespace GraphNamespace;

template<typename T>
SomeSimpleCycle<T>::SomeSimpleCycle(Graph<T> graph)
{
    mAdjacencySize = graph.mAdjacencySize - 1;
    size_t  row = 0,  column;
    for (size_t i = 1; i < graph.mAdjacencySize; ++i) {
        column = 0;
        for (size_t j = 1; j < graph.mAdjacencySize; ++j) {
            mAdjacencyMatrix[row][column++] = graph.mAdjacencyMatrix[i][j];
        }
        row++;
    }
    for (size_t i = 0; i < mAdjacencySize; ++i) {
        mVisited[i] = false;
    }
    
//    mAdjacencyMatrix = graph.mAdjacencyMatrix;
//    mVisited = std::vector(mAdjacencySize, false);
}

template<typename T>
bool    SomeSimpleCycle<T>::detectSimpleCycle(T node, T par)
{
	mVisited[node] = 1;
	for (auto child : mAdjacencyMatrix[node]) {
		if (mVisited[child] == 0) {
			if (detectSimpleCycle(child, node))
				return true;
		}

		else if (child != par) {
			a = child;
			b = node;
			return true;
		}
	}
	return false;
}

template<typename T>
void    SomeSimpleCycle<T>::findSimpleCycle()
{
    std::vector<T>  par(mAdjacencySize, -1);
    std::queue<T>   q;
	q.push(a);
	bool ok = true;
	while (!q.empty()) {
		T   node = q.front();
		q.pop();
		mVisited[node] = 1;
		for (auto child : mAdjacencyMatrix[node]) {
			if (node == a && child == b)
				continue;

			if (mVisited[child] == 0) {
				par[child] = node;

				if (child == b) {
					ok = false;
					break;
				}
				q.push(child);
				mVisited[child] = 1;
			}
		}
		if (ok == false)
			break;
	}

	mSimpleCycle.push_back(a);
	T x = b;

	while (x != a) {
		mSimpleCycle.push_back(x);
		x = par[x];
	}
}

template<typename T>
void    SomeSimpleCycle<T>::displaySimpleCycle()
{
    for (size_t i = 0; i < mSimpleCycle.size(); ++i) {
        std::cout << mSimpleCycle[i] << "->";
    }
    std::cout << std::endl;
}

template<typename T>
void    SomeSimpleCycle<T>::displayAdjacency()
{
    for (size_t i = 0; i < mAdjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < mAdjacencyMatrix.size(); ++j) {
            std::cout << mAdjacencyMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
