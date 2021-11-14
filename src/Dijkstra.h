#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_
#include <functional>
#include <limits>

typedef std::pair<int, int> distVertex;

class Dijkstra {
   private:
   public:
    const int infinity = 9999;
    const int nil = -1;
    std::vector<int> predecessor;
    std::vector<int> distance;
    std::vector<Vertex> S;
    Digraph graph;

    Dijkstra(Digraph G) : graph(G) {
        distance.assign(graph.Size(), infinity);
        predecessor.assign(graph.Size(), nil);
    }

    void shortestPath(int source) {
        // This PQ syntax uses minimum heap logic on stored data.
        std::priority_queue<distVertex, std::vector<distVertex>,
                            std::greater<distVertex> >
            min_distance;

        min_distance.push(std::make_pair(0, source));
        distance[source] = 0;

        while (!min_distance.empty()) {
            // Minimum heap secures the minimum distance is processed first.
            int u = min_distance.top().second;

            min_distance.pop();

            for (int v = 0; v < graph.Size(); v++) {
                if(graph.edge[u][v] == 0){
                    continue;
                }
                if (distance[v] > (distance[u] + graph.weight[u][v])) {
                    distance[v] = distance[u] + graph.weight[u][v];
                    predecessor[v] = u;
                    min_distance.push(std::make_pair(distance[v], v));
                }
            }
        }
        showPath(source);
    }

    void printPath(int vertex){
        if(predecessor[vertex] == -1){
            return;
        }
        printPath(predecessor[vertex]);
        std::cout << " - " << graph.vertices[vertex].getName();
    }

    void showPath(int source){
        std::cout << "Dijkstra Shortest Path" << std::endl;
        std::cout << "Vertex\tDistance\tPath";

        for(int i = 1; i < graph.Size(); i++){
            std::cout << std::endl << graph.vertices[source].getName() 
            << " -> " << graph.vertices[i].getName() << "\t\t" << distance[i]
            << "\t\t" << graph.vertices[source].getName(); 
            
            printPath(i);
        }
    }
};

#endif