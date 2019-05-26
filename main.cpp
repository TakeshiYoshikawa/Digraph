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
	int option = 0;
	std::vector<Vertex*> vertexes;
	Digraph* digraph;
	Graph* graph;
	
	while(1){
		std::cout << "Graph size: " << std::endl;
		//std::cin >> size;
		std::cout << "0 - Digraph\n1 - Undirected Graph" << std::endl;
		//std::cin >> option;
		
		if(option == 0){
			digraph = new Digraph(size);
		}
		else{
			graph = new Graph(size);
		}

		std::cout << "Input " << size << " vertexes";
		for(int i = 0; i < size; i++){
			Vertex* vertex = new Vertex(" ",i);
			vertexes.push_back(vertex);
			if(option == 0)
				digraph->add_vertex(vertexes[i]);
			else
				graph->add_vertex(vertexes[i]);
		}
		digraph->showGraph();
		break;
	}
	/*
	Digraph* digraph = new Digraph(6);
	Vertex* a = new Vertex("a",0);
	Vertex* b = new Vertex("b",1);
	Vertex* c = new Vertex("c",2);
	Vertex* d = new Vertex("d",3);
	Vertex* e = new Vertex("e",4);
	Vertex* f = new Vertex("f",5);
	digraph->add_vertex(a);
	digraph->add_vertex(b);
	digraph->add_vertex(c);
	digraph->add_vertex(d);
	digraph->add_vertex(e);
	digraph->add_vertex(f);

	digraph->add_edge(0,0,1);
	digraph->add_edge(0,4,1);
	digraph->add_edge(1,2,1);
	digraph->add_edge(3,5,1);
	digraph->add_edge(2,3,1);
	digraph->add_edge(5,4,1);
	digraph->add_edge(5,1,1);
	digraph->add_edge(2,4,1);
	
	delete digraph;
	Graph *graph = new Graph(6);
	graph->add_vertex(a);
	graph->add_vertex(b);
	graph->add_vertex(c);
	graph->add_edge(0,1,1);
	graph->add_edge(0,2,1);
	graph->showGraph();
	delete graph;
	*/
	/*
	//Warshall* W = new Warshall(digraph);
	//W->WarshallAlgorithm();	

	std::cout << std::endl;
	
	digraph->showGraph();

	std::cout << std::endl << "DFS path: " << std::endl;
	DFS* dfs = new DFS(digraph, 0);
	
	std::cout << std::endl << std::endl;

	std::cout << "Out degree: " << a->get_out_degree() << std::endl;
	std::cout << "In degree: " << a->get_in_degree() << std::endl << std::endl;
	
	std::cout << "Topological Sort: ";
	delete digraph; delete dfs;
	*/
	return 0;
}