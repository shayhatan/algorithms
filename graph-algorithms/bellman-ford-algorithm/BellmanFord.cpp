//
// Created by USER on 26/12/2021.
//

#include "BellmanFord.h"

BellmanFord::BellmanFord(std::vector<Vertex> &vector_list, std::vector<Edge> &edge_list) : vector_list(vector_list),
                                                                                           edge_list(edge_list) {}

void BellmanFord::operator()(size_t source_vertex_index, size_t target_vertex_index) const {
    if (source_vertex_index >= vector_list.size() || target_vertex_index >= vector_list.size()
        || source_vertex_index < 0 || target_vertex_index < 0) {
        return;
    }

    Vertex &source_vertex = vector_list[source_vertex_index];
    Vertex &target_vertex = vector_list[target_vertex_index];

    source_vertex.setMin(0);

    for (int i = 0; i < vector_list.size() - 1; ++i) {
        for (auto const &edge : edge_list) {
            int new_distance = edge.getStartVertex()->getMin() + edge.getWeight();

            if (new_distance < edge.getEndVertex()->getMin()) {
                edge.getEndVertex()->setMin(new_distance);
                edge.getEndVertex()->setPreviousVertex(edge.getStartVertex());
            }
        }
    }

    //additional iteration to check negative cycles
    if (hasCycle(edge_list)) {
        return;
    }

    if (target_vertex.getMin() != MAX_VALUE) {
        printPath(target_vertex);
    } else {
        std::cout << "There is not path from source to target...\n";
    }

}

bool BellmanFord::hasCycle(std::vector<Edge> &edge_list) {
    for (Edge edge: edge_list) {
        if (edge.getStartVertex()->getMin() != MAX_VALUE) {
            if (edge.getEndVertex()->getMin() > edge.getStartVertex()->getMin() + edge.getWeight()) {
                std::cout << "Negative edge weight cycles detected" << std::endl;
                return true;
            }
        }
    }
    return false;
}

void BellmanFord::printPath(Vertex &v) {
    std::cout << "There is shortest path from source to target, with cost: " << v.getMin() << std::endl;

    Vertex *actual = &v;
    while (actual != nullptr) {
        std::cout << *actual << ' ';
        actual = actual->getPreviousVertex();
    }
    std::cout << std::endl;
}
