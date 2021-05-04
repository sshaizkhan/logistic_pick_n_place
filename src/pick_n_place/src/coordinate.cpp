//
// Created by shahwaz on 5/3/21.
//

#include "pick_n_place/coordinate.h"

Coordinate::Coordinate(double x, double y, double z) : x(x), y(y), z(z) {}

double Coordinate::getX() const {
    return x;
}

double Coordinate::getY() const {
    return y;
}

double Coordinate::getZ() const {
    return z;
}

std::ostream& operator<<(std::ostream& stream,
                         const Coordinate& obj) {
    stream<<"{ ";
    stream<<"x: "<<obj.getX();
    stream<<", y: "<<obj.getY();
    stream<<", z: "<<obj.getZ();
    stream<<" }"<<std::endl;
    return stream;
}
