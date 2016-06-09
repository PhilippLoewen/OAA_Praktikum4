//
// Created by loewi on 5/26/16.
//

#ifndef PRAKTIKUM3_NAVIGATOR_H
#define PRAKTIKUM3_NAVIGATOR_H


#include "DiGraph.h"
#include "Vehicle.h"

class Navigator {
    DiGraph *mDiGraph;

    Vehicle *mVehicle;

public:
    Navigator(DiGraph *diGraph) : mDiGraph{ diGraph }{};

    void setGraph(DiGraph *diGraph);

    DiGraph* getGraph();

    void setVehicle(Vehicle *vehicle);

    Vehicle * getVehicle();

    double planRoute(std::string from, std::string to);


};


#endif //PRAKTIKUM3_NAVIGATOR_H
