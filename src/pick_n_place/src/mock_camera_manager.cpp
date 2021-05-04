
/**
 * Mock Camera manager which returns predefined Boxes and Containers.
 */
#include "pick_n_place/camera_manager.h"

std::vector<Box> scanBoxes() {

    return getMockBoxes();
}

std::vector<Box> scanContainers() {

    return getMockContainer();
}
