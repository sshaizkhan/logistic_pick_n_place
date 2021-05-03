//
// Created by shahwaz on 5/3/21.
//

#ifndef DEV_SHAHWAZ_KHAN_COORDINATE_H
#define DEV_SHAHWAZ_KHAN_COORDINATE_H


class Coordinate {

private:
    double x;
    double y;
    double z;

public:
    Coordinate(double x, double y, double z);

    double getX() const;

    double getY() const;

    double getZ() const;

};


#endif //DEV_SHAHWAZ_KHAN_COORDINATE_H
