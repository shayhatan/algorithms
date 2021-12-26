//
// Created by USER on 26/12/2021.
//

#ifndef BELLMAN_FORD_ALGORITHM_EDGE_H
#define BELLMAN_FORD_ALGORITHM_EDGE_H

class Vertex;

class Edge {
    int weight;
    Vertex *start_vertex;
    Vertex *end_vertex;
public:
    Edge(Vertex *start_vertex, Vertex *end_vertex, int weight);

    int getWeight() const;

    void setWeight(int weight);

    Vertex *getStartVertex() const;

    void setStartVertex(Vertex *start_vertex);

    Vertex *getEndVertex() const;

    void setEndVertex(Vertex *end_vertex);
};


#endif //BELLMAN_FORD_ALGORITHM_EDGE_H
