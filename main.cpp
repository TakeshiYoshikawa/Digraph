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
    // std::vector<std::string> name = {"short", "calca", "cinto",
    // 					  "jaqueta", "camisa", "gravata",
    // 					  "meia", "sapato", "relogio"};

    std::vector<std::string> name = {"s", "u", "v", "x", "y"};

    // true - Digraph // false - Undirected Digraph
    Digraph digraph(name.size(), true);

    for (int i = 0; i < name.size(); i++) {
        Vertex vertex(name[i], i);
        vertices.push_back(vertex);
        digraph.add_vertex(vertices[i]);
        std::cout << vertices[i].getName() << " -> index "
                  << vertices[i].index() << std::endl;
    }

    digraph.add_edge(0, 1, 10);
    digraph.add_edge(0, 3, 5);
    digraph.add_edge(1, 2, 1);
    digraph.add_edge(1, 3, 2);
    digraph.add_edge(2, 4, 4);
    digraph.add_edge(3, 1, 3);
    digraph.add_edge(3, 2, 9);
    digraph.add_edge(3, 4, 2);
    digraph.add_edge(4, 0, 7);
    digraph.add_edge(4, 2, 6);
    // Trabalho 2 - Algoritmo de Warshall
    // Warshall W;
    // W.WarshallAlgorithm(digraph);

    // Trabalho 3 - Ordenacao Topologica
    // TopologicalSort path(digraph);
    // path.ExecuteTopologicalSort();
    // path.showTopologicalSort();

    // Trabalho 4 - Componentes Fortemente Conectados (SCC)
    // SCC scc(digraph);
    // scc.Components();

    // Trabalho 5 - Definir o menor caminho e a rota resultante por Dijkstra.
    Dijkstra dijkstra(digraph);
    dijkstra.shortestPath(0);
    return 0;
}