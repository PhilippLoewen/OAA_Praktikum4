//
// Created by loewi on 27.04.16.
//

#include <limits>
#include <SimpleException.h>
#include <Priorityqueue.h>
#include <map>
#include <iostream>
#include "DiGraph.h"
#include "Edge.h"

#define STARTSIZE 100


void DiGraph::addNode(Node *node) {
    mNodes.push_back(node);
}

void DiGraph::addEdge(std::string pKey1, std::string pKey2, double pWeight) {
    Edge *edge = new Edge;
    Node *node1 = findByKey(pKey1);
    Node *node2 = findByKey(pKey2);
    edge->setStartNode(node1);
    edge->setEndNode(node2);
    edge->setWeight(pWeight);
    node1->setNewEdge(edge);
}

std::vector<Node *> DiGraph::getNeighbours(std::string key) {
    Node *tmpnode,*startnode,*endnode;
    std::vector<Edge *> edges;
    std::vector<Node *> retList;
    for (int i = 0; i < mNodes.size(); i++) {
        tmpnode = mNodes[i];
        edges = tmpnode->getEdges();
        for (int j = 0; j < edges.size();j++) {
            startnode = edges[j]->getStartNode();
            endnode = edges[j]->getEndNode();
            if (startnode->getKey() == key && startnode != endnode) {
                retList.push_back(endnode);
            }
            if (endnode->getKey() == key && startnode != endnode) {
                retList.push_back(startnode);
            }
        }

    }

    return retList;
}

std::vector<Edge *> DiGraph::getEdges(std::string key) {
    Node *node = findByKey(key);
    return node->getEdges();
}

std::vector<Node *> DiGraph::getNodes() {
    std::vector<Node *> nodes;
    for (int i = 0; i < mNodes.size(); i++) {
        nodes.push_back(mNodes[i]);
    }
    return nodes;
}


Node *DiGraph::findByKey(std::string pKey) {
    int i = 0;
    while (mNodes[i]->getKey() != pKey && i < mNodes.size()) {
        i++;
    }
    if (i == mNodes.size()) {
        throw SimpleException("Key nicht gefunden", 1);
    }
    return mNodes[i];
}

std::vector<Edge *> DiGraph::dijkstraShortestPath(std::string start, std::string end) {
    Priorityqueue<Node*> pq;

    std::vector<Edge*> result;
    Node *startnode = findByKey(start);
    Node *endnode = findByKey(end);

    Node *u;
    Node *v;

    std::map<Node*,double> dist;
    std::map<Node*,Node*> previous;

    for(auto node : this->mNodes){
        if (node == startnode)
            dist[node] = 0;
        else
            dist[node] = std::numeric_limits<double>::infinity();

        previous[node] = nullptr;
        pq.insert(node, dist[node]);
    }

    //std::cout << "Between for and while\n";

    while (!pq.isEmpty()){
        u = pq.extractMin();
        std::vector<Edge*> outEdges = u->getEdges();

        for(auto edge : outEdges) {
            v = edge->getEndNode();
            double alt = dist[u] + edge->getWeight();
            if (alt < dist[v]) {
                dist[v] = alt;
                previous[v] = u;
                pq.decreaseKey(v, alt);
            }
        }
    }

    u = endnode;

    //std::cout << previous[u]->getKey();


   while (previous[u] != nullptr){
        result.push_back(previous[u]->getEdgeTo(u));
        u = previous[u];
    }

    return result;


}

void DiGraph::setVisualizer(GraphVisualizer *graphVisualizer) {
    mGraphVisualizer = graphVisualizer;
}

GraphVisualizer *DiGraph::getVisualizer() {
    return mGraphVisualizer;
}


























