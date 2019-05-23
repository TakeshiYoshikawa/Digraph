#ifndef VERTEX_H_
#define VERTEX_H_
#include <iostream>
#include <string>

class Vertex{
	private:
		int name;
	public:
		Vertex(int name){
			this->name = name;
		}

		int getName(){
			return this->name;
		}
};

#endif