#ifndef DFS_H_
#define DFS_H_
#include <algorithm>
#include <stack>
#include <vector>
#include "Digraph.h"
#include "Vertex.h"

class DFS {
   private:
    int time;
    Digraph digraph;
    static const int null = -1;

   public:
    enum Color { white, gray, black };
    std::stack<int> finalized_order;
    std::vector<Color> color;
    std::vector<int> discovered;
    std::vector<int> finalized;
    std::vector<int> predecessor;
    std::vector<std::string> topologic_order;

    DFS(Digraph D) : digraph(D), time(0) {
        color.assign(digraph.Size(), white);
        discovered.assign(digraph.Size(), 0);
        finalized.assign(digraph.Size(), 0);
        predecessor.assign(digraph.Size(), 0);
    }

    DFS(Digraph D, int initial_vertex)
        : digraph(D), time(0), color(digraph.Size(), white) {
        discovered.assign(digraph.Size(), 0);
        finalized.assign(digraph.Size(), 0);
        predecessor.assign(digraph.Size(), 0);

        predecessor.at(initial_vertex) = null;
        traverse(initial_vertex);
    }

    void traverse(int i) {
        color[i] = gray;
        // std::cout << "[" << digraph.vertices[i].getName() << "]";
        discovered[i] = ++time;

        for (int j = 0; j < digraph.Size(); j++) {
            if ((digraph.adjacency_matrix[i][j] == 1 && (color[j] == white))) {
                predecessor[j] = i;
                traverse(j);
            }

            color[i] = black;
            finalized[i] = time;
        }
        finalized_order.push(i);
        topologic_order.push_back(digraph.vertices[i].getName());
    }

    void findComponents(int i, std::vector<std::vector<int> > components) {
        color[i] = gray;
        // component[].push_back(i);
        std::cout << "[" << digraph.vertices[i].getName() << "]";
        discovered[i] = ++time;

        for (int j = 0; j < digraph.Size(); j++) {
            if ((color[j] == white) && (digraph.adjacency_matrix[i][j] != 0)) {
                predecessor[j] = i;
                findComponents(j, components);
            }

            color[i] = black;
            finalized[i] = time;
        }
        finalized_order.push(i);
        topologic_order.push_back(digraph.vertices[i].getName());
    }
};

#endif