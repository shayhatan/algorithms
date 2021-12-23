//
// Created by USER on 23/12/2021.
//

#include "Vertex.h"

const std::string &Vertex::getId() const {
    return id;
}

void Vertex::setId(const std::string &id) {
    Vertex::id = id;
}

Vertex *Vertex::getPredecessor() const {
    return predecessor;
}

void Vertex::setPredecessor(Vertex *predecessor) {
    Vertex::predecessor = predecessor;
}

double Vertex::getMinDistance() const {
    return min_distance;
}

void Vertex::setMinDistance(double minDistance) {
    min_distance = minDistance;
}

const std::vector<Edge*> &Vertex::getAdjList() {
    return adj_list;
}

void Vertex::addAdj(Edge *edge) {
    if (edge) {
        adj_list.push_back(edge);
    }
}

Vertex::Vertex(const std::string &_id) : id(_id) {}

bool Vertex::operator<(const Vertex &other) const {
    return min_distance < other.min_distance;
}

std::ostream &operator<<(std::ostream &strm, Vertex &vertex) {
    strm << vertex.id;
    return strm;
}
