//
// Created by USER on 22/12/2021.
//

#ifndef ALGORITHMS_VERTEX_H
#define ALGORITHMS_VERTEX_H


#include <string>
#include <vector>
#include <iostream>

class Vertex {
    //every node will have an integer (data) parameter
    std::string name = 0;

private:
    //track whether we already visited the node or not
    bool visited = false;
    //store the neighbours
    std::vector<Vertex *> neighbours;
public:
    Vertex(const std::string &_name);

    ~Vertex() = default;

    const std::string &getName() const;

    void setName(const std::string &name);

    bool isVisited() const;

    void setVisited(bool _visited);

    const std::vector<Vertex *> &getNeighbours() const;

    void addNeighbour(Vertex *neighbour);

    friend std::ostream &operator<<(std::ostream &strm, const Vertex &vertex);

};


#endif //ALGORITHMS_VERTEX_H
