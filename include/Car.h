//
// Created by loewi on 5/26/16.
//

#ifndef PRAKTIKUM3_CAR_H
#define PRAKTIKUM3_CAR_H


#include "Vehicle.h"

class Car : public Vehicle {

    Car(double speed = 60) : speed { speed } {};

    double neededTimeForDistance(double dist) {
        return dist / speed;
    }
};


#endif //PRAKTIKUM3_CAR_H
