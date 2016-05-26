//
// Created by loewi on 06.05.16.
//

#include <gtest/gtest.h>
#include "Node.h"
#include "Edge.h"
#include "Helper.h"
#include <climits>


#define ITER 50

class NodeTest : public testing::Test {
protected:
    Node *node;
    NodeTest() {
        node = new Node;
        std::srand(std::time(NULL));
    }

    virtual ~NodeTest() {
        delete node;
    }
};

TEST_F(NodeTest, constructor) {
    Node node1;
    EXPECT_EQ("", node1.getKey());

    EXPECT_EQ(0, node1.getPositionX());
    EXPECT_EQ(0, node1.getPositionY());

    Node node2(4,2);

    EXPECT_EQ(4, node2.getPositionX());
    EXPECT_EQ(2, node2.getPositionY());
}


TEST_F(NodeTest, basic) {

    EXPECT_EQ("", node->getKey());

    EXPECT_EQ(0, node->getPositionX());
    EXPECT_EQ(0, node->getPositionY());

    node->setKey("Nope");
    EXPECT_EQ("Nope", node->getKey());
    for (int i = 0; i < ITER; i++) {

    }
}

TEST_F(NodeTest, positions) {
    int xarr[ITER];
    int yarr[ITER];
    Node node1;

    for (int i = 0; i < ITER; i++) {
        xarr[i] = rand() % INT_MAX;
        yarr[i] = rand() % INT_MAX;
        node1.setPositionX(xarr[i]);
        node1.setPositionY(yarr[i]);

        EXPECT_EQ(xarr[i], node1.getPositionX());
        EXPECT_EQ(yarr[i], node1.getPositionY());

    }
}

TEST_F(NodeTest, edgetest) {
    Node node[2];
    std::string str[2];
    int posx[2];
    int posy[2];
    for (int i = 0; i < 2; i++) {
        str[i] = Helper::randomString(3);
        posx[i] = rand() % INT_MAX;
        posy[i] = rand() % INT_MAX;
        node[i].setKey(str[i]);
        node[i].setPositionX(posx[i]);
        node[i].setPositionY(posy[i]);
    }
    Edge *edge = new Edge;
    edge->setWeight(6.34);
    edge->setStartNode(&node[0]);
    edge->setEndNode(&node[1]);
    node->setNewEdge(edge);

    Liste<Edge *> edges = node[0].getEdges();
    EXPECT_EQ(edge, edges[0]);
    EXPECT_EQ(posx[0], edges[0]->getStartNode()->getPositionX());
    EXPECT_EQ(posy[0], edges[0]->getStartNode()->getPositionY());
    EXPECT_EQ(str[0], edges[0]->getStartNode()->getKey());

    EXPECT_EQ(posx[1], edges[0]->getEndNode()->getPositionX());
    EXPECT_EQ(posy[1], edges[0]->getEndNode()->getPositionY());
    EXPECT_EQ(str[1], edges[0]->getEndNode()->getKey());

}
