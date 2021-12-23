//
// Created by USER on 23/12/2021.
//

#ifndef ALGORITHMS_EDGE_H
#define ALGORITHMS_EDGE_H

#include "Vertex.h"
#include <memory>


class Edge {

    double weight;
    std::shared_ptr<Vertex> start_vertex;
    std::shared_ptr<Vertex> target_vertex;

public:
    Edge(double _weight, const std::shared_ptr<Vertex> &_start_vertex, const std::shared_ptr<Vertex> &_target_vertex);

    double getWeight() const;

    const std::shared_ptr<Vertex> &getStartVertex() const;

    const std::shared_ptr<Vertex> &getTargetVertex() const;

};


#endif //ALGORITHMS_EDGE_H
