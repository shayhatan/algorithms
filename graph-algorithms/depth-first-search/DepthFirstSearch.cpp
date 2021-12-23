//
// Created by USER on 22/12/2021.
//

#include "DepthFirstSearch.h"

void DepthFirstSearch::operator()() {
    for (auto vertex : vertex_list) {
        if (!vertex->isVisited()) {
            dfs(vertex);
        }
    }
    std::cout << std::endl;
}

void DepthFirstSearch::dfs(Vertex *vertex) {
    //we visit given vertex
    std::cout << *vertex << std::endl;
    //visit the neighbors
    for (Vertex *v : vertex->getNeighbours()) {
        if (!v->isVisited()) {
            v->setVisited(true);
            // instead of using the STL : "Stack", we use the actual stack with recursion
            dfs(v);
        }
    }
}

DepthFirstSearch::DepthFirstSearch(std::vector<Vertex *> &_vertex_list) : vertex_list(_vertex_list) {

}
