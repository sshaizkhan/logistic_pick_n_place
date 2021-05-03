//
// Created by shahwaz on 5/3/21.
//

#include "pick_n_place/box.h"

/* Represents the maximum coordinate value for box in either x, y or z direction*/
const int MAX_COORDINATE_LIMIT = 100000;

Box::Box(double length, double height, double depth, const Coordinate &centerCoordinate) : length(length), height(height), depth(depth),
                                                                                          center_coordinate(centerCoordinate) {}

double Box::getLength() const {
    return length;
}

double Box::getHeight() const {
    return height;
}

double Box::getDepth() const {
    return depth;
}
const Coordinate &Box::getCenterCoordinate() const {
    return center_coordinate;
}

Coordinate Box::getTopLeftCoordinate() {

    return {center_coordinate.getX()
                      , center_coordinate.getY() - length/2,
            center_coordinate.getZ() - height / 2};
}

Coordinate Box::getBottomRightCoordinate() {

    return {center_coordinate.getX()
            , center_coordinate.getY() + length/2,
            center_coordinate.getZ() + height / 2};
}

std::string Box::getUniqueId() {

    return std::to_string(center_coordinate.getZ() * MAX_COORDINATE_LIMIT + center_coordinate.getY()*MAX_COORDINATE_LIMIT/10
                          + center_coordinate.getX() * MAX_COORDINATE_LIMIT/100) ;
}





