#ifndef WARSHALL_H_
#define WARSHALL_H_
#include <iostream>

class Warshall {
   	private:
   	public:
    Digraph WarshallAlgorithm(Digraph graph) {
    	for (int k = 0; k < graph.Size(); k++) {
            for (int i = 0; i < graph.Size(); i++) {
                for (int j = 0; j < graph.Size(); j++) {
                    graph.edge[i][j] =
                        (graph.edge[i][j] ||
                         (graph.edge[i][k] &&
                          graph.edge[k][j]));
                }
            }
        }

        std::cout << "   ";
        for (int i = 0; i < graph.Size(); i++)
            std::cout << graph.vertices[i].getName() << "   ";
        std::cout << std::endl;

        for (int i = 0; i < graph.Size(); i++) {
            std::cout << graph.vertices[i].getName() << "  ";
            for (int j = 0; j < graph.Size(); j++) {
                std::cout << graph.edge[i][j] << "   ";
            }
            std::cout << std::endl;
        }

        return graph;
    }
};

#endif