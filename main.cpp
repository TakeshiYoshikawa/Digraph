#include <iostream>
#include "src/Menu.h"

int main(int argc, char *argv[]) {
    int option;
    int algorithm_option;
    std::vector<Vertex> vertices;

    std::cout << "Grafo pré-definido no código fonte" << std::endl;

    // Altere o vetor de nomes, alguns exemplos disponíveis para teste imediato.
    std::vector<std::string> name = {"a","b","c","d","e","f"};


    Digraph digraph(name.size(), true);
    for (int i = 0; i < name.size(); i++) {
        Vertex vertex(name[i], i);
        vertices.push_back(vertex);
        digraph.add_vertex(vertices[i]);
        std::cout << vertices[i].getName() << " -> index "
                  << vertices[i].index() << std::endl;
    }

    /*
    Definição das arestas, alguns arquivos de exemplo na pasta graph_example
    já possuem exemplos prontos.
    */
    digraph.add_edge(0,3,1);
    digraph.add_edge(0,2,1);
    digraph.add_edge(1,0,1);
    digraph.add_edge(1,2,1);
    digraph.add_edge(2,4,1);
    digraph.add_edge(3,0,1);
    digraph.add_edge(3,5,1);
    digraph.add_edge(4,1,1);
    digraph.add_edge(5,5,1);

    digraph.showGraph();

    while (1) {
        std::cout << "\nEscolha uma opção: " << std::endl;
        std::cout << "1 - Definir um grafo e escolher as operações."
                  << std::endl;
        std::cout << "2 - Utilizar o grafo pré-definido e escolher somente as "
                     "operações."
                  << std::endl;
        std::cout << "Digite a opção: ";
        std::cin >> option;

        switch (option) {
            case (1):
                Menu::Opcao::main();
                break;

            case (2):
                std::cout << "Opção de grafo pré-definido selecionado."
                          << std::endl;
                while (1) {
                    std::cout << "Selecione um algoritmo." << std::endl;
                    std::cout
                        << "1 - Warshall\n2 - Ordenação Topológica\n3 - "
                           "Componentes Fortemente Conectados\n4 - Menor "
                           "caminho (Dijkstra)\n5 - Mostrar grafo\n6 - Encerrar"
                        << std::endl;

                    std::cout << "Escolha o algoritmo: ";
                    std::cin >> algorithm_option;
                    if (algorithm_option == 1) {
                        Warshall W;
                        W.WarshallAlgorithm(digraph);
                    } else if (algorithm_option == 2) {
                        TopologicalSort path(digraph);
                        path.ExecuteTopologicalSort();
                    } else if (algorithm_option == 3) {
                        SCC scc(digraph);
                        scc.Components();
                        scc.showComponents();
                    } else if (algorithm_option == 4) {
                        Dijkstra dijkstra(digraph);
                        dijkstra.shortestPath(0);
                    } else if (algorithm_option == 5) {
                        digraph.showGraph();
                    } else if (algorithm_option == 6) {
                        break;
                    }
                }
        }
    }
    return 0;
}