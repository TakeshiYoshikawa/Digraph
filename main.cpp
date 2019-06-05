#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include "DFS.h"
#include "Digraph.h"
#include "Dijkstra.h"
#include "SCC.h"
#include "TopologicalSort.h"
#include "Vertex.h"
#include "Warshall.h"

int main(int argc, char *argv[]) {
    std::vector<Vertex> vertices;

    std::vector<std::string> name = {"1", "2", "3", "4", "5",
                                     "6", "7", "8", "9"};
    // true - Digraph
    // false - Undirected Digraph
    Digraph digraph(name.size(), true);

    for (int i = 0; i < name.size(); i++) {
        Vertex vertex(name[i], i);
        vertices.push_back(vertex);
        digraph.add_vertex(vertices[i]);
        std::cout << vertices[i].getName() << " -> index "
                  << vertices[i].index() << std::endl;
    }

    digraph.add_edge(0, 1, 1);
    digraph.add_edge(1, 3, 1);
    digraph.add_edge(2, 7, 1);
    digraph.add_edge(3, 4, 1);
    digraph.add_edge(4, 1, 1);
    digraph.add_edge(5, 2, 1);
    digraph.add_edge(5, 8, 1);
    digraph.add_edge(6, 1, 1);
    digraph.add_edge(6, 5, 1);
    digraph.add_edge(7, 2, 1);
    digraph.add_edge(8, 5, 1);

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
    scc.showComponents();

    // Trabalho 5 - Definir o menor caminho e a rota resultante por Dijkstra.
    // Dijkstra dijkstra(digraph);
    // dijkstra.shortestPath(0);

    return 0;
}