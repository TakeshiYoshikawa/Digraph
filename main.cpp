//============================================================================
// Name        : AdjacencyMatrixGraphImp.cpp
// Author      : Amritpal Singh
// Copyright   : arrayed.net
// Description : Array based Adjacency Matrix Graph Implimentation
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <queue>

class vertex{
	private:
		int name;
	public:
		vertex(int name){
			this->name = name;
		}

		int getName(){
			return this->name;
		}
};

class Digraph{
	private:
		static const int NULL_EDGE = 0;
		std::vector<vertex*> vertices;
		// marks[i] is mark for vertices[i]
		int number_of_vertex;
		int maxVertices;

	public:
		std::vector< std::vector<int> > edges;
		
		Digraph(int size){
			number_of_vertex = 0;
			maxVertices = size;

			vertices.resize(size);
			
			// initialize vertices
			for (int i=0;i<size;i++)
				vertices[i] = NULL;

			int rows = size;
			int columns = size;
			edges.resize(rows, std::vector<int>(columns, 0));
		}
		
		int getNumberOfVertex(){
			return this->number_of_vertex;
		}
		
		bool is_empty(){
			if (number_of_vertex == 0)
				return true;
			else
				return false;
		}

		bool is_full(){
			if (number_of_vertex == maxVertices)
				return true;
			else
				return false;
		}

		void add_vertex(vertex* Vertex){
			vertices[number_of_vertex] = Vertex;
			for (int i=0; i<maxVertices; i++){
				edges[number_of_vertex][i] = NULL_EDGE;
				edges[i][number_of_vertex] = NULL_EDGE;
			}
			number_of_vertex++;
		}

		void add_edge(int fromVertex, int toVertex, int weight){
			int row;
			int column;

			row = index_is(vertices[fromVertex]);
			column = index_is(vertices[toVertex]);
			edges[row][column] = weight;
		}

		int weight_is(int fromVertex, int toVertex){
			int row;
			int column;

			row = index_is(vertices[fromVertex]);
			column = index_is(vertices[toVertex]);
			return edges[row][column];
		}

		int index_is(vertex* Vertex){
			int i = 0;
			while (i < number_of_vertex){
				if (vertices[i] == Vertex)
					return i;
				i++;
			}
			return -1;
		}

		void showGraph(){
			std::cout << "   ";
			for(int i = 0; i < number_of_vertex; i++)
				std::cout << i << "   ";
			std::cout << std::endl;

			for(int i = 0; i < number_of_vertex; i++){
				std::cout << i <<  "  ";
				for(int j = 0 ; j < number_of_vertex; j++){
					std::cout << edges[i][j] << "   ";
				}
				std::cout << std::endl;
			}
		}
		
		~Digraph(){
			for (int i=0;i<number_of_vertex;i++){
				delete vertices[i];
			}
		}
};

class Warshall{
	private:
		Digraph* G;
		int dimension;
	public:
		Warshall(Digraph* graph){
			this->G = graph;
			this->dimension = G->getNumberOfVertex();
		}
		
		void WarshallAlgorithm(){
			for(int k = 0; k < dimension; k++){
				for(int i = 0; i < dimension; i++){
					for(int j = 0; j < dimension; j++){
						G->edges[i][j] = (G->edges[i][j] || (G->edges[i][k] && G->edges[k][j]));
					}
				}
			}
		}
};

int main(){
	int size = 4;
	Digraph* G = new Digraph(size);
	
	for(int i = 0; i < size; i++){
		vertex* pVertex = new vertex(i);
		G->add_vertex(pVertex);
	}
	G->add_edge(1,0,1);
	G->add_edge(0,1,1);
	G->add_edge(1,2,1);
	G->add_edge(2,3,1);
	
	Warshall* W = new Warshall(G);
	W->WarshallAlgorithm();	
	G->showGraph();
	return 0;
}
