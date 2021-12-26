//
// Created by USER on 26/12/2021.
//

#include "Vertex.h"

Vertex::Vertex(std::string _id) : id(_id) {

}

int Vertex::getMin() const {
    return min_distance;
}

void Vertex::setMin(int min) {
    min_distance = min;
}

Vertex *Vertex::getPreviousVertex() const {
    return previous_vertex;
}

void Vertex::setPreviousVertex(Vertex *_previous_vertex) {
    previous_vertex = _previous_vertex;
}

bool Vertex::isVisited() const {
    return visited;
}

void Vertex::setVisited(bool _visited) {
    visited = _visited;
}

std::ostream &operator<<(std::ostream &os, const Vertex &v) {
    os << v.id;
    return os;
}

