//
// Created by loewi on 06.05.16.
//

#include <gtest/gtest.h>
#include <stdlib.h>
#include <OpenCVGraphVisualizer.h>
#include "DiGraph.h"
#include "Helper.h"

#define ANZAHL 10
#define AUFLX 1500
#define AUFLY 960
#define BEREICHX (AUFLX - 199)
#define BEREICHY (AUFLY - 199)


class DiGraphTest : public testing::Test {
protected:
    DiGraph *digraph;
    DiGraphTest() {
        digraph = new DiGraph;
        std::srand(std::time(NULL));
    }

    virtual ~DiGraphTest() {
        delete digraph;
    }


};

TEST_F(DiGraphTest, complete) {

    std::string keys[ANZAHL];
    int posx[ANZAHL];
    int posy[ANZAHL];
    int weight[ANZAHL];
    DiGraph diGraph;
    Node node[ANZAHL];

    for (int i = 0; i < ANZAHL; i++) {
        keys[i] = Helper::randomString(3);
        posx[i] = (std::rand() % BEREICHX) + 100;
        posy[i] = (std::rand() % BEREICHY) + 100;
        node[i].setKey(keys[i]);
        node[i].setPositionX(posx[i]);
        node[i].setPositionY(posy[i]);
        diGraph.addNode(&node[i]);
        if (i > 0) {
            weight[i] = std::rand() % 10;
            diGraph.addEdge(keys[i - 1], keys[i], weight[i]);

        }

    }

    // Check
    std::vector<Node *> nodelist = diGraph.getNodes();

    for (int i = 0; i < ANZAHL; i++) {

        EXPECT_EQ(keys[i], nodelist[i]->getKey());
        EXPECT_EQ(posx[i], nodelist[i]->getPositionX());
        EXPECT_EQ(posy[i], nodelist[i]->getPositionY());

        std::vector<Edge *> edgelist = nodelist[i]->getEdges();

        for (int j = 0; j < edgelist.size(); j++) {
            EXPECT_EQ(weight[i + 1],edgelist[j]->getWeight());
        }


        EXPECT_EQ(posx[i], node[i].getPositionX());
    }
}

TEST_F(DiGraphTest, visualizer) {
    OpenCVGraphVisualizer openCVGraphVisualizer;
    digraph->setVisualizer(&openCVGraphVisualizer);

    EXPECT_EQ(&openCVGraphVisualizer, digraph->getVisualizer());
}