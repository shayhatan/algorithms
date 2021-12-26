//
// Created by USER on 26/12/2021.
//

#include "Edge.h"

Edge::Edge(Vertex *start_vertex, Vertex *end_vertex, int weight) : start_vertex(start_vertex),
                                                                   end_vertex(end_vertex), weight(weight) {}

int Edge::getWeight() const {
    return weight;
}

void Edge::setWeight(int weight) {
    Edge::weight = weight;
}

Vertex *Edge::getStartVertex() const {
    return start_vertex;
}

void Edge::setStartVertex(Vertex *start_vertex) {
    start_vertex = start_vertex;
}

Vertex *Edge::getEndVertex() const {
    return end_vertex;
}

void Edge::setEndVertex(Vertex *end_vertex) {
    end_vertex = end_vertex;
}

