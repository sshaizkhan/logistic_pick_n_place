//
// Created by shahwaz on 5/3/21.
//

#include "pick_n_place/camera_manager.h"


std::vector<Box> CameraManager::scanBoxes() {

    return getMockBoxes();
}

std::vector<Box> CameraManager::scanContainers() {

    return getMockContainer();
}
