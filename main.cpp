#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "Vertex.h"
#include "Digraph.h"
#include "DFS.h"
#include "Warshall.h"

int main(int argc, char *argv[]){
	int size = 5;
	Digraph* G = new Digraph(size);
	
	for(int i = 0; i < size; i++){
		Vertex* pVertex = new Vertex(i);
		G->add_vertex(pVertex);
	}

	G->add_edge(0,1,1);
	G->add_edge(1,2,1);
	G->add_edge(2,0,1);
	G->add_edge(2,3,1);
	G->add_edge(4,0,1);
	G->add_edge(4,2,1);

//	Warshall* W = new Warshall(G);	
//	W->WarshallAlgorithm();	
//	G->showGraph();

	DFS* dfs = new DFS(G, 0);

	std::cout << std::endl;
	
	G->showGraph();
//	delete G; delete W; delete dfs;
	return 0;
}