//
// Created by loewi on 27.04.16.
//

#ifndef PRAKTIKUM3_NODE_H
#define PRAKTIKUM3_NODE_H

#include <string>
#include "liste.h"

class Edge;

class Node {
public:
    Node(int x = 0, int y = 0) : mPositionX{ x }, mPositionY{y}{};

    std::string getKey() const;

    Liste<Edge *> getEdges();

    void setKey(std::string new_key);

    void setNewEdge(Edge *edge);

    int getPositionX() const {
        return mPositionX;
    }

    void setPositionX(int positionX) {
        mPositionX = positionX;
    }

    int getPositionY() const {
        return mPositionY;
    }

    void setPositionY(int positionY) {
        mPositionY = positionY;
    }

private:
    std::string mNodeKey;

    int mPositionX, mPositionY;

    Liste<Edge *> mEdges;


};


#endif //PRAKTIKUM3_NODE_H
