#include <iostream>
#include "Menu.h"

int main(int argc, char *argv[]) {
    Menu::Opcao::main();
    
    // Estrutura sem formato de menu.
    // std::vector<Vertex> vertices;

    // std::vector<std::string> name = {"short","meia","calca","sapato","cinto","camisa","gravata","jaqueta","relogio"};
    // true - Digraph
    // false - Undirected Digraph
    // Digraph digraph(name.size(), true);

    // for (int i = 0; i < name.size(); i++) {
    //     Vertex vertex(name[i], i);
    //     vertices.push_back(vertex);
    //     digraph.add_vertex(vertices[i]);
    //     std::cout << vertices[i].getName() << " -> index "
    //               << vertices[i].index() << std::endl;
    // }

    // digraph.add_edge(0,2,1);
    // digraph.add_edge(0,3,1);
    // digraph.add_edge(1,3,1);    
    // digraph.add_edge(2,3,1);
    // digraph.add_edge(2,4,1);
    // digraph.add_edge(4,7,1);
    // digraph.add_edge(5,4,1);
    // digraph.add_edge(5,6,1);
    // digraph.add_edge(6,7,1);

    // // Trabalho 2 - Algoritmo de Warshall
    // // Warshall W;
    // // W.WarshallAlgorithm(digraph);

    // // Trabalho 3 - Ordenacao Topologica
    // TopologicalSort path(digraph);
    // path.ExecuteTopologicalSort();
    // path.showTopologicalSort();

    // // Trabalho 4 - Componentes Fortemente Conectados (SCC)
    // SCC scc(digraph);
    // scc.Components();
    // scc.showComponents();

    // // Trabalho 5 - Definir o menor caminho e a rota resultante por Dijkstra.
    // // Dijkstra dijkstra(digraph);
    // // dijkstra.shortestPath(0);

    return 0;
}