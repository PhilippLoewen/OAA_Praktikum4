//
// Created by loewi on 27.05.16.
//
#include "gtest/gtest.h"
#include <stdlib.h>
#include <Car.h>
#include <Motorcycle.h>
#include <Bicycle.h>
#include "Navigator.h"

#include "Helper.h"

struct NavigatorTest : public testing::Test {
    Navigator *navigator;
    DiGraph *diGraph;
    NavigatorTest() {
        diGraph = new DiGraph();
        navigator = new Navigator(diGraph);
        std::srand(std::time(NULL));
    }

    virtual ~NavigatorTest() {
        delete navigator;
        delete diGraph;
    }


};

TEST_F(NavigatorTest, changeGraph) {
    EXPECT_EQ(diGraph, navigator->getGraph());

    DiGraph *nGraph = new DiGraph;
    navigator->setGraph(nGraph);

    EXPECT_EQ(nGraph, navigator->getGraph());


}

TEST_F(NavigatorTest, Vehicle) {
    Car *polo = new Car(60);
    Motorcycle *mc = new Motorcycle(120);
    Bicycle *rad = new Bicycle(20);

    navigator->setVehicle(polo);

    EXPECT_EQ(polo, navigator->getVehicle());

    navigator->setVehicle(mc);

    EXPECT_EQ(mc, navigator->getVehicle());

    EXPECT_EQ(rad, navigator->getVehicle());



}

