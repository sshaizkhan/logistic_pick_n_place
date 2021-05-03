//
// Created by shahwaz on 5/3/21.
//

#ifndef DEV_SHAHWAZ_KHAN_CAMERA_MANAGER_H
#define DEV_SHAHWAZ_KHAN_CAMERA_MANAGER_H

#include "pick_n_place/box.h"
#include "bits/stdc++.h"
#include "pick_n_place/mock_data.h"
#include "vector"


class CameraManager {

public:
    static std::vector<Box> scanBoxes();

    static std::vector<Box> scanContainers();

};


#endif //DEV_SHAHWAZ_KHAN_CAMERA_MANAGER_H
