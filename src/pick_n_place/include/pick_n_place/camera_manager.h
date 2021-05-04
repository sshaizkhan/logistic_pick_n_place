/**
 * Module responsible for returning Box & Containers dimensions using Camera situated on Box and Containers rail.
 */
#ifndef DEV_SHAHWAZ_KHAN_CAMERA_MANAGER_H
#define DEV_SHAHWAZ_KHAN_CAMERA_MANAGER_H

#include "pick_n_place/box.h"
#include "bits/stdc++.h"
#include "pick_n_place/mock_data.h"
#include "vector"

/**
 * Returns list of boxes scanned by the Camera situated on top of Boxes rail.
 * It has been assumed that the camera is capable enough of detecting center_coordinate
 * including length, depth and height of each box.
 */
std::vector<Box> scanBoxes();

/**
 * Returns list of containers scanned by the Camera situated on top of Containers rail.
 * It has been assumed that the camera is capable enough of detecting center_coordinate
 * including length, depth and height of each box.
 */
std::vector<Box> scanContainers();

#endif //DEV_SHAHWAZ_KHAN_CAMERA_MANAGER_H
