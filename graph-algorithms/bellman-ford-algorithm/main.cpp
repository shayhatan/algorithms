#include <iostream>

#include <iostream>

#include "Vertex.h"
#include "Edge.h"
#include "BellmanFord.h"
using std::vector;

int main(int argc, const char * argv[]) {

    vector <Vertex> vertex_list;

    vertex_list.push_back(Vertex("A"));
    vertex_list.push_back(Vertex("B"));
    vertex_list.push_back(Vertex("C"));
    vertex_list.push_back(Vertex("D"));
    vertex_list.push_back(Vertex("E"));
    vertex_list.push_back(Vertex("F"));
    vertex_list.push_back(Vertex("G"));
    vertex_list.push_back(Vertex("H"));

    vector <Edge> edge_list;
    edge_list.push_back(Edge(&vertex_list[0], &vertex_list[1], 5));
    edge_list.push_back(Edge(&vertex_list[0], &vertex_list[4], 9));
    edge_list.push_back(Edge(&vertex_list[0], &vertex_list[7], 8));
    edge_list.push_back(Edge(&vertex_list[1], &vertex_list[3], 12));
    edge_list.push_back(Edge(&vertex_list[1], &vertex_list[4], 15));
    edge_list.push_back(Edge(&vertex_list[1], &vertex_list[7], 4));
    edge_list.push_back(Edge(&vertex_list[2], &vertex_list[3], 3));
    edge_list.push_back(Edge(&vertex_list[2], &vertex_list[6], 11));
    edge_list.push_back(Edge(&vertex_list[3], &vertex_list[6], 9));
    edge_list.push_back(Edge(&vertex_list[4], &vertex_list[5], 4));
    edge_list.push_back(Edge(&vertex_list[4], &vertex_list[6], 20));
    edge_list.push_back(Edge(&vertex_list[4], &vertex_list[7], 5));
    edge_list.push_back(Edge(&vertex_list[5], &vertex_list[2], 1));
    edge_list.push_back(Edge(&vertex_list[5], &vertex_list[6], 13));
    edge_list.push_back(Edge(&vertex_list[7], &vertex_list[2], 7));
    edge_list.push_back(Edge(&vertex_list[7], &vertex_list[5], 6));

    BellmanFord algorithm = BellmanFord(vertex_list, edge_list);
    algorithm(0,6);
    return 0;
}