//
// Created by loewi on 27.04.16.
//

#ifndef PRAKTIKUM3_EDGE_H
#define PRAKTIKUM3_EDGE_H


#include "Node.h"

class Edge {
public:

    double getWeight();
    Node * getStartNode();
    Node * getEndNode();

    void setWeight(double w);

    void setStartNode(Node * n);

    void setEndNode(Node * n);

private:

    Node *mStartnode;

    Node *mEndnode;

    double mWeight;

};


#endif //PRAKTIKUM3_EDGE_H
