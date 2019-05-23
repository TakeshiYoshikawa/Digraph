#ifndef WARSHALL_H_
#define WARSHALL_H_

class Warshall{
	private:
		Digraph* G;
		int dimension;
	public:
		Warshall(Digraph* graph){
			this->G = graph;
			this->dimension = G->getNumberOfVertex();
		}
		
		void WarshallAlgorithm(){
			for(int k = 0; k < dimension; k++){
				for(int i = 0; i < dimension; i++){
					for(int j = 0; j < dimension; j++){
						G->edges[i][j] = (G->edges[i][j] || (G->edges[i][k] && G->edges[k][j]));
					}
				}
			}
		}
};

#endif