//
// Created by loewi on 27.04.16.
//

#include "Edge.h"

float Edge::getWeight() {
    return mWeight;
}

Node *Edge::getStartNode() {
    return mStartnode;
}

Node *Edge::getEndNode() {
    return mEndnode;
}

void Edge::setStartNode(Node *n) {
    mStartnode = n;
}

void Edge::setWeight(float w) {
    mWeight = w;
}

void Edge::setEndNode(Node *n) {
    mEndnode = n;
}











