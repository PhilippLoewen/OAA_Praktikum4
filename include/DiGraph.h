//
// Created by loewi on 27.04.16.
//

#ifndef PRAKTIKUM3_DIGRAPH_H
#define PRAKTIKUM3_DIGRAPH_H



#include "Edge.h"
#include "GraphVisualizer.h"

class Node;

class DiGraph {
public:

    void addNode(Node * node);

    void addEdge(std::string pKey1, std::string pKey2, double pWeight);

    std::vector<Node*> getNeighbours(std::string key);

    std::vector<Edge*> getEdges(std::string key);

    std::vector<Node*> getNodes();

    std::vector<Edge*> dijkstraShortestPath(std::string start, std::string end);

    void setVisualizer(GraphVisualizer *graphVisualizer);

    GraphVisualizer* getVisualizer();

private:
    std::vector<Node*> mNodes;

    Node *findByKey(std::string pKey);

    GraphVisualizer* mGraphVisualizer;
};


#endif //PRAKTIKUM3_DIGRAPH_H
