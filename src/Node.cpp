//
// Created by loewi on 27.04.16.
//

#include "Node.h"
#include "Edge.h"


std::string Node::getKey() const {
    return mNodeKey;
}

Liste<Edge *> Node::getEdges() {
    return mEdges;
}

void Node::setKey(std::string new_key) {
    mNodeKey = new_key;
}

void Node::setNewEdge(Edge *edge) {
    mEdges.append(edge);
}

Edge *Node::getEdgeTo(Node *endnode) {
    int i = 0;
    while(this->mEdges[i]->getEndNode() != endnode && i < this->mEdges.size()) {
        i++;
    }
    if (i == this->mEdges.size())
        throw "Edge not found";
    return this->mEdges[i];
}












