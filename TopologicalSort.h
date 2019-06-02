#ifndef TOPOLOGICALSORT_H_
#define TOPOLOGICALSORT_H_

#include <iostream>
#include <queue>
#include "DFS.h"
#include "Digraph.h"
#include "Vertex.h"

class TopologicalSort {
   private:
    Digraph digraph;
    DFS dfs;
    std::queue<int> Q;
    enum Color { white, gray, black };
    std::vector<Color> color;

   public:
    TopologicalSort(Digraph G) : digraph(G), dfs(digraph) {}

    bool hasBackEdge(int u) {
        color[u] = gray;
        int vertex;

        for (int j = 0; j < digraph.Size(); j++) {
            // Exist adjacency
            if (digraph.adjacency_matrix[u][j] == 0) continue;

            vertex = j;

            if (color[vertex] == gray) return true;

            if ((color[vertex] == white) && (hasBackEdge(vertex))) return true;
        }

        color[u] = black;
        return false;
    }

    bool isDAG(Digraph digraph) {
        int source_counter = 0;
        int goal_counter = 0;

        color.assign(digraph.Size(), white);

        for (int i = 0; i < digraph.Size(); i++) {
            if (color[i] == white) {
                if (hasBackEdge(i)) {
                    return false;
                }
            }
        }
        for (int i = 0; i < digraph.Size(); i++) {
            if (digraph.vertices[i].get_in_degree() == 0) source_counter++;
            if (digraph.vertices[i].get_out_degree() == 0) goal_counter++;
        }

        if ((source_counter != 0) && (goal_counter != 0))
            return true;
        else
            return false;
    }

    void ExecuteTopologicalSort() {
        if (isDAG(digraph)) {
            for (int i = 0; i < digraph.Size(); i++) {
                if (digraph.vertices[i].get_in_degree() == 0) {
                    Q.push(i);
                }
            }

            while (!Q.empty()) {
                int source = Q.front();
                Q.pop();

                dfs.traverse(source);
            }
        } else {
            std::cout << "This graph is not acyclic." << std::endl;
        }
    }

    void showTopologicalSort() {
        if (isDAG(digraph)) {
            digraph.showGraph();
            std::reverse(dfs.topologic_order.begin(),
                         dfs.topologic_order.end());
            for (int i = 0; i < digraph.Size(); i++) {
                std::cout << "[" << dfs.topologic_order[i] << "]";
            }
        } else {
            std::cout << "Cannot show input graph is not acyclic.";
        }
    }
};

#endif