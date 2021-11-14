#ifndef SCC_H_
#define SCC_H_
#include <map>
#include <vector>
#include "DFS.h"
#include "Digraph.h"

class SCC {
   private:
   public:
    int counter;
    int time;
    std::vector<int> discovered;
    std::vector<int> finalized;
    std::vector<int> predecessor;
    std::map<int, std::vector<int> > component;
    std::vector<bool> marked;
    Digraph graph, transposed;

    SCC(Digraph G) : graph(G), transposed(G) {
        counter = 0;
        discovered.assign(graph.Size(), 0);
        finalized.assign(graph.Size(), 0);
        predecessor.assign(graph.Size(), 0);
        marked.assign(graph.Size(), false);
    }

    void searchComponents(Digraph graph, int current_vertex) {
        marked[current_vertex] = true;
        discovered[current_vertex] = ++time;

        component[counter].push_back(current_vertex);

        for (int next = 0; next < graph.Size(); next++) {
            if ((graph.edge[current_vertex][next] == 1 && (!marked[next]))) {
                predecessor[next] = current_vertex;
                searchComponents(graph, next);
            }

            finalized[current_vertex] = time;
        }
    }

    void Components() {
        // First, execute DFS to get finalized vertices.
        DFS path(graph);

        for (int start = 0; start < graph.vertices.size(); start++) {
            if (path.color[start] == path.white) {
                path.traverse(start);
            }
        }

        // Transpose input matrix
        transposed.Transpose();

        // Execute DFS again with transposed as input.
        while (!(path.finalized_order.empty())) {
            int vertex = path.finalized_order.top();
            path.finalized_order.pop();

            if (!marked[vertex]) {
                searchComponents(transposed, vertex);
                counter++;
            }
        }
    }

    void showComponents() {
        for (int i = 0; i < component.size(); i++) {
            std::cout << "Component: ";
            for (int j = 0; j < component[i].size(); j++) {
                std::cout << "[" << graph.vertices[component[i][j]].getName()
                          << "]";
            }
            std::cout << std::endl;
        }
    }
};

#endif