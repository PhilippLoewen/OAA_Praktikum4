//
// Created by loewi on 5/26/16.
//

#ifndef PRAKTIKUM3_MOTORCYCLE_H
#define PRAKTIKUM3_MOTORCYCLE_H


#include "Vehicle.h"

class Motorcycle : public Vehicle {

public:

    Motorcycle ( double speed = 90) : Vehicle ( speed ) {};

    double neededTimeForDistance(double dist) {
        return dist / speed;
    }

};


#endif //PRAKTIKUM3_MOTORCYCLE_H
