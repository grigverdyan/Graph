#include "../includes/getAdjacencyMatrix.hpp"

size_t   **newDynamic(size_t size)
{
    size_t**    mx = new size_t* [size];
    if (!mx)
    {
        cerr << "ERROR: could not allocate mamory for adjacency matrix!\n";
        exit(3);
    }

    for (size_t i = 0; i < size; i++)
    {
        mx[i] = new size_t [size];
        if (!mx[i])
        {
            deleteDynamic(mx, i);
            cerr << "ERROR: could not allocate memory for adjacency matrix[" << i << "]!\n";
            exit(4); 
        }
    }
    adjacencyMxFillZero(mx, size);
    return mx;
}

void    deleteDynamic(size_t **mx, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        delete [] mx[i];
    }

    delete [] mx;
    mx = nullptr;
}

void    adjacencyMxFillZero(size_t **mx, size_t size)
{
    for (size_t i = 0; i < size; i++)
        for (size_t j = 0; j < size; j++)
            mx[i][j] = 0;
}

size_t  adjacencyMatrixSize(vector<edge>& edges)
{
    size_t  size = edges[0].left;
    for (size_t i= 0; i < edges.size(); i++)
    {
        if (edges[i].left > size)
            size = edges[i].left;
        if (edges[i].right > size)
            size = edges[i].right;
    }

    return size + 1;
}

void    buildAndSimplifyAdjacencyMx(size_t **mx, vector<edge> edges, size_t size)
{
    for (size_t i = 0; i < edges.size(); i++)
    {
        if (edges[i].left != edges[i].right)
            mx[edges[i].left][edges[i].right] += 1;
        mx[edges[i].right][edges[i].left] += 1;
    }

    for (size_t i = 1; i < size; i++)
        for (size_t j = 1; j < size; j++)
            if (i == j)
                mx[i][j] = 0;
            else if (mx[i][j] > 1)
                mx[i][j] = 1;
}

void    displayMatrix(size_t **mx, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
            cout << mx[i][j] << " ";
        cout << endl;
    }
}