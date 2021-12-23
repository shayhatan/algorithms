//
// Created by USER on 22/12/2021.
//

#include "Vertex.h"

Vertex::Vertex(const std::string &_name) : name(_name){}

const std::string &Vertex::getName() const {
    return name;
}

void Vertex::setName(const std::string &name) {
    Vertex::name = name;
}

bool Vertex::isVisited() const {
    return visited;
}

void Vertex::setVisited(bool _visited) {
    visited = _visited;
}


void Vertex::addNeighbour(Vertex *neighbour) {
    neighbours.push_back(neighbour);
}

std::ostream &operator<<(std::ostream &strm, const Vertex& vertex) {
    strm << vertex.name;
    return strm;
}

const std::vector<Vertex *> &Vertex::getNeighbours() const{
    return neighbours;
}

