/**
 * Module responsible for scanning QR Code within a specified dimension.
 */
#ifndef DEV_SHAHWAZ_KHAN_BOX_QR_CODE_DETECTION_H
#define DEV_SHAHWAZ_KHAN_BOX_QR_CODE_DETECTION_H

#include "pick_n_place/box.h"

class QRCodeScanner {
private:
    std::queue<int> non_used_container_qr_codes;
    std::queue<int> non_used_box_qr_codes;
    int maximum_qr_code_till_now;

    /**
     * Scans the front facing plane (2 dimensional) of the box between top_left_coordinate and right_bottom_coordinate.
     * @param top_left_coordinate  Top left coordinate of the Box on the front facing side.
     * @param right_bottom_coordinate Bottom right coordinate of the Box on the front facing side.
     * @return QR code present between two coordinates belonging to the vertical 2d plane.
     */
    int getQRCodeByScanningWithinBoxEdgePoints(const Coordinate &top_left_coordinate,
                                               const Coordinate &right_bottom_coordinate);

    /**
     * Scans the front facing plane (2 dimensional) of the container between top_left_coordinate and right_bottom_coordinate.
     * @param top_left_coordinate  Top left coordinate of the Box on the front facing side.
     * @param right_bottom_coordinate Bottom right coordinate of the Box on the front facing side.
     * @return QR code present between two coordinates belonging to the vertical 2d plane.
     */
    int getQRCodeByScanningWithinContainerEdgePoints(const Coordinate &top_left_coordinate,
                                                     const Coordinate &right_bottom_coordinate);

public:

    QRCodeScanner();

    /**
     * Returns the QR code by scanning within Box bounds.
     */
    int fetchBoxQRCode(const Box &box);

    /**
     * Returns the QR code by scanning within Container bounds.
     */
    int fetchContainerQRCode(const Box &container);

};

#endif //DEV_SHAHWAZ_KHAN_BOX_QR_CODE_DETECTION_H
