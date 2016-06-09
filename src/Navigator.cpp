//
// Created by loewi on 5/26/16.
//

#include <iostream>
#include "Navigator.h"
#include "DiGraph.h"

void Navigator::setGraph(DiGraph *diGraph) {
    this->mDiGraph = diGraph;
}

void Navigator::setVehicle(Vehicle *vehicle) {
    this->mVehicle = vehicle;
}

double Navigator::planRoute(std::string from, std::string to) {
    std::vector<Edge*> path = this->mDiGraph->dijkstraShortestPath(from, to);
    GraphVisualizer *gv = this->mDiGraph->getVisualizer();
    gv->render(*this->mDiGraph);
    gv->highlightPath(path);
    double time = 0;
    for (auto edge : path) {
        time += this->mVehicle->neededTimeForDistance(edge->getWeight());
    }

    gv->show();
    return time;
}

DiGraph *Navigator::getGraph() {
    return mDiGraph;
}

Vehicle * Navigator::getVehicle() {
    return mVehicle;
}











