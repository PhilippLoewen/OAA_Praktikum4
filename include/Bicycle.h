//
// Created by loewi on 5/26/16.
//

#ifndef PRAKTIKUM3_BICYCLE_H
#define PRAKTIKUM3_BICYCLE_H


#include "Vehicle.h"

class Bicycle : protected Vehicle {

    Bicycle ( double speed = 30) : speed { speed } {};

    double neededTimeForDistance(double dist) {
        return dist / speed;
    }

};


#endif //PRAKTIKUM3_BICYCLE_H
