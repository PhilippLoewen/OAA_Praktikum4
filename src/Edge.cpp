//
// Created by loewi on 27.04.16.
//

#include "Edge.h"

double Edge::getWeight() {
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

void Edge::setWeight(double w) {
    mWeight = w;
}

void Edge::setEndNode(Node *n) {
    mEndnode = n;
}











