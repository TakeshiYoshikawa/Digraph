#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "Vertex.h"
#include "Digraph.h"
#include "DFS.h"
#include "Warshall.h"

int main(int argc, char *argv[]){
	int size = 9;
	int option = 0;
	std::vector<Vertex*> vertexes;
	std::string name[] = {"short","meia","calca","sapato","cinto","camisa","gravata","jaqueta","relogio"};
	Digraph *digraph;

	//true - Undirected Graph
	//false - Digraph
	digraph = new Digraph(size, false);

	for (int i = 0; i < size; i++){
		Vertex *vertex = new Vertex(name[i], i);
		vertexes.push_back(vertex);
		digraph->add_vertex(vertexes[i]);
	}

	digraph->add_edge(0,3,1);
	digraph->add_edge(0,2,1);
	digraph->add_edge(1,3,1);
	digraph->add_edge(2,4,1);
	digraph->add_edge(2,3,1);
	digraph->add_edge(4,7,1);
	digraph->add_edge(5,4,1);
	digraph->add_edge(5,6,1);
	digraph->add_edge(6,7,1);

	/*
	//Trabalho 2 - Algoritmo de Warshall
	Warshall* W = new Warshall(digraph);
	W->WarshallAlgorithm();	
	*/

	//Trabalho 3 - Ordenacao Topologica
	std::cout << "DFS path: " << std::endl;
	DFS* dfs = new DFS(digraph, 0);
	std::cout << "\nTopological Sort: " << std::endl;
	delete dfs;
	digraph->showGraph();
	delete digraph;

	return 0;
}