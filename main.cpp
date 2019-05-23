#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "Vertex.h"
#include "Digraph.h"
#include "DFS.h"
#include "Warshall.h"

int main(int argc, char *argv[]){
	Digraph* G = new Digraph(5);
	Vertex* a = new Vertex("a",0);
	Vertex* b = new Vertex("b",1);
	Vertex* c = new Vertex("c",2);
	Vertex* d = new Vertex("d",3);
	Vertex* e = new Vertex("e",4);
	G->add_vertex(a);
	G->add_vertex(b);
	G->add_vertex(c);
	G->add_vertex(d);
	G->add_vertex(e);

	G->add_edge(0,1,1);
	G->add_edge(1,2,1);
	G->add_edge(2,0,1);
	G->add_edge(2,3,1);
	G->add_edge(4,0,1);
	G->add_edge(4,2,1);
	
	Warshall* W = new Warshall(G);	
	W->WarshallAlgorithm();	

	std::cout << std::endl;
	
	G->showGraph();

	std::cout << std::endl << "DFS path: " << std::endl;
	DFS* dfs = new DFS(G, 0);
	
	delete G; delete dfs;
	return 0;
}