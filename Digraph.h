#ifndef DIGRAPH_H_
#define DIGRAPH_H_
#include <iostream>
#include <vector>
#include "Vertex.h"

class Digraph
{
private:
	static const int NULL_EDGE = 0;
	int number_of_vertex;
	int maxVertices;
	bool isUndirected;
public:
	std::vector<Vertex> vertices;
	std::vector<std::vector<int> > adjacency_matrix;
	
	Digraph(int size, bool graph_type)
		: vertices(size, Vertex("", 0))
	{
		number_of_vertex = 0;
		maxVertices = size;
		isUndirected = graph_type;
		
		for(int i = 0; i < size; i++)
		{
			Vertex vertex("",i);
			vertices.push_back(vertex);
		}

		//vertices.resize(size);
		int rows = size;
		int columns = size;
		adjacency_matrix.resize(rows, std::vector<int>(columns, 0));		
	}

	void add_vertex(Vertex vertex)
	{
		vertices[number_of_vertex] = vertex;
		for (int i = 0; i < maxVertices; i++)
		{
			adjacency_matrix[number_of_vertex][i] = NULL_EDGE;
			adjacency_matrix[i][number_of_vertex] = NULL_EDGE;
		}
		number_of_vertex++;
	}

	void showGraph()
	{
		std::cout << "   ";
		for (int i = 0; i < number_of_vertex; i++)
			std::cout << vertices[i].getName() << "   ";
		std::cout << std::endl;

		for (int i = 0; i < number_of_vertex; i++)
		{
			std::cout << vertices[i].getName() << "  ";
			for (int j = 0; j < number_of_vertex; j++)
			{
				std::cout << adjacency_matrix[i][j] << "   ";
			}
			std::cout << std::endl;
		}
	}
	
	void add_edge(int fromVertex, int toVertex, int weight)
	{
		int row;
		int column;

		row = get_index_of(vertices[fromVertex]);
		column = get_index_of(vertices[toVertex]);

		adjacency_matrix[row][column] = weight;

		if (isUndirected)
		{
			adjacency_matrix[column][row] = weight;
			vertices[row].add_undirected_degree();
			vertices[column].add_undirected_degree();
		}

		//Form to determine in and out degree on a digraph.
		if (!isUndirected)
		{
			if (adjacency_matrix[row][column] != 0)
				vertices[column].add_in_degree();
			if (adjacency_matrix[row][column] != 0)
				vertices[row].add_out_degree();
		}
	}
	
	int get_index_of(Vertex vertex)
	{
		int i = 0;
		while (i < number_of_vertex)
		{
			if (vertices[i].getValue() == vertex.getValue())
				return i;
			i++;
		}
		return -1;
	}
	
	int getNumberOfVertex()
	{
		return this->number_of_vertex;
	}

	bool is_empty()
	{
		if (number_of_vertex == 0)
			return true;
		else
			return false;
	}

	bool is_full()
	{
		if (number_of_vertex == maxVertices)
			return true;
		else
			return false;
	}

	int weight_is(int fromVertex, int toVertex)
	{
		int row;
		int column;

		row = get_index_of(vertices[fromVertex]);
		column = get_index_of(vertices[toVertex]);
		return adjacency_matrix[row][column];
	}
};

#endif