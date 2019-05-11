#include <iostream>
#include <cmath>
#include <vector>

void foo(){
	std::vector<std::vector<int> > A((1,0), std::vector<int>(1));
	
	A.resize(15,std::vector<int>(20));
	
	for(int i = 0; i < A.size(); i++){
		for(int j = 0; j < A[1].size(); j++){		
			std::cout << "[" << A[i][j] << "]";
		}
		std::cout << std::endl;
	}

}

template <class T>
class Vertex{
	private:
		T name;
	public:
		Vertex(T name){
			this->name = name;
		}
		
		T getName(){
			return this->name;
		}
};

class Edge{
	private:
		int v1, v2, weight;
	public:
};

template <class T>
class Digraph{
	private:
		int number_of_vertex;
		std::vector<std::vector<int> > adjacency_matrix;
	public:
		Digraph(int size){
			this->number_of_vertex = size;
			adjacency_matrix.resize(size,std::vector<int>(size));
		}

		void add_edge(T fromVertex, T toVertex){
			adjacency_matrix[fromVertex][toVertex] = 1;
		}
		
		void showGraph(){
			std::cout << "   ";
			for(int i = 0; i < number_of_vertex; i++)
				std::cout << i << "   ";
			std::cout << std::endl;

			for(int i = 0; i < number_of_vertex; i++){
				std::cout << i <<  "  ";
				for(int j = 0 ; j < number_of_vertex; j++){
					std::cout << adjacency_matrix[i][j] << "   ";
				}
				std::cout << std::endl;
			}
		}
		
		int get_OutDegree(int vertex){
			int out_degree_count = 0;
			for(int j = 0; j < this->number_of_vertex; j++){
				if(adjacency_matrix[vertex][j] == 1)
					out_degree_count++;
			}
			return out_degree_count;
		}
		
		int get_InDegree(int vertex){
			int in_degree_count = 0;
			for(int i = 0; i < this->number_of_vertex; i++){
				if(adjacency_matrix[i][vertex] == 1)
					in_degree_count++;
			}
			return in_degree_count;
		}
};

int main(){
	Digraph <int>G(7);
	G.add_edge(0,1);
	G.add_edge(0,2);
	G.add_edge(0,3);
	G.add_edge(0,4);
	G.add_edge(2,3);
	G.add_edge(3,3);
	G.add_edge(4,3);
	G.add_edge(5,0);
	G.add_edge(1,0);
	G.add_edge(2,0);
	G.add_edge(6,0);
	G.showGraph();
	
	for(int i = 0; i < 7; i++){	
		std::cout << "\nIn degree of " << i << " is " << G.get_InDegree(i);
		std::cout << "\nOut degree of " << i << " is " << G.get_OutDegree(i) << std::endl;
	}

}
