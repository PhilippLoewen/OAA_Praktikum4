//
// Created by loewi on 04.05.16.
//


#include <Edge.h>
#include <ctime>
#include <gtest/gtest.h>

struct EdgeTest : public testing::Test {
    Edge *edge;
    EdgeTest() {
        edge = new Edge;
        std::srand(std::time(NULL));
    }

    virtual ~EdgeTest() {
        delete edge;
    }


};

TEST_F(EdgeTest, weight) {
    double weight = rand() % 10;
    edge->setWeight(weight);
    EXPECT_EQ(weight, edge->getWeight());
}

TEST_F(EdgeTest, node) {
    Node *snode = new Node;
    Node *enode = new Node;
    edge->setStartNode(snode);
    edge->setEndNode(enode);
    EXPECT_EQ(snode, edge->getStartNode());
    EXPECT_EQ(enode, edge->getEndNode());
    edge->setStartNode(enode);
    EXPECT_EQ(edge->getEndNode(),edge->getStartNode());
    edge->setEndNode(snode);
    EXPECT_EQ(snode, edge->getEndNode());
}

