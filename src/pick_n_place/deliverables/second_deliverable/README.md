
# LOGISTICS CASE PICKING

## SECOND DELIVERABLE

**Components detail and Implementation plan**

This deliverable is based on the solution presented in the first deliverable. The deliverable consists of brief summary 
of the components and technologies that are used in order to present a solution to the given logistic case picking problem.

Therefore, the various components used as are follows:

* **6 dof Robotic Manipulator**: The selection of the manipulator was based on its reachability and payload capacity. The manipulator 
  should be able to reach a height of 1.5m withing its workspace and carry load between 10 - 15 kg. Based on the given conditions, 
  **_ABB IBR2400 and IBR2600_** would be best suitable for this task. It has reach of 1.55 - 1.85 respectively with load carrying capacity
  from 12 - 20 kg. To read more on this, please [click here.](https://new.abb.com/products/robotics/industrial-robots/robot-selector)

[comment]: <> (  <p align="center">)

[comment]: <> (  <img src="https://drive.google.com/uc?export=view&id=13_EwEY7583n2_S4qesi8AydiIFFW0fBn" alt="Sublime's custom image"/>)

[comment]: <> (</p>)
  

* **Mobile Platform**: Traditionally, the pick and place position are within the workspace of the robotic manipulator but in this problem, having
  a distance of 10m between pick and place position, warrants a mobile platform. The platform should be such that it can carry
  the combined load of manipulator and box, and should be easy to integrate with current system. Based on the formulated conditions,
  **_MAV3K Autonomous Mobile Robot_** by **WAYPOINT ROBOTICS** would be right fit. The platform can carry upto 3000lbs load and has built in LIDAR and ROS-native system architecture.
  To read more this, please [click here.](https://waypointrobotics.com/mav3k-autonomous-mobile-platform/)
  

* **Camera(s)**: Camera plays a important role in an automated material handling environment it can be used to scan items, 
  QR Codes, raw data for object detection and much more. In the given problem, the system consists of three cameras. First
  camera mounted on top of boxes (2m high) for the pose estimation, second camera mounted on top of containers (1.5m high) 
  for scanning and sending QR code of containers to the system and the third camera mounted on robot to scan the QR codes 
  on the box and then send it over to the system for registration and matching with the QR codes of the respective containers. 
  For this purpose, we use industrial cameras which has higher resolution at larger distance like as in our case, so 
  **_COGNEX In-Sight 2000 Vision Sensor_** can accomplish the task. To read more on this, please 
  [click here.](https://www.cognex.com/products/machine-vision/vision-sensors/in-sight-2000-vision-sensors)
  

* **End Effector - Pneumatic Gripper**: The need of pneumatic gripper has been increasing lately because of their versatility 
  ease of use. The pneumatic gripper consists of rubber bellows and are operated using vacuum pressure. Nowadays, multiple 
  bellows are combined together to form a single giant gripper in order to lift heavy load. The high negative pressure is usually
  created using vacuum generator which uses highly compressed air to create a partial vacuum under the bellows to lift the items.
  For this task, four bellows above 6cm diameter and a pressure of roughly 12kPa can easily lift 15kg payload.
  

