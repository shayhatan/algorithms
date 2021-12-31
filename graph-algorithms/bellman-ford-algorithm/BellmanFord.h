//
// Created by USER on 26/12/2021.
//

#ifndef BELLMAN_FORD_ALGORITHM_BELLMANFORD_H
#define BELLMAN_FORD_ALGORITHM_BELLMANFORD_H

#include <vector>
#include "Vertex.h"
#include "Edge.h"
// could preform Fibonacci heap in Complexity of - Time: O(V log(V)), Space: O(V)

class BellmanFord {
    std::vector<Vertex> &vector_list;
    std::vector<Edge> &edge_list;
public:
    BellmanFord(std::vector<Vertex> &vector_list, std::vector<Edge> &edge_list);

    void operator()(size_t source_vertex_index, size_t target_vertex_index) const;

private:
    static bool hasCycle(std::vector<Edge> &edge_list);

    static void printPath(Vertex& v);
};


#endif //BELLMAN_FORD_ALGORITHM_BELLMANFORD_H
