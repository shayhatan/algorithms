//
// Created by USER on 26/12/2021.
//

#ifndef BELLMAN_FORD_ALGORITHM_VERTEX_H
#define BELLMAN_FORD_ALGORITHM_VERTEX_H
#include "Edge.h"
#include <vector>
#include <limits>
#include <iostream>

const int MAX_VALUE = 10e7;

class Vertex {
    std::string id;
    bool visited = false;
    int min_distance = MAX_VALUE;
    Vertex *previous_vertex = nullptr;

public:
    Vertex(std::string _id);

    int getMin() const;

    void setMin(int min);

    Vertex *getPreviousVertex() const;

    void setPreviousVertex(Vertex *_previous_vertex);

    bool isVisited() const;

    void setVisited(bool _visited);

    friend std::ostream &operator<<(std::ostream& os, const Vertex& v);

};
#endif //BELLMAN_FORD_ALGORITHM_VERTEX_H
