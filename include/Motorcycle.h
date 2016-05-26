//
// Created by loewi on 5/26/16.
//

#ifndef PRAKTIKUM3_MOTORCYCLE_H
#define PRAKTIKUM3_MOTORCYCLE_H


class Motorcycle : protected Vehicle {

    Motorcycle ( double speed = 90) : speed { speed } {};

    double neededTimeForDistance(double dist) {
        return dist / speed;
    }

};


#endif //PRAKTIKUM3_MOTORCYCLE_H
