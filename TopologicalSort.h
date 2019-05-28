#ifndef TOPOLOGICALSORT_H_
#define TOPOLOGICALSORT_H_

#include <iostream>
#include <queue>
#include "Vertex.h"
#include "Digraph.h"

class TopologicalSort
{
private:
    Digraph* digraph;
    DFS *dfs;
    std::queue<int> Q;
    enum Color
    {
        white,
        gray,
        black
    };
    std::vector<Color> color;
    int V;

public:
    TopologicalSort(Digraph *d)
    {
        digraph = d;
        dfs = new DFS(digraph);
        V = digraph->getNumberOfVertex();
    }

    bool hasBackEdge(int u)
    {
        color[u] = gray;
        int vertex;

        for (int j = 0; j < V; j++)
        {
            //Exist adjacency
            if (digraph->adjacency_matrix[u][j] == 0)
                continue;

            vertex = j;

            if (color[vertex] == gray)
                return true;

            if ((color[vertex] == white) && (hasBackEdge(vertex)))
                return true;
        }

        color[u] = black;
        return false;
    }

    bool isDAG(Digraph *d)
    {
        int source_counter = 0;
        int goal_counter = 0;

        color.assign(V, white);

        for (int i = 0; i < V; i++)
        {
            if (color[i] == white)
            {
                if (hasBackEdge(i))
                {
                    return false;
                }
            }
        }
        for(int i = 0; i < V; i++)
        {
            if(digraph->vertexes[i]->get_in_degree() == 0) 
                source_counter++;
            if(digraph->vertexes[i]->get_out_degree() == 0) 
                goal_counter++;
        }
        
        if((source_counter != 0) && (goal_counter != 0))
            return true;
        else
            return false;
    }

    void ExecuteTopologicalSort()
    {
        if(isDAG(digraph) == true)
        {
            for (int i = 0; i < V; i++)
            {
                if(digraph->vertexes[i]->get_in_degree() == 0)
                {
                    Q.push(i);
                }
            }

            while(!Q.empty())
            {
                int source = Q.front();
                Q.pop();

                dfs->init_DFS(source);
            }
        }
    }

    void showTopologicalSort()
    {
        std::reverse(dfs->topologic_order.begin(), dfs->topologic_order.end());
        for(int i = 0; i < V; i++)
        {
            std::cout << "[" << dfs->topologic_order[i] << "]"; 
        }
    }
};

#endif