//
// Created by loewi on 5/26/16.
//

#ifndef PRAKTIKUM3_VEHICLE_H
#define PRAKTIKUM3_VEHICLE_H


class Vehicle {
protected:

    double speed;

public:
    virtual double neededTimeForDistance(double dist) = 0;

    Vehicle (double speed = 50) : speed { speed } {};

};


#endif //PRAKTIKUM3_VEHICLE_H
