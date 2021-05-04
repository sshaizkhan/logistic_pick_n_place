/**
 * Mock implementation of QRCodeScanner which ensures that each QR code assigned to
 * container has a equivalent match in the Box and vice-versa.
 */
#include "pick_n_place/qr_code_scanner.h"



void QRCodeScanner::clearQueue(std::queue<int> queue){
    while(!queue.empty()){
        queue.pop();
    }
}
QRCodeScanner::QRCodeScanner() {
    maximum_qr_code_till_now=0;
}

void mockFailedToScanQRCodeException(){
    int random_value=std::rand()% 5;
    if(random_value==0){
        throw FailedToScanQRCode("Failed to scan QR code. Please retry.");
    }
}

int QRCodeScanner::getQRCodeByScanningWithinBoxEdgePoints(const Coordinate& top_left_coordinate, const Coordinate& right_bottom_coordinate )
{
    mockFailedToScanQRCodeException();
    if(!non_used_container_qr_codes.empty()){
        int qr_code=non_used_container_qr_codes.front();
        std::cout<<"Returning qr_code "<<qr_code<<" for the box "<<std::endl;
        non_used_container_qr_codes.pop();
        return qr_code;
    }
    maximum_qr_code_till_now+=1;
    std::cout<<"Pushing qr_code to box "<<maximum_qr_code_till_now<<std::endl;
    non_used_box_qr_codes.push(maximum_qr_code_till_now);
    return maximum_qr_code_till_now;
}

int QRCodeScanner::getQRCodeByScanningWithinContainerEdgePoints(const Coordinate& top_left_coordinate, const Coordinate& right_bottom_coordinate )
{
    mockFailedToScanQRCodeException();
    if(!non_used_box_qr_codes.empty()){
        int qr_code=non_used_box_qr_codes.front();
        std::cout<<"Returning qr_code "<<qr_code<<" for the container "<<std::endl;
        non_used_box_qr_codes.pop();
        return qr_code;
    }
    maximum_qr_code_till_now+=1;
    std::cout<<"Pushing qr_code to container "<<maximum_qr_code_till_now<<std::endl;
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

QRCodeScanner::~QRCodeScanner() {
    clearQueue(non_used_container_qr_codes);
    clearQueue(non_used_box_qr_codes);
}

FailedToScanQRCode::FailedToScanQRCode(const std::string message) noexcept :
        m_message(message)
{
    std::cout << this->m_message << std::endl;
}

const char *FailedToScanQRCode::what() const noexcept
{
    return this->m_message.c_str();
}

