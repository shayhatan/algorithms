//
// Created by USER on 23/12/2021.
//

#ifndef ALGORITHMS_VERTEX_H
#define ALGORITHMS_VERTEX_H

#include <string>
#include <vector>
#include <numeric>
#include <iostream>

//10^7
const int MAX_VAL = 10e7;

class Edge;

class Vertex {
    std::string id;
    std::vector<Edge*> adj_list;
    Vertex *predecessor = nullptr;

    //by default until we compare
    double min_distance = MAX_VAL;
public:
    Vertex(const std::string &_id);

    ~Vertex() = default;

    const std::vector<Edge*> &getAdjList();

    void addAdj(Edge* edge);

    const std::string &getId() const;

    void setId(const std::string &id);

    Vertex *getPredecessor() const;

    void setPredecessor(Vertex *predecessor);

    double getMinDistance() const;

    void setMinDistance(double minDistance);

    bool operator<(const Vertex& other) const;

    friend std::ostream &operator<<(std::ostream &strm, Vertex& vertex);
};


#endif //ALGORITHMS_VERTEX_H
