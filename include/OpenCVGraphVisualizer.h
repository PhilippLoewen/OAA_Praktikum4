//
// Created by loewi on 27.04.16.
//

#ifndef PRAKTIKUM3_OPENCVGRAPHVISUALIZER_H
#define PRAKTIKUM3_OPENCVGRAPHVISUALIZER_H


#include <cv.hpp>
#include <highgui.h>
#include <math.h>
#include <sstream>
#include "GraphVisualizer.h"
#include "DiGraph.h"
#include "Node.h"
#include "Edge.h"

#define NODERADIUS 30

class OpenCVGraphVisualizer : public GraphVisualizer {

private:
    cv::Mat img;

public:
    OpenCVGraphVisualizer() {
        this->img = cv::Mat::zeros(768, 1024, CV_8UC3);
    }
    OpenCVGraphVisualizer(int x, int y) {
        this->img = cv::Mat::zeros(y, x, CV_8UC3);
    }

    void render(DiGraph &g) {
        this->img.setTo(cv::Scalar(255, 255, 255));
        std::vector<Node *> nodes = g.getNodes();

        for(int i = 0; i < nodes.size(); i++) {
            drawNode(*nodes[i],cv::Scalar(0,0,0));
            std::vector<Edge *> edges = nodes[i]->getEdges();
            for (int j = 0; j < edges.size(); j++) {
                 drawEdge(*edges[j], cv::Scalar(0,0,0),edges[j]->getWeight());
             }
        }

    }

    virtual void show() {

        cv::namedWindow("Graph");
        //cvStartWindowThread();
        cv::imshow("Graph", this->img);
        cv::waitKey();
        cvDestroyAllWindows();
    }

    void drawNode(Node &node, cv::Scalar nodeColor) {
        cv::Point center(node.getPositionX(), node.getPositionY());
        cv::circle(this->img, center, NODERADIUS, nodeColor, 1, CV_AA);
        int baseline = 0;
        cv::Size textSize = getTextSize(node.getKey(), cv::FONT_HERSHEY_TRIPLEX, 0.5, 1, &baseline);
        cv::Point centerText(node.getPositionX() - (textSize.width / 2),
                             node.getPositionY() - (textSize.height / 2) + baseline * 2);
        cv::putText(this->img, node.getKey(), centerText, cv::FONT_HERSHEY_TRIPLEX, 0.5, cv::Scalar(0, 0, 0), 1, CV_AA);
    }

    void drawEdge(Edge &edge, cv::Scalar color, double weight, int thickness = 1, int arrowMagnitude = 20) {

        cv::Point p(edge.getStartNode()->getPositionX(), edge.getStartNode()->getPositionY());

        cv::Point q(edge.getEndNode()->getPositionX(), edge.getEndNode()->getPositionY());

        // Berechne den Winkel
        const double PI = 3.141592653;
        double angle = atan2((double) p.y - q.y, (double) p.x - q.x);

        // Berechne verkuerzten Pfeil
        q.x = (int) (q.x + NODERADIUS * cos(angle));
        q.y = (int) (q.y + NODERADIUS * sin(angle));
        p.x = (int) (p.x - NODERADIUS * cos(angle));
        p.y = (int) (p.y - NODERADIUS * sin(angle));

        // Zeichne Hauptlinie
        cv::line(img, p, q, color, thickness, CV_AA);
        int size = (int) sqrt(pow(p.x - q.x, 2) + pow(p.y - q.y, 2));
        cv::Point weightpoint( p.x - (size / 2) * cos(angle) + 10 * sin(angle), p.y - (size / 2) * sin(angle) + 10 * cos(angle));
        std::stringstream weightstring;
        weightstring << weight;
        cv::putText(this->img, weightstring.str(), weightpoint, cv::FONT_HERSHEY_TRIPLEX, 0.5, CV_RGB(255, 0, 0), 1, CV_AA);

        //Erstes Segment
        p.x = (int) (q.x + arrowMagnitude * cos(angle + PI / 8));
        p.y = (int) (q.y + arrowMagnitude * sin(angle + PI / 8));
        cv::line(img, p, q, color, thickness, CV_AA);

        // Zweites Segment
        p.x = (int) (q.x + arrowMagnitude * cos(angle - PI / 8));
        p.y = (int) (q.y + arrowMagnitude * sin(angle - PI / 8));
        cv::line(img, p, q, color, thickness, CV_AA);
    }

    void highlightPath(std::vector<Edge*> path) {
        for (Edge* edge : path){
            drawEdge(*edge, cv::Scalar(255,0,0),edge->getWeight(), 2);
        }
    }
};

#endif //PRAKTIKUM3_OPENCVGRAPHVISUALIZER_H
