//
// Created by loewi on 5/26/16.
//

#ifndef PRAKTIKUM3_GRAPHVISUALIZER_H
#define PRAKTIKUM3_GRAPHVISUALIZER_H


class DiGraph;

class Edge;

class GraphVisualizer {

public:
    virtual void render(DiGraph &digraph) = 0;

    virtual void show() = 0;

    virtual void highlightPath(std::vector<Edge*> path) = 0;

};


#endif //PRAKTIKUM3_GRAPHVISUALIZER_H
