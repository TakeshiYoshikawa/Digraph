#ifndef DFS_H_
#define DFS_H_
#include <vector>
#include <algorithm>
#include "Vertex.h"
#include "Digraph.h"

class DFS
{
private:
    int time;
    int dim;
    enum Color
    {
        white,
        gray,
        black
    };
    Digraph *digraph;
    std::vector<Color> color;

public:
    std::vector<int> discovered;
    std::vector<int> finalized;
    std::vector<int> predecessor;
    std::vector<std::string> topologic_order;

    DFS(Digraph *D)
    {
        this->digraph = D;
        this->dim = digraph->getNumberOfVertex();
        this->time = 0;

        color.assign(digraph->getNumberOfVertex(), white);
        discovered.assign(digraph->getNumberOfVertex(), 0);
        finalized.assign(digraph->getNumberOfVertex(), 0);
        predecessor.assign(digraph->getNumberOfVertex(), 0);
    }

    void init_DFS(int start_vertex)
    {
        DFS_visit(start_vertex);
    }

    void DFS_visit(int i)
    {
        color[i] = gray;
        //std::cout << " -> " << digraph->vertexes[i]->getName();
        discovered[i] = ++time;

        for (int j = 0; j < dim; j++)
        {
            if ((color[j] == white) && (digraph->adjacency_matrix[i][j] != 0))
            {
                predecessor[j] = i;
                DFS_visit(j);
            }

            color[i] = black;
            finalized[i] = time;
        }
        topologic_order.push_back(digraph->vertexes[i]->getName());
    }
};

#endif