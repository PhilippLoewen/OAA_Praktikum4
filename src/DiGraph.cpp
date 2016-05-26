//
// Created by loewi on 27.04.16.
//

#include <limits>
#include <SimpleException.h>
#include <Priorityqueue.h>
#include <map>
#include "DiGraph.h"
#include "Edge.h"

#define STARTSIZE 100


void DiGraph::addNode(Node *node) {
    mNodes.append(node);
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

Liste<Node *> DiGraph::getNeighbours(std::string key) {
    Node *tmpnode,*startnode,*endnode;
    Liste<Edge *> edges;
    Liste<Node *> retList;
    for (int i = 0; i < mNodes.size(); i++) {
        tmpnode = mNodes[i];
        edges = tmpnode->getEdges();
        for (int j = 0; j < edges.size();j++) {
            startnode = edges[j]->getStartNode();
            endnode = edges[j]->getEndNode();
            if (startnode->getKey() == key && startnode != endnode) {
                retList.append(endnode);
            }
            if (endnode->getKey() == key && startnode != endnode) {
                retList.append(startnode);
            }
        }

    }

    return retList;
}

Liste<Edge *> DiGraph::getEdges(std::string key) {
    Node *node = findByKey(key);
    return node->getEdges();
}

Liste<Node *> DiGraph::getNodes() {
    Liste<Node *> nodes;
    for (int i = 0; i < mNodes.size(); i++) {
        nodes.append(mNodes[i]);
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

Liste<Edge *> DiGraph::dijkstraShortestPath(std::string start, std::string end) {
    Priorityqueue<Node*> pq;

    Liste<Edge*> result;
    Node *startnode = findByKey(start);
    Node *endnode = findByKey(end);

    Node *u;

    std::map<Node*,double> dist;
    std::map<Node*,Node*> previous;

    for(int i = 0; i < this->mNodes.size(); i++){
        if (this->mNodes[i] == startnode)
            dist[this->mNodes[i]] = 0;
        else
            dist[this->mNodes[i]] = std::numeric_limits<double>::infinity();

        previous[this->mNodes[i]] = NULL;
        pq.insert(this->mNodes[i], dist[this->mNodes[i]]);
    }

    while (!pq.isEmpty()){
        u = pq.extractMin();
        Liste<Edge*> outEdges = u->getEdges();

        for(int i = 0; i < outEdges.size(); i++) {
            Node *v = outEdges[i]->getEndNode();
            double alt = dist[u] + outEdges[i]->getWeight();
            if (alt < dist[v]) {
                dist[v] = alt;
                previous[v] = u;
                pq.decreaseKey(v, alt);
            }
        }
    }

    u = endnode;

    while (previous[u] != NULL){
        result.append(previous[u]->getEdgeTo(u));
        u = previous[u];
    }


}






















