#ifndef VERTEX_H_
#define VERTEX_H_
#include <iostream>
#include <string>

class Vertex
{
private:
	int value;
	int in_degree;
	int out_degree;
	int undirected_degree;
	std::string name;

public:
	Vertex(std::string name, int value)
	{
		this->name = name;
		this->value = value;
		this->undirected_degree = 0;
		this->in_degree = 0;
		this->out_degree = 0;
	}

	int getValue()
	{
		return this->value;
	}

	std::string getName()
	{
		return this->name;
	}

	void add_in_degree()
	{
		this->in_degree++;
	}

	void add_out_degree()
	{
		this->out_degree++;
	}

	int get_in_degree()
	{
		return this->in_degree;
	}

	int get_out_degree()
	{
		return this->out_degree;
	}

	void add_undirected_degree()
	{
		this->undirected_degree++;
	}

	int get_undirected_degree()
	{
		return this->undirected_degree;
	}
};

#endif