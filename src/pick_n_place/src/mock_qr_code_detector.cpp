//
// Created by shahwaz on 5/3/21.
//

#include "pick_n_place/qr_code_detector.h"

int box_id;
int container_id;
int getQRCodeByBoxEdgePoints(Coordinate top_left_coordinate, Coordinate right_bottom_coordinate )
{
    return 0;
}

int getQRCodeByContainerEdgePoints(Coordinate top_left_coordinate, Coordinate right_bottom_coordinate )
{
    return 0;
}


int getQRCodeBox(Box& box)
{
    return getQRCodeByBoxEdgePoints(box.getTopLeftCoordinate(), box.getBottomRightCoordinate());
}

int getQRContainer(Box& container)
{
    return getQRCodeByContainerEdgePoints(container.getTopLeftCoordinate(), container.getBottomRightCoordinate());

}

