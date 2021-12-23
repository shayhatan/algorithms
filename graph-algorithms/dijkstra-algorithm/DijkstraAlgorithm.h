//
// Created by USER on 23/12/2021.
//

#ifndef ALGORITHMS_DIJKSTRAALGORITHM_H
#define ALGORITHMS_DIJKSTRAALGORITHM_H

#include "Vertex.h"
#include "Edge.h"

class DijkstraAlgorithm {
public:
    void computePaths(std::shared_ptr<Vertex> source_vertex);

    std::vector<Vertex *> getPath(std::shared_ptr<Vertex> vertex);
};

#endif //ALGORITHMS_DIJKSTRAALGORITHM_H
