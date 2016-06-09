//
// Created by loewi on 27.04.16.
//

#ifndef PRAKTIKUM3_NODE_H
#define PRAKTIKUM3_NODE_H

#include <string>
#include <vector>


class Edge;

class Node {
public:
    Node(int x = 0, int y = 0) : mPositionX{ x }, mPositionY{y}{};

    Node(std::string key, int x, int y) : mNodeKey { key }, mPositionX { x }, mPositionY { y } {};

    std::string getKey() const;

    std::vector<Edge *> getEdges();

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

    Edge* getEdgeTo(Node* endnode);

private:
    std::string mNodeKey;

    int mPositionX, mPositionY;

    std::vector<Edge *> mEdges;


};


#endif //PRAKTIKUM3_NODE_H
