//
// Created by loewi on 5/26/16.
//

#include "Navigator.h"
#include "DiGraph.h"

void Navigator::setGraph(DiGraph *diGraph) {
    this->mDiGraph = diGraph;
}

void Navigator::setVehicle(Vehicle *vehicle) {
    this->mVehicle = vehicle;
}

double Navigator::planRoute(std::string from, std::string to) {
    Liste<Edge*> path = this->mDiGraph->dijkstraShortestPath(from, to);
    this->mDiGraph->getVisualizer()->highlightPath(path);
    double time = 0;
    for (auto edge : path) {
        time += this->mVehicle->neededTimeForDistance(edge->getWeight());
    }

}







