//
// Created by loewi on 5/26/16.
//

#include "DiGraph.h"
#include "Node.h"
#include <string>
#include <iostream>
#include "GraphVisualizer.h"
#include "Vehicle.h"
#include "Navigator.h"


void createDummyGraph(Digraph &g) {
    g.addNode( new Node("Aachen", 100, 600));
    g.addNode( new Node("Berlin", 300, 650));
    g.addNode( new Node("Koeln", 300, 300));
    g.addNode( new Node("Essen", 900, 300));
    g.addNode( new Node("Bonn", 300, 150));
    g.addNode( new Node("Krefeld", 100, 160));

    g.createEdge("Aachen", "Berlin", 7);
    g.createEdge("Koeln", "Aachen", 9);
    g.createEdge("Aachen", "Krefeld", 7);
    g.createEdge("Berlin", "Essen", 40);
    g.createEdge("Berlin", "Koeln", 3);
    g.createEdge("Koeln", "Essen", 31);
    g.createEdge("Bonn", "Essen", 8);
    g.createEdge("Krefeld", "Bonn", 1);


}



int main(int argc, char **argv) {

    DiGraph myGraph;
    OpenCVGraphVisualizer graphviz;
    myGraph.setVisualizer(&graphviz);
    createDummyGraph(myGraph);
    Navigator navi(&myGraph);
    int speed = 120;
    navi.setVehicle(new Car(speed));
    std::cout << "Fahrzeit: " << navi.planRoute("Aachen", "Essen") << std::endl;
}
