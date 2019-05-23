#ifndef VERTEX_H_
#define VERTEX_H_
#include <iostream>
#include <string>

class Vertex{
	private:
		int value;
		std::string name;
	public:
		Vertex(std::string name, int value){
			this->name = name;
			this->value = value;
		}

		int getValue(){
			return this->value;
		}

		std::string getName(){
			return this->name;
		}
};

#endif