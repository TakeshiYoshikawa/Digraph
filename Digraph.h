#ifndef DIGRAPH_H_
#define DIGRAPH_H_
#include <iostream>
#include <vector>

class Digraph{
	private:
		static const int NULL_EDGE = 0;
		// marks[i] is mark for vertices[i]
		int number_of_vertex;
		int maxVertices;

	public:
		std::vector<Vertex*> vertices;
		std::vector< std::vector<int> > adjacency_matrix;
		
		Digraph(int size){
			number_of_vertex = 0;
			maxVertices = size;

			vertices.resize(size);
			
			// initialize vertices
			for (int i=0;i<size;i++)
				vertices[i] = NULL;

			int rows = size;
			int columns = size;
			adjacency_matrix.resize(rows, std::vector<int>(columns, 0));
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

		void add_vertex(Vertex* vertex){
			vertices[number_of_vertex] = vertex;
			for (int i=0; i<maxVertices; i++){
				adjacency_matrix[number_of_vertex][i] = NULL_EDGE;
				adjacency_matrix[i][number_of_vertex] = NULL_EDGE;
			}
			number_of_vertex++;
		}

		void add_edge(int fromVertex, int toVertex, int weight){
			int row;
			int column;

			row = index_is(vertices[fromVertex]);
			column = index_is(vertices[toVertex]);
			adjacency_matrix[row][column] = weight;
			
			//This line is for undirected graph
			//adjacency_matrix[column][row] = weight;
		}

		int weight_is(int fromVertex, int toVertex){
			int row;
			int column;

			row = index_is(vertices[fromVertex]);
			column = index_is(vertices[toVertex]);
			return adjacency_matrix[row][column];
		}

		int index_is(Vertex* vertex){
			int i = 0;
			while (i < number_of_vertex){
				if (vertices[i] == vertex)
					return i;
				i++;
			}
			return -1;
		}

		void showGraph(){
			std::cout << "   ";
			for(int i = 0; i < number_of_vertex; i++)
				std::cout << vertices[i]->getName() << "   ";
			std::cout << std::endl;

			for(int i = 0; i < number_of_vertex; i++){
				std::cout << vertices[i]->getName() <<  "  ";
				for(int j = 0 ; j < number_of_vertex; j++){
					std::cout << adjacency_matrix[i][j] << "   ";
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

#endif

