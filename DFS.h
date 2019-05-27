#ifndef DFS_H_
#define DFS_H_
#include <vector>
#include <algorithm>
#include "Vertex.h"
#include "Digraph.h"

class DFS{
    private:
        int time;
        int dim;
        enum Color{white, gray, black};
        Digraph* digraph;
        std::vector<Color> color;
        std::vector<int> found; 
        std::vector<int> finalized;
        std::vector<int> predecessor;
        std::vector<std::string> terminados;
    
    public:
        DFS(Digraph* D, int start_vertex){
            this->digraph = D;
            this->dim = digraph->getNumberOfVertex();
            this->time = 0;
            
            color.assign(digraph->getNumberOfVertex(), white);
            found.assign(digraph->getNumberOfVertex(), 0);
            finalized.assign(digraph->getNumberOfVertex(), 0);
            predecessor.assign(digraph->getNumberOfVertex(), 0);
            
            for(int i = start_vertex; i < digraph->getNumberOfVertex(); i++){
                if(color[i] == white)
                    DFS_visit(i);
            }
        }    

        void DFS_visit(int i){
            color[i] = gray;
            std::cout << " -> " << digraph->vertexes[i]->getName();
            this->time++;
            found[i] = time;
            
            for(int j = 0; j < dim; j++){
                if((color[j] == white) && (digraph->adjacency_matrix[i][j] != 0)){
                    DFS_visit(j);
                }
                
                color[i] = black;
                finalized[i] = time;
            }
            terminados.push_back(digraph->vertexes[i]->getName());
        }

        ~DFS(){
            std::reverse(terminados.begin(), terminados.end());
            for(int i = 0; i < terminados.size(); i++){
                std::cout << "[" << terminados[i] << "]";
            }
            std::cout << std::endl << std::endl;
        }
};

#endif