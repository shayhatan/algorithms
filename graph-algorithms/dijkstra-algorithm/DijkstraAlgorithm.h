//
// Created by USER on 23/12/2021.
//

#ifndef ALGORITHMS_DIJKSTRAALGORITHM_H
#define ALGORITHMS_DIJKSTRAALGORITHM_H

#include "Vertex.h"
#include "Edge.h"

// Dijkstra's Shortest Path -
// could preform Fibonacci heap in Complexity of - Time: O(V log(V)), Space: O(V)
//### Can not calculate if there is a negative weight!

class DijkstraAlgorithm {
public:
    void computePaths(std::shared_ptr<Vertex> source_vertex);

    std::vector<Vertex *> getPath(std::shared_ptr<Vertex> vertex);
};

#endif //ALGORITHMS_DIJKSTRAALGORITHM_H
