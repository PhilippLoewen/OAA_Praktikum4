//
// Created by loewi on 27.04.16.
//

#include "Node.h"


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










