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
	int size = 4;
	std::vector<Vertex *> vertexes;
	std::string name[] = {"0","1","2","3"};

	//true - Undirected Graph
	//false - Digraph
	Digraph digraph(size, false);

	for (int i = 0; i < size; i++)
	{
		Vertex *vertex = new Vertex(name[i], i);
		vertexes.push_back(vertex);
		digraph.add_vertex(vertexes[i]);
	}

	digraph.add_edge(0, 3, 1);
	digraph.add_edge(1, 0, 1);
	digraph.add_edge(1, 2, 1);
	digraph.add_edge(2, 0, 1);
	digraph.add_edge(2, 3, 1);
	digraph.add_edge(3, 2, 1);
	
	digraph.showGraph();
	
	//Trabalho 2 - Algoritmo de Warshall
	Warshall W;
	W.WarshallAlgorithm(digraph);
	
	//DFS dfs(&digraph);
	//dfs.init_DFS(0);

	//Trabalho 3 - Ordenacao Topologica
	// TopologicalSort TS(digraph);
	// TS.ExecuteTopologicalSort();
	// TS.showTopologicalSort();
	return 0;
}