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
using namespace std;

class vertex{
	private:
		string name;
	public:
		vertex(string name){
			this->name = name;
		}

		string getName(){
			return this->name;
		}
};

class Digraph{
	private:
		static const int NULL_EDGE = 0;
		vector<vertex*> vertices;
		// marks[i] is mark for vertices[i]
		int number_of_vertex;
		int maxVertices;
		vector< vector<int> > edges;

	public:
		Digraph(int size){
			number_of_vertex = 0;
			maxVertices = size;

			vertices.resize(size);
			
			// initialize vertices
			for (int i=0;i<size;i++)
				vertices[i] = NULL;

			int rows = size;
			int columns = size;
			edges.resize(rows, vector<int>(columns, 0));
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
			cout << "   ";
			for(int i = 0; i < number_of_vertex; i++)
				cout << i << "   ";
			cout << endl;

			for(int i = 0; i < number_of_vertex; i++){
				cout << i <<  "  ";
				for(int j = 0 ; j < number_of_vertex; j++){
					cout << edges[i][j] << "   ";
				}
				cout << endl;
			}
		}
		
		~Digraph(){
			for (int i=0;i<number_of_vertex;i++){
				delete vertices[i];
			}
		}
};

int main(){
	Digraph G(10);
	vertex* root = new vertex("A");;
	G.add_vertex(root);
	
	vertex* pVertex;
	pVertex = new vertex("B");
	G.add_vertex(pVertex);
	pVertex = new vertex("C");
	G.add_vertex(pVertex);
	pVertex = new vertex("D");
	G.add_vertex(pVertex);
	pVertex = new vertex("E");
	G.add_vertex(pVertex);

	// Add edges into memory
	G.add_edge(0,1,1);
	G.add_edge(0,2,1);
	G.add_edge(1,3,1);
	G.add_edge(2,4,1);
	G.add_edge(3,2,1);
	G.add_edge(4,3,1);
	G.add_edge(4,0,1);
	G.add_edge(4,1,1);

	G.showGraph();
	return 0;
}
