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

std::vector<std::string> name = {"0","1","2","3","4","5","6","7","8","9"};

    // true - Digraph // false - Undirected Digraph
    Digraph digraph(name.size(), true);

    for (int i = 0; i < name.size(); i++) {
        Vertex vertex(name[i], i);
        vertices.push_back(vertex);
        digraph.add_vertex(vertices[i]);
        std::cout << vertices[i].getName() << " -> index "
                  << vertices[i].index() << std::endl;
    }

    digraph.add_edge(0, 5, 1);
    digraph.add_edge(0, 6, 1);
    digraph.add_edge(1, 4, 1);
    digraph.add_edge(2, 6, 1);
    digraph.add_edge(2, 9, 1);
    digraph.add_edge(3, 7, 1);
    digraph.add_edge(3, 8, 1);
    digraph.add_edge(4, 9, 1);
    digraph.add_edge(5, 2, 1);
    digraph.add_edge(6, 4, 1);
    digraph.add_edge(7, 8, 1);
    digraph.showGraph();
    
    // Trabalho 2 - Algoritmo de Warshall
    Warshall W;
    W.WarshallAlgorithm(digraph);

    // Trabalho 3 - Ordenacao Topologica
    TopologicalSort path(digraph);
    path.ExecuteTopologicalSort();
    path.showTopologicalSort();

    // Trabalho 4 - Componentes Fortemente Conectados (SCC)
    SCC scc(digraph);
    scc.Components();

    // Trabalho 5 - Definir o menor caminho e a rota resultante por Dijkstra.
    Dijkstra dijkstra(digraph);
    dijkstra.shortestPath(0);

    return 0;
}