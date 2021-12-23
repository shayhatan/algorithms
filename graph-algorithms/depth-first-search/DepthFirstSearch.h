//
// Created by USER on 22/12/2021.
//

#ifndef ALGORITHMS_DEPTHFIRSTSEARCH_H
#define ALGORITHMS_DEPTHFIRSTSEARCH_H

#include "Vertex.h"
#include <vector>
#include <iostream>

class DepthFirstSearch {
    std::vector<Vertex *> vertex_list;
public:
    explicit DepthFirstSearch(std::vector<Vertex*> &_vertex_list);

    void operator()();


private:
    void dfs(Vertex *vertex);
};


#endif //ALGORITHMS_DEPTHFIRSTSEARCH_H
