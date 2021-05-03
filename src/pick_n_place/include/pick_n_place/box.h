//
// Created by shahwaz on 5/3/21.
//

#ifndef DEV_SHAHWAZ_KHAN_BOX_H
#define DEV_SHAHWAZ_KHAN_BOX_H

#include "pick_n_place/coordinate.h"
#include "bits/stdc++.h"

class Box {
private:
    double depth;
    double length;
    double height;
    Coordinate center_coordinate;

public:

    Box(double length, double width, double depth, const Coordinate &centerCoordinate);

    /* Dimension along Y-axis*/
    double getLength() const;

    /* Dimension along Z-axis*/
    double getHeight() const;

    /* Dimension along X-axis*/
    double getDepth() const;

    const Coordinate &getCenterCoordinate() const;

    Coordinate getTopLeftCoordinate();

    Coordinate getBottomRightCoordinate();

    std::string getUniqueId();

};



#endif //DEV_SHAHWAZ_KHAN_BOX_H
