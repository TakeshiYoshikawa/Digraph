#ifndef SCC_H_
#define SCC_H_
#include <vector>
#include "DFS.h"
#include "Digraph.h"

class SCC {
   private:
    enum Color { white, gray, black };

   public:
    std::vector<std::vector<int> > component;
    Digraph digraph;
    Digraph transposed;

    SCC(Digraph G) : digraph(G), transposed(G) {}

    void Components() {
        // First, execute DFS to get finalized vertices.
        DFS path(digraph);
        for (int start = 0; start < digraph.vertices.size(); start++) {
            if (path.color[start] == path.white) {
                path.traverse(start);
            }
        }

        // Transpose input matrix
        transposed.Transpose();
        DFS transposedPath(transposed);

        // Execute DFS again with transposed as input.
        while (!(path.finalized_order.empty())) {
            int vertex = path.finalized_order.top();
            path.finalized_order.pop();

            if (transposedPath.color[vertex] == 0) {
                std::cout << "Component: ";
                transposedPath.findComponents(vertex, component);
                std::cout << std::endl;
            }
        }
    }
};

#endif