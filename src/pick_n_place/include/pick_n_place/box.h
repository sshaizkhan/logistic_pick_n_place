/**
 * Entity containing required parameters to represent a Box in 3d.
 */
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

    const Coordinate& getCenterCoordinate() const;

    /**
     * Returns the front (i.e. towards the robot's end effector) facing top left coordinate.
     */
    Coordinate getTopLeftCoordinate() const;

    /**
     * Returns the front (i.e. towards the robot's end effector) facing right bottom coordinate.
     */
    Coordinate getBottomRightCoordinate() const;

    /**
     * Constructs the Id using Box center coordinates and returns it.
     */
    std::string getUniqueId();

};

#endif //DEV_SHAHWAZ_KHAN_BOX_H
