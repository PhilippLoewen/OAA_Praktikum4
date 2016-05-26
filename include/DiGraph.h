//
// Created by loewi on 27.04.16.
//

#ifndef PRAKTIKUM3_DIGRAPH_H
#define PRAKTIKUM3_DIGRAPH_H


#include "liste.h"
#include "Edge.h"

class Node;

class DiGraph {
public:

    void addNode(Node * node);

    void addEdge(std::string pKey1, std::string pKey2, float pWeight);

    Liste<Node*> getNeighbours(std::string key);

    Liste<Edge*> getEdges(std::string key);

    Liste<Node*> getNodes();

    Liste<Edge*> dijkstraShortestPath(std::string start, std::string end);

private:
    Liste<Node*> mNodes;

    Node *findByKey(std::string pKey);
};


#endif //PRAKTIKUM3_DIGRAPH_H