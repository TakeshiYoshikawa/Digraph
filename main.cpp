#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "Vertex.h"
#include "Digraph.h"
#include "DFS.h"
#include "Warshall.h"
#include "TopologicalSort.h"

int main(int argc, char *argv[])
{
	int size = 9;
	std::vector<Vertex> vertices;
	std::string name[] = {"short", "calca", "cinto", 
						  "jaqueta", "camisa", "gravata", 
						  "meia", "sapato", "relogio"};
	
	
	//true - Undirected Graph // false - Digraph
	Digraph digraph(size, false);

	for (int i = 0; i < size; i++)
	{ 
		Vertex vertex(name[i], i);
		vertices.push_back(vertex);
		digraph.add_vertex(vertices[i]);
		std::cout << vertices[i].getValue() << "-> " << vertices[i].getName() << std::endl;
	}

	digraph.add_edge(0, 1, 1);
	digraph.add_edge(1, 2, 1);
	digraph.add_edge(1, 7, 1);
	digraph.add_edge(2, 3, 1);
	digraph.add_edge(4, 2, 1);
	digraph.add_edge(4, 5, 1);
	digraph.add_edge(5, 3, 1);
	digraph.add_edge(6, 7, 1);

	//Trabalho 2 - Algoritmo de Warshall
	//Warshall W;
	//W.WarshallAlgorithm(digraph);

	//Trabalho 3 - Ordenacao Topologica
	TopologicalSort path(digraph);
	path.ExecuteTopologicalSort();
	path.showTopologicalSort();
	
	return 0;
}