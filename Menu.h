#ifndef MENU_H_
#define MENU_H_
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

namespace Menu {
class Opcao {
   private:
   public:
    static void main() {
        std::vector<Vertex> vertices;
        std::vector<std::string> name;
        std::string vertex_name;

        std::cout << "Escreva o nome dos vertices do grafo no formato de "
                     "string, a quantidade sera definida pelo numero de "
                     "declaracoes. Para encerrar digite -1."
                  << std::endl;

        while (1) {
            std::cin >> vertex_name;
            if (vertex_name == "-1") {
                break;
            }
            name.push_back(vertex_name);
        }

        std::cout << "Digite o tipo de grafo:" << std::endl
                  << "1 - Direcionado (Digrafo)." << std::endl
                  << "0 - Nao direcionado." << std::endl;

        int graph_type;
        bool key;
        std::cin >> graph_type;

        if (graph_type == 1) {
            key = true;
        } else {
            key = false;
        }

        Digraph graph(name.size(), key);

        std::cout << "Legenda dos vertices declarados em indices numericos."
                  << std::endl;
        for (int i = 0; i < name.size(); i++) {
            Vertex vertex(name[i], i);
            vertices.push_back(vertex);
            graph.add_vertex(vertices[i]);
            std::cout << vertices[i].getName() << " -> index "
                      << vertices[i].index() << std::endl;
        }

        std::cout
            << "Insira tres indices para definir as arestas do grafo e o peso "
               "da aresta, por exemplo: 0  1  15. Para encerrar digite -1 -1 -1"
            << std::endl;
        int fromVertex;
        int toVertex;
        int weight;
        while (1) {
            std::cout << "Vertice de origem:" << std::endl;
            std::cin >> fromVertex; 
            std::cout << "Vertice de destino:" << std::endl;
            std::cin >> toVertex; 
            std::cout << "Peso:" << std::endl;
            std::cin >> weight;
            std::cin.ignore(512, '\n');
            if ((fromVertex == -1) && (toVertex == -1) && (weight == -1)) {
                break;
            }
            
            if ((fromVertex > name.size()) || (toVertex > name.size())) {
                std::cout
                    << "Indice ultrapassando o limite do grafo. Abortagem"
                    << std::endl;
                break;
            }
            graph.add_edge(fromVertex, toVertex, weight);
        }
        graph.showGraph();
    }
};
}  // namespace Menu

#endif