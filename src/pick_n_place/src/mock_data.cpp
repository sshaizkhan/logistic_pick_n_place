//
// Created by shahwaz on 5/3/21.
//

#include "pick_n_place/mock_data.h"

const double DISTANCE_ROBOT_TO_BOXES = 1.5;
const double DISTANCE_ROBOT_TO_CONTAINERS = -1.5;

const double BOX_LENGTH = 0.5;
const double BOX_HEIGHT = 0.5;
const double BOX_DEPTH = 0.5;

const double CONTAINER_LENGTH = 0.6;
const double CONTAINER_HEIGHT = 0.1;
const double CONTAINER_DEPTH = 0.6;

std::vector<Box> getMockBoxes()
{
    std::vector<Box> mock_boxes;
    mock_boxes.emplace_back(BOX_LENGTH, BOX_HEIGHT, BOX_DEPTH, Coordinate(DISTANCE_ROBOT_TO_BOXES, 0.51, 0.67 ));
    mock_boxes.emplace_back(BOX_LENGTH, BOX_HEIGHT, BOX_DEPTH, Coordinate(DISTANCE_ROBOT_TO_BOXES, -0.51, 0.67 ));
    mock_boxes.emplace_back(BOX_LENGTH, BOX_HEIGHT, BOX_DEPTH, Coordinate(DISTANCE_ROBOT_TO_BOXES, 0.26, 1.17 ));
    mock_boxes.emplace_back(BOX_LENGTH, BOX_HEIGHT, BOX_DEPTH, Coordinate(DISTANCE_ROBOT_TO_BOXES, 0, 1.67 ));
    mock_boxes.emplace_back(BOX_LENGTH, BOX_HEIGHT, BOX_DEPTH, Coordinate(DISTANCE_ROBOT_TO_BOXES, 0.0, 0.67 ));
    mock_boxes.emplace_back(BOX_LENGTH, BOX_HEIGHT, BOX_DEPTH, Coordinate(DISTANCE_ROBOT_TO_BOXES, -0.25, 1.17 ));

    return mock_boxes;
}
std::vector<Box> getMockContainer()
{
    std::vector<Box> mock_containers;
    mock_containers.emplace_back(CONTAINER_LENGTH, CONTAINER_HEIGHT, CONTAINER_DEPTH,Coordinate(DISTANCE_ROBOT_TO_CONTAINERS,-0.61, 0.42 ));
    mock_containers.emplace_back(CONTAINER_LENGTH, CONTAINER_HEIGHT, CONTAINER_DEPTH,Coordinate(DISTANCE_ROBOT_TO_CONTAINERS,0.0, 0.42 ));
    mock_containers.emplace_back(CONTAINER_LENGTH, CONTAINER_HEIGHT, CONTAINER_DEPTH, Coordinate(DISTANCE_ROBOT_TO_CONTAINERS,0.61, 0.42 ));

    return mock_containers;
}