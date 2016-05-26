#include <iostream>

#include "DiGraph.h"
#include "OpenCVGraphVisualizer.h"
#include <ctime>

#define ANZAHL 10
#define AUFLX 1500
#define AUFLY 960
#define BEREICHX (AUFLX - 199)
#define BEREICHY (AUFLY - 199)

std::string ranStr(int size) {
    int i;
    std::string str;
    for (i = 0; i < size; ++i) {
        str.push_back((char)((rand() % 26) + 'A'));
    }
    return str;
}


int main() {

    std::srand( static_cast<unsigned int>(std::time(NULL)));
    std::string keys[ANZAHL];
    int posx[ANZAHL];
    int posy[ANZAHL];
    DiGraph diGraph;
    Node node[ANZAHL];
    for (int i = 0; i < ANZAHL; i++) {
        keys[i] = ranStr(3);
        posx[i] = (std::rand() % BEREICHX) + 100;
        posy[i] = (std::rand() % BEREICHY) + 100;
        node[i].setKey(keys[i]);
        node[i].setPositionX(posx[i]);
        node[i].setPositionY(posy[i]);
        diGraph.addNode(&node[i]);
        if (i > 0) {
            diGraph.addEdge(keys[i - 1], keys[i], std::rand() % 10);

        }

    }


    OpenCVGraphVisualizer ogv(AUFLX,AUFLY);



    ogv.render(diGraph);
    ogv.show();

    return 0;
}