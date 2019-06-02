#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include "DFS.h"
#include "Digraph.h"
#include "SCC.h"
#include "TopologicalSort.h"
#include "Vertex.h"
#include "Warshall.h"

int main(int argc, char *argv[]) {
    std::vector<Vertex> vertices;
    // std::vector<std::string> name = {"short", "calca", "cinto",
    // 					  "jaqueta", "camisa", "gravata",
    // 					  "meia", "sapato", "relogio"};

    std::vector<std::string> name = {"a", "b", "c", "d", "e",
                                     "f", "g", "h", "i", "j"};

    // true - Digraph // false - Undirected Digraph
    Digraph digraph(name.size(), true);

    for (int i = 0; i < name.size(); i++) {
        Vertex vertex(name[i], i);
        vertices.push_back(vertex);
        digraph.add_vertex(vertices[i]);
        std::cout << vertices[i].getName() << " -> index "
                  << vertices[i].getValue() << std::endl;
    }

    digraph.add_edge(0, 1, 1);
    digraph.add_edge(0, 4, 1);
    digraph.add_edge(2, 0, 1);
    digraph.add_edge(2, 9, 1);
    digraph.add_edge(3, 2, 1);
    digraph.add_edge(5, 3, 1);
    digraph.add_edge(5, 7, 1);
    digraph.add_edge(6, 1, 1);
    digraph.add_edge(6, 7, 1);
    digraph.add_edge(7, 8, 1);
    digraph.add_edge(7, 0, 1);
    digraph.add_edge(8, 6, 1);
    digraph.add_edge(8, 4, 1);
    digraph.add_edge(9, 5, 1);

    // Trabalho 2 - Algoritmo de Warshall
    // Warshall W;
    // W.WarshallAlgorithm(digraph);

    // Trabalho 3 - Ordenacao Topologica
    // TopologicalSort path(digraph);
    // path.ExecuteTopologicalSort();
    // path.showTopologicalSort();

    // Trabalho 4 - Componentes Fortemente Conectados (SCC)
    SCC scc(digraph);
    scc.Components();
    return 0;
}