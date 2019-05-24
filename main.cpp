#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "Vertex.h"
#include "Digraph.h"
#include "DFS.h"
#include "Warshall.h"

int main(int argc, char *argv[]){
	Digraph* G = new Digraph(6);
	Vertex* a = new Vertex("a",0);
	Vertex* b = new Vertex("b",1);
	Vertex* c = new Vertex("c",2);
	Vertex* d = new Vertex("d",3);
	Vertex* e = new Vertex("e",4);
	Vertex* f = new Vertex("f",5);
	G->add_vertex(a);
	G->add_vertex(b);
	G->add_vertex(c);
	G->add_vertex(d);
	G->add_vertex(e);
	G->add_vertex(f);

	G->add_edge(0,1,1);
	G->add_edge(0,2,1);
	G->add_edge(0,0,1);
	G->add_edge(0,3,1);
	G->add_edge(0,4,1);
	G->add_edge(0,5,1);
	G->add_edge(1,2,1);
	G->add_edge(2,0,1);
	G->add_edge(3,5,1);
	G->add_edge(2,3,1);
	G->add_edge(4,2,1);
	G->add_edge(3,2,1);
	G->add_edge(5,4,1);
	G->add_edge(5,1,1);
	G->add_edge(5,5,1);

	//Warshall* W = new Warshall(G);	
	//W->WarshallAlgorithm();	

	std::cout << std::endl;
	
	G->showGraph();

	std::cout << std::endl << "DFS path: " << std::endl;
	DFS* dfs = new DFS(G, 0);
	
	std::cout << std::endl << std::endl;

	std::cout << "Out degree: " << f->get_out_degree() << std::endl;
	std::cout << "In degree: " << f->get_in_degree();
	
	delete G; delete dfs;
	return 0;
}