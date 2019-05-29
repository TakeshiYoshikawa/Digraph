#ifndef WARSHALL_H_
#define WARSHALL_H_
#include <iostream>

class Warshall
{
public:
	void WarshallAlgorithm(Digraph graph)
	{
		for (int k = 0; k < graph.getNumberOfVertex(); k++)
		{
			for (int i = 0; i < graph.getNumberOfVertex(); i++)
			{
				for (int j = 0; j < graph.getNumberOfVertex(); j++)
				{
					graph.adjacency_matrix[i][j] = (graph.adjacency_matrix[i][j] || (graph.adjacency_matrix[i][k] && graph.adjacency_matrix[k][j]));
				}
			}
		}

		std::cout << "   ";
		for (int i = 0; i < graph.getNumberOfVertex(); i++)
			std::cout << graph.vertexes[i]->getName() << "   ";
		std::cout << std::endl;

		for (int i = 0; i < graph.getNumberOfVertex(); i++)
		{
			std::cout << graph.vertexes[i]->getName() << "  ";
			for (int j = 0; j < graph.getNumberOfVertex(); j++)
			{
				std::cout << graph.adjacency_matrix[i][j] << "   ";
			}
			std::cout << std::endl;
		}
	}
};

#endif