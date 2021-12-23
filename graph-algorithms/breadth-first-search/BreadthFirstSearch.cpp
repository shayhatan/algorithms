//
// Created by USER on 22/12/2021.
//

#include "BreadthFirstSearch.h"

void BreadthFirstSearch::operator()(Vertex* root) const {
    //breadth first search need a FIFO structure -> queue
    std::deque<Vertex *> queue;
    //we start with "root node" (set it to be visited)
    root->setVisited(true);
    //add the root node to the queue
    queue.push_back(root);
    while (!queue.empty()) {
        //this is how we get the first item we have inserted
        Vertex *actual = queue.front();
        queue.pop_front();
        std::cout << "Visited node " << *actual << std::endl;
        // now we visit neighbors
        for(Vertex *v : actual->getNeighbours()) {
            //only visit node once
            if(!v->isVisited()) {
                v->setVisited(true);
                queue.push_back(v);
            }
        }
    }
}
