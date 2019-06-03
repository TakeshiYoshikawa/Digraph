#ifndef DIGRAPH_H_
#define DIGRAPH_H_
#include <algorithm>
#include <iostream>
#include <vector>
#include "Vertex.h"

class Digraph {
   private:
    static const int NULL_EDGE = 0;
    int number_of_vertex;
    int maxVertices;
    bool isDigraph;

   public:
    std::vector<Vertex> vertices;
    std::vector<std::vector<int> > edge;
    std::vector<std::vector<int> > weight;

    Digraph(int size, bool graph_type) : vertices(size, Vertex("", 0)) {
        number_of_vertex = 0;
        maxVertices = size;
        isDigraph = graph_type;

        int rows = size;
        int columns = size;

        edge.resize(rows, std::vector<int>(columns, 0));
        weight.resize(rows, std::vector<int>(columns, 0));
    }

    void Transpose() {
        for (int i = 0; i < number_of_vertex; i++) {
            for (int j = 0; j < number_of_vertex; j++) {
                if (i < j)
                    std::swap(edge[i][j], edge[j][i]);
            }
        }
    }

    void add_vertex(Vertex vertex) {
        vertices[number_of_vertex] = vertex;
        for (int i = 0; i < maxVertices; i++) {
            edge[number_of_vertex][i] = NULL_EDGE;
            edge[i][number_of_vertex] = NULL_EDGE;
        }
        number_of_vertex++;
    }

    void add_edge(int fromVertex, int toVertex, int weight) {
        int row;
        int column;

        row = get_index_of(vertices[fromVertex]);
        column = get_index_of(vertices[toVertex]);

        edge[row][column] = 1;
        this->weight[row][column] = weight;

        if (isDigraph) {
            if (edge[row][column] != 0)
                vertices[column].add_in_degree();
            if (edge[row][column] != 0)
                vertices[row].add_out_degree();
        }

        // Form to determine in and out degree on a digraph.
        if (!isDigraph) {
            edge[column][row] = 1;
            this->weight[column][row] = weight;
            vertices[row].add_undirected_degree();
            vertices[column].add_undirected_degree();
        }
    }

    void showGraph() {
        std::cout << "   ";
        for (int i = 0; i < number_of_vertex; i++)
            std::cout << vertices[i].getName() << "   ";
        std::cout << std::endl;

        for (int i = 0; i < number_of_vertex; i++) {
            std::cout << vertices[i].getName() << "  ";
            for (int j = 0; j < number_of_vertex; j++) {
                std::cout << edge[i][j] << "   ";
            }
            std::cout << std::endl;
        }
    }

    int get_index_of(Vertex vertex) {
        int i = 0;
        while (i < number_of_vertex) {
            if (vertices[i].index() == vertex.index()) return i;
            i++;
        }
        return -1;
    }

    int Size() { return this->number_of_vertex; }

    bool is_empty() {
        if (number_of_vertex == 0)
            return true;
        else
            return false;
    }

    bool is_full() {
        if (number_of_vertex == maxVertices)
            return true;
        else
            return false;
    }

    int weightBetween(int fromVertex, int toVertex) {
        int row;
        int column;

        row = get_index_of(vertices[fromVertex]);
        column = get_index_of(vertices[toVertex]);
        return weight[row][column];
    }
};

#endif