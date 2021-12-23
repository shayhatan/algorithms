//
// Created by USER on 23/12/2021.
//
#include "DijkstraAlgorithm.h"
#include <set>
#include <algorithm>

using std::multiset;
using std::shared_ptr;

void DijkstraAlgorithm::computePaths(std::shared_ptr<Vertex> source_vertex) {
    //cmp function for stl...
    auto fCompare = [&](shared_ptr<Vertex> const &l, shared_ptr<Vertex> const &r) {
        return *l < *r;
    };
    source_vertex->setMinDistance(0.);
    // could be much better if it were fibonacci heap...
    multiset<shared_ptr<Vertex>, decltype(fCompare)> queue(fCompare);
    //insert starting vertex
    queue.insert(source_vertex);

    while (!queue.empty()) {
        auto it = queue.begin();
        auto actual_vertex = *it;
        queue.erase(it);

        for (const Edge *edge : actual_vertex->getAdjList()) {
            shared_ptr<Vertex> from = edge->getStartVertex();
            shared_ptr<Vertex> to = edge->getTargetVertex();

            // notice the the first actual distance is zero ...
            double new_distance = actual_vertex->getMinDistance() + edge->getWeight();

            //Fibonacci heaps can do it O(1)!! BUT here we are using multiset..
            //this would be O(V) running time complexity
            if (new_distance < to->getMinDistance()) {
                //means we have better route
                for (auto i = queue.begin(); i != queue.end(); ++i) {
                    if ((*i)->getId() == to->getId()) {
                        queue.erase(i);
                        break;
                    }
                }
                to->setMinDistance(new_distance);
                to->setPredecessor(actual_vertex.get());
                queue.insert(to);
            }
        }
    }
}

std::vector<Vertex *> DijkstraAlgorithm::getPath(std::shared_ptr<Vertex> vertex) {
    //this would be the dest vertex
    std::cout << "min distance: " << vertex->getMinDistance()<< std::endl;
    std::vector<Vertex *> path;
    for (Vertex *it = vertex.get(); it != nullptr; it = it->getPredecessor()) {
        path.push_back(it);
    }
    std::reverse(path.begin(), path.end());
    return path;

}