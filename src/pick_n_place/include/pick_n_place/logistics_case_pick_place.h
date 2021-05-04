//
// Created by shahwazk@usc.edu on 4/30/21.
//

#ifndef DEV_SHAHWAZ_KHAN_LOGISTICS_CASE_PICK_PLACE_H
#define DEV_SHAHWAZ_KHAN_LOGISTICS_CASE_PICK_PLACE_H

//ROS
#include "ros/ros.h"
#include "ros/package.h"
#include "geometry_msgs/Pose.h"
#include "std_msgs/String.h"
#include "memory"
#include <iostream>

//MoveIt
#include "moveit/planning_scene_interface/planning_scene_interface.h"
#include "moveit/move_group_interface/move_group_interface.h"
#include "moveit_visual_tools/moveit_visual_tools.h"
#include "moveit_msgs/CollisionObject.h"
#include "geometric_shapes/shape_operations.h"

#include <moveit_msgs/PlanningScene.h>
#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/GetStateValidity.h>
#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/ApplyPlanningScene.h>

#include <moveit/robot_model_loader/robot_model_loader.h>
#include <moveit/robot_state/robot_state.h>
#include <moveit/robot_state/conversions.h>

//TF
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"

#include "pick_n_place/box.h"
#include "pick_n_place/mock_data.h"
#include "pick_n_place/coordinate.h"
#include "pick_n_place/camera_manager.h"
#include "pick_n_place/qr_code_scanner.h"


class Pick_Place {
private:
    /*data*/
    QRCodeScanner qrCodeScanner;

    Box pickMatchingQrCodeContainer(const Box &box, std::map<int, Box> &container_map);

    std::map<int, Box> buildContainerQRCodeMap(const std::vector<Box> &containers);

//   Initialise ROS parameters
    ros::NodeHandle nodeHandle;
    //    Moveit Planning Interface
    moveit::planning_interface::MoveGroupInterfacePtr abb_group_ptr;

    void addTable(std::string &object_id, double x, double y, double z);

    void addBoxes(Box &box);

    void addContainers(Box &container);

    void spawnTables();

    void spawnBoxes();

    void spawnContainers();

    static Coordinate calculateBoxPickPose(const Box &box);

    void updatePlanningScene();

    bool moveToPickPose(const Coordinate &target_position);

    bool moveToPlacePose(const Coordinate &target_position);

    void attachCollisionObjects(std::string object_id);

    void detachCollisionObjects(std::string object_id);

    void pickBox(Box box);

    void placeBox(Coordinate coordinate);

    static void printVector(std::vector<std::string> &input);

    void homePosition();

    //    Initializing Move Group Parameters
    moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
    moveit::planning_interface::MoveGroupInterface::Plan abb_goal_plan;

//    Publishers and Subscribers
    ros::Publisher planning_scene_publisher;
public:
    Pick_Place();
    void spawnEnvironment();
    void run();

};

#endif //DEV_SHAHWAZ_KHAN_LOGISTICS_CASE_PICK_PLACE_H
