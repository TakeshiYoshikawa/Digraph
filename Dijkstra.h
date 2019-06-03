#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_
#include <limits>
#include <functional>

typedef std::pair<int,int> distVertex;

class Dijkstra {
   private:
   public:
    int minimum;
    const int infinity = 9999;
    const int nil = -1;
    std::vector<int> distance;
    std::vector<int> predecessor;
    Digraph graph;

    //ok
    Dijkstra(Digraph G) : graph(G){
        distance.assign(graph.Size(), infinity);
    }

    //ok
    void initializeSource(int source) {
        for (int i = 0; i < graph.Size(); i++) {
            predecessor.push_back(nil);
        }
        distance[source] = 0;
    }

    //ok
    void relax(int u, int v) {
        if (distance[v] > distance[u] + graph.weight[u][v]) {
            distance[v] = distance[u] + graph.weight[u][v];
            predecessor[v] = u;
        }
    }

    int extractMin() {
        this->minimum = distance[0];
        int minimum_index = 0;

        for (int index = 0; index < distance.size(); index++) {
            if (distance[index] < minimum) {
                distance[index] = minimum;
     
                // Stores index from distance with shortest value.
                minimum_index = index;
            }
        }
        return minimum_index;
    }

    void shortestPath(int source) {
        initializeSource(source);
        
        std::vector<Vertex> S;

        std::vector<Vertex> Q = graph.vertices;

        while (!Q.empty()) {
            int u = extractMin();
            std::cout << "[" <<  u << "]";
            
            // S.push_back(Q[u]);

            std::vector<Vertex>::iterator it = Q.begin() + u;
            Q.erase(it);
            
            for (int v = 0; v < 5; v++) {
                relax(u, v);
            }
        }

        // for (int i : distance) {
        //     std::cout << "[" << i << "]";
        // }
    }
};

#endif