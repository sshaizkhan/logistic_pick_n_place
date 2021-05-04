/**
 * Mock implementation of QRCodeScanner which ensures that each QR code assigned to
 * container has a equivalent match in the Box and vice-versa.
 */
#include "pick_n_place/qr_code_detector.h"


QRCodeScanner::QRCodeScanner() {
    while(!non_used_container_qr_codes.empty()){
        non_used_container_qr_codes.pop();
    }
    while(!non_used_box_qr_codes.empty()){
        non_used_box_qr_codes.pop();
    }
    maximum_qr_code_till_now=0;
}

int QRCodeScanner::getQRCodeByScanningWithinBoxEdgePoints(const Coordinate& top_left_coordinate, const Coordinate& right_bottom_coordinate )
{
    if(!non_used_container_qr_codes.empty()){
        int qr_code=non_used_container_qr_codes.front();
        non_used_container_qr_codes.pop();
        return qr_code;
    }
    maximum_qr_code_till_now+=1;
    non_used_box_qr_codes.push(maximum_qr_code_till_now);
    return maximum_qr_code_till_now;
}

int QRCodeScanner::getQRCodeByScanningWithinContainerEdgePoints(const Coordinate& top_left_coordinate, const Coordinate& right_bottom_coordinate )
{
    if(!non_used_box_qr_codes.empty()){
        int qr_code=non_used_box_qr_codes.front();
        non_used_box_qr_codes.pop();
        return qr_code;
    }
    maximum_qr_code_till_now+=1;
    non_used_container_qr_codes.push(maximum_qr_code_till_now);
    return maximum_qr_code_till_now;
}

int  QRCodeScanner::fetchBoxQRCode(const Box& box)
{
    return getQRCodeByScanningWithinBoxEdgePoints(box.getTopLeftCoordinate(), box.getBottomRightCoordinate());
}

int  QRCodeScanner::fetchContainerQRCode(const Box& container)
{
    return getQRCodeByScanningWithinContainerEdgePoints(container.getTopLeftCoordinate(), container.getBottomRightCoordinate());

}

