//
// Created by USER on 23/12/2021.
//

#include "Edge.h"

Edge::Edge(double _weight, const std::shared_ptr<Vertex> &_start_vertex,
           const std::shared_ptr<Vertex> &_target_vertex)
        : weight(_weight), start_vertex(_start_vertex), target_vertex(_target_vertex) {
}

double Edge::getWeight() const {
    return weight;
}

const std::shared_ptr<Vertex> &Edge::getStartVertex() const {
    return start_vertex;
}

const std::shared_ptr<Vertex> &Edge::getTargetVertex() const {
    return target_vertex;
}
