//
// Created by shahwazk@usc.edu on 4/30/21.
//

#include "pick_n_place/logistics_case_pick_place.h"

#include <utility>

const double DEPTH_CLEARANCE_FOR_PICKUP = 0.10;
const double HEIGHT_CLEARANCE_FOR_PLACE = 0.2;
const double DEPTH_OFFSET_FOR_PLACE=0.2;

Pick_Place::Pick_Place() {

    std::cout << "LOADING MOVE GROUP FOR ABB IRB2400 INDUSTRIAL ROBOT" << std::endl;
    moveit::planning_interface::MoveGroupInterface::Options Options{PLANNING_GROUP, ROBOT_DESCRIPTION, nodeHandle};

    abb_group_ptr = std::make_shared<moveit::planning_interface::MoveGroupInterface>(Options);
    abb_group_ptr->setPlanningTime(5);
    abb_group_ptr->setNumPlanningAttempts(3);
    abb_group_ptr->setPlannerId("RRTConnect");
    joint_model_group = abb_group_ptr->getCurrentState()->getJointModelGroup(PLANNING_GROUP);
    planning_scene_monitor = std::make_shared<planning_scene_monitor::PlanningSceneMonitor>(ROBOT_DESCRIPTION);

    joint_names = joint_model_group->getVariableNames();
    link_names = joint_model_group->getLinkModelNames();

    abb_group_ptr->setGoalTolerance(0.001);
    abb_group_ptr->allowReplanning(true);

    std::cout << "Joint Names: \n";
    printVector(joint_names);

    std::cout << "Link Names: \n";
    printVector(link_names);

    planning_scene_publisher = nodeHandle.advertise<moveit_msgs::PlanningScene>("planning_scene", 1);
}


void Pick_Place::addTable(std::string &object_id, double x, double y, double z) {

//    Creating Table Environment
    /* collision object created */
    moveit_msgs::CollisionObject collision_object;

    /*Adding table to places boxes */
    collision_object.id = object_id;
    collision_object.header.frame_id = abb_group_ptr->getPlanningFrame();

    /* Define the primitive and its dimensions */
    collision_object.primitives.resize(1);
    collision_object.primitives[0].type = collision_object.primitives[0].BOX;
    collision_object.primitives[0].dimensions.resize(3);
    collision_object.primitives[0].dimensions[0] = 1.0;
    collision_object.primitives[0].dimensions[1] = 2.5;
    collision_object.primitives[0].dimensions[2] = 0.42;

    /* Define the pose of the table */
    collision_object.primitive_poses.resize(1);
    collision_object.primitive_poses[0].position.x = x;
    collision_object.primitive_poses[0].position.y = y;
    collision_object.primitive_poses[0].position.z = z;

    collision_object.primitive_poses[0].orientation.x = 0.0;
    collision_object.primitive_poses[0].orientation.y = 0.0;
    collision_object.primitive_poses[0].orientation.z = 0.0;
    collision_object.primitive_poses[0].orientation.w = 1.0;

    /* Object added to planning scene */
    collision_object.operation = collision_object.ADD;
    planning_scene_interface.applyCollisionObject(collision_object);
}

void Pick_Place::addBoxes(Box &box) {

    //    Creating Box Environment
    /* collision object created */
    moveit_msgs::CollisionObject collision_object;

//    Adding table to places containers
    collision_object.id = box.getUniqueId();
    collision_object.header.frame_id = abb_group_ptr->getPlanningFrame();

    /* Define the primitive and its dimensions */
    collision_object.primitives.resize(1);
    collision_object.primitives[0].type = collision_object.primitives[0].BOX;
    collision_object.primitives[0].dimensions.resize(3);
    collision_object.primitives[0].dimensions[0] = box.getDepth();
    collision_object.primitives[0].dimensions[1] = box.getLength();
    collision_object.primitives[0].dimensions[2] = box.getHeight();

    /* Define the pose of the box */
    collision_object.primitive_poses.resize(1);
    collision_object.primitive_poses[0].orientation.x = 0.0;
    collision_object.primitive_poses[0].orientation.y = 0.0;
    collision_object.primitive_poses[0].orientation.z = 0.0;
    collision_object.primitive_poses[0].orientation.w = 1.0;

    collision_object.primitive_poses[0].position.x = box.getCenterCoordinate().getX();
    collision_object.primitive_poses[0].position.y = box.getCenterCoordinate().getY();
    collision_object.primitive_poses[0].position.z = box.getCenterCoordinate().getZ();


    /* Object added to planning scene */
    collision_object.operation = collision_object.ADD;
    planning_scene_interface.applyCollisionObject(collision_object);
}

void Pick_Place::addContainers(Box &container) {

//    Creating Containers Environment
    /* collision object created */
    moveit_msgs::CollisionObject collision_object;

//    Adding table to places containers
    collision_object.id = container.getUniqueId();
    collision_object.header.frame_id = abb_group_ptr->getPlanningFrame();

    /* Creating mesh from STL file of container */
    std::string mesh_from_file = "package://pick_n_place/meshes/collision/container.stl";
    shapes::Mesh *mesh_container = shapes::createMeshFromResource(mesh_from_file);

    /* Defining shape messages */
    shape_msgs::Mesh container_mesh;
    shapes::ShapeMsg container_mesh_msg;
    shapes::constructMsgFromShape(mesh_container, container_mesh_msg);
    container_mesh = boost::get<shape_msgs::Mesh>(container_mesh_msg);

    /* Define the pose of the box */
    geometry_msgs::Pose container_pose;
    container_pose.orientation.x = 0.0;
    container_pose.orientation.y = 0.0;
    container_pose.orientation.z = 0.0;
    container_pose.orientation.w = 1.0;

    container_pose.position.x = container.getCenterCoordinate().getX();
    container_pose.position.y = container.getCenterCoordinate().getY();
    container_pose.position.z = container.getCenterCoordinate().getZ();

    /* Adding mesh to collision object */
    collision_object.meshes.push_back(container_mesh);
    collision_object.mesh_poses.push_back(container_pose);

    /* Object added to planning scene */
    collision_object.operation = collision_object.ADD;
    planning_scene_interface.applyCollisionObject(collision_object);

}

void Pick_Place::spawnBoxes() {
    std::vector<Box> boxes = getMockBoxes();
    for (auto &box : boxes) {
        addBoxes(box);
        std::cout << "B0X " << box.getUniqueId() << " ADDED TO THE PLANNING SCENE" << std::endl;
    }
}

void Pick_Place::spawnContainers() {
    std::vector<Box> containers = getMockContainer();
    for (auto &container : containers) {
        addContainers(container);
        std::cout << "CONTAINER " << container.getUniqueId() << " ADDED TO THE PLANNING SCENE" << std::endl;
    }
}

void Pick_Place::spawnTables() {
    std::string box_table = "table_top_boxes";
    std::string container_table = "table_top_containers";

    addTable(box_table, 1.5, 0.0, 0.21);
    std::cout << "BOXES TABLE ADDED TO THE PLANNING SCENE" << std::endl;

    addTable(container_table, -1.5, 0.0, 0.21);
    std::cout << "CONTAINERS TABLE ADDED TO THE PLANNING SCENE" << std::endl;
}


void Pick_Place::spawnEnvironment() {

    /* Spawning added boxes, containers and tables in the world */
    spawnBoxes();
    spawnContainers();
    spawnTables();
}

Coordinate Pick_Place::calculateBoxPickPose(const Box &box) {
    return {box.getCenterCoordinate().getX() - (box.getDepth() / 2) - DEPTH_CLEARANCE_FOR_PICKUP,
            box.getCenterCoordinate().getY(), box.getCenterCoordinate().getZ()};
}

bool Pick_Place::moveToPickPose(const Coordinate &target_pose) {
    abb_group_ptr->setStartStateToCurrentState();
    geometry_msgs::Pose start_pose;
    start_pose = abb_group_ptr->getCurrentPose().pose;
    std::cout << "Start Pose for Planning is: \n" << start_pose << std::endl;

    geometry_msgs::Pose target_p;
    target_p.position.x = target_pose.getX();
    target_p.position.y = target_pose.getY();
    target_p.position.z = target_pose.getZ();
    target_p.orientation.x = 0.5;
    target_p.orientation.y = 0.5;
    target_p.orientation.z = 0.5;
    target_p.orientation.w = 0.5;

    abb_group_ptr->setPoseTarget(target_p);
    std::cout << "Target Pose for Planning is: \n" << target_p << std::endl;

    bool success = (abb_group_ptr->plan(abb_goal_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
    if (success) {

        std::cout << "PLANNING SUCCESSFUL, MOVING TO DESIGNATED TARGET......." << std::endl;
        abb_group_ptr->move();
//        planning_scene_monitor->startSceneMonitor();
//        planning_scene_monitor->startStateMonitor();
//        planning_scene_monitor->updateSceneWithCurrentState();
//        planning_scene_monitor->triggerSceneUpdateEvent(planning_scene_monitor::PlanningSceneMonitor::SceneUpdateType::UPDATE_STATE );
//        planning_scene_monitor->triggerSceneUpdateEvent(planning_scene_monitor::PlanningSceneMonitor::SceneUpdateType::UPDATE_SCENE );
        updatePlanningScene();
    }
    return success;
}

void Pick_Place::pickBox(Box box) {
    Coordinate box_pick_pose = calculateBoxPickPose(box);

    if (!moveToPickPose(box_pick_pose)) {
        std::cout << "Unable to Plan for the Pre-Pick Position \n";
        std::cout << "Aborting Picking Operation \n";
        return;
    }
}

bool Pick_Place::moveToPlacePose(const Coordinate& place_target_pose) {

    abb_group_ptr->setStartStateToCurrentState();
    geometry_msgs::Pose start_pose;
    start_pose = abb_group_ptr->getCurrentPose().pose;
    std::cout << "Start Pose for Placing is: \n" << start_pose << std::endl;

    geometry_msgs::PoseStamped place_target_p;
    place_target_p.header.frame_id = "base_link";

    place_target_p.pose.position.x = place_target_pose.getX();
    place_target_p.pose.position.y = place_target_pose.getY();
    place_target_p.pose.position.z = place_target_pose.getZ();

    place_target_p.pose.orientation.x = 1.0;
    place_target_p.pose.orientation.y = 0.0;
    place_target_p.pose.orientation.z = 0.0;
    place_target_p.pose.orientation.w = 0.0;

    abb_group_ptr->setPoseTarget(place_target_p);
    std::cout << "Target Pose for Placing is: \n" << place_target_p << std::endl;
    abb_group_ptr->setGoalOrientationTolerance(0.0000000001);

    bool success = (abb_group_ptr->plan(abb_goal_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
    if (success) {
        ros::WallDuration(3).sleep();
        ROS_INFO("Planning successful, moving to designated goal");
        abb_group_ptr->move();
//        planning_scene_monitor->startSceneMonitor();
//        planning_scene_monitor->startStateMonitor();
//        planning_scene_monitor->updateSceneWithCurrentState();
//        planning_scene_monitor->triggerSceneUpdateEvent(planning_scene_monitor::PlanningSceneMonitor::SceneUpdateType::UPDATE_STATE );
//        planning_scene_monitor->triggerSceneUpdateEvent(planning_scene_monitor::PlanningSceneMonitor::SceneUpdateType::UPDATE_SCENE );
        updatePlanningScene();

    }
    return success;
}

void Pick_Place::placeBox(Coordinate center_position) {

    if (!moveToPlacePose(Coordinate(center_position.getX()+DEPTH_OFFSET_FOR_PLACE, center_position.getY(),
                                        center_position.getZ() + HEIGHT_CLEARANCE_FOR_PLACE))) {
        std::cout << "UNABLE TO PLAN FOR PLACE POSITION \n";
        std::cout << "ABORTING PLACE OPERATION \n";
        return;
    }
}

void Pick_Place::updatePlanningScene() {
    moveit_msgs::PlanningScene planning_scene;
    planning_scene.robot_state.is_diff = true;
    planning_scene.is_diff = true;
    planning_scene_interface.applyPlanningScene(planning_scene);
    planning_scene_publisher.publish(planning_scene);
}

void Pick_Place::attachCollisionObjects(std::string object_id) {

    ROS_INFO("Attaching box to the suction gripper");
    moveit_msgs::AttachedCollisionObject attached_object;
    attached_object.link_name = "suction_cup_end_effector";
    attached_object.object.header.frame_id = abb_group_ptr->getPlanningFrame();
    attached_object.object.id = std::move(object_id);
    attached_object.touch_links = std::vector<std::string>{"suction_cup_end_effector", "tool0"};

    planning_scene_interface.applyAttachedCollisionObject(attached_object);
    updatePlanningScene();
}

void Pick_Place::detachCollisionObjects(std::string object_id) {
    ROS_INFO("Detaching box from the suction gripper");
    moveit_msgs::AttachedCollisionObject detach_object;
    detach_object.object.operation = detach_object.object.REMOVE;
    detach_object.link_name = "suction_cup_end_effector";
    detach_object.object.header.frame_id = abb_group_ptr->getPlanningFrame();
    detach_object.object.id = std::move(object_id);

    planning_scene_interface.applyAttachedCollisionObject(detach_object);
    updatePlanningScene();
}

void Pick_Place::homePosition() {
    std::vector<double> target_joint_angles = {-1.57, 0, 0, 0, 0, 0};
    abb_group_ptr->setStartStateToCurrentState();
    abb_group_ptr->setJointValueTarget(target_joint_angles);

    bool success = (abb_group_ptr->plan(abb_goal_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
    if (success) {
        std::cout << "MOVING TO HOME POSITION" << std::endl;
        abb_group_ptr->move();
    }
    updatePlanningScene();
}


void Pick_Place::run() {
    std::vector<Box> boxes = scanBoxes();
    auto comp = [](Box a, Box b) {
        if (a.getCenterCoordinate().getZ() == b.getCenterCoordinate().getZ()) {
            return a.getCenterCoordinate().getY() <= b.getCenterCoordinate().getY();
        }
        return a.getCenterCoordinate().getZ() <= b.getCenterCoordinate().getZ();
    };
    std::priority_queue<Box, std::vector<Box>, decltype(comp)>
            pq(comp);
    for (auto box:boxes) {
        pq.push(box);
    }

    for (auto & container : scanContainers()) {
        Box box = pq.top();
        pickBox(box);
        pq.pop();
        ros::Duration(1).sleep();
        attachCollisionObjects(box.getUniqueId());
        placeBox(container.getCenterCoordinate());
        detachCollisionObjects(box.getUniqueId());
    }

    std::cout << "OPERATION TERMINATED SUCCESSFULLY" << std::endl;
    homePosition();
}


void Pick_Place::printVector(std::vector<std::string> &input) {

    /* lambda expression to print vector*/
    std::cout << " [ ";
    for_each(input.begin(), input.end(), [](const std::string &i) {
                 std::cout << i << " ";
             }
    );
    std::cout << "]" << std::endl;
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "logistic_case_picking");
    ros::AsyncSpinner spinner(1);
    spinner.start();

    Pick_Place abb_robot;
    abb_robot.spawnEnvironment();
    abb_robot.run();

    ros::waitForShutdown();

    return 0;
}
