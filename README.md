
[comment]: <> ([![Contributors][contributors-shield]][contributors-url])

[comment]: <> ([![Forks][forks-shield]][forks-url])

[comment]: <> ([![Stargazers][stars-shield]][stars-url])

[comment]: <> ([![Issues][issues-shield]][issues-url])

[comment]: <> ([![MIT License][license-shield]][license-url])

[comment]: <> ([![LinkedIn][linkedin-shield]][linkedin-url])

<!-- PROJECT LOGO -->
<br />
<p align="center">
  <a href="https://www.shutterstock.com/image-vector/collect-pick-order-icon-package-box-1879519894">
    <img src="src/resources/pick_place_logo.jpg" alt="Logo" width="80" height="80">
  </a>

<h3 align="center">Logistic Case Picking Operation</h3>


<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#build">Build</a></li>
    <li>
      <a href="#involved-components">Involved Components</a>
      <ul>
        <li><a href="#mobile-bot">Mobile Bot</a></li>
        <li><a href="#abb-robot-package">ABB Robot Package</a></li>
      </ul>
    </li>
    <li><a href="#Run">Run</a></li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#assumptions">Assumption</a></li>
    <li><a href="#error-handling">Error Handling</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgements">Acknowledgements</a></li>
  </ol>
</details>


<!-- ABOUT THE PROJECT -->
## About The Project

The aim of the project is to design a realistic solution to a pick a box from a mountain of arranged boxes and place
the box onto its corresponding container. Each container has a different visual marker (bar-code, QR Code, etc.), and each
box has he same marker as the container it should go to. The distance between the mountain of boxes and the containers is 10m.
The boxes weight between 10 and 15kg and their size between 30x30x30 cm and 50x50x50cm, but they are not necessarily equilateral.
The mountain of boxes is not higher than 1.5m.

The project involve three deliverable :

- Description of the solution and summary of its workflow
- Details of the components and plan for the implementation of the solution
- Source code of one of the components

The relevant README files for the above two deliverables are :

1. deliverable - 1  [README](src/pick_n_place/deliverables/first_deliverable/README.md)

2. deliverable - 2  [README](src/pick_n_place/deliverables/second_deliverable/README.md)

### Built With

The project is made using the following framework and hardware:
*[ROS](https://www.ros.org/)
*[C++](https://www.cplusplus.com/)
*[MoveIt](https://moveit.ros.org/)
*[ABB Support Package](https://github.com/ros-industrial/abb.git)
*[Mobile Base](src/mobile_bot)

<!-- GETTING STARTED -->
## Getting Started

To get started with the project, you need to have the following prerequisites installed
in your system.

### Prerequisites

*ROS

  The ROS (Robot Operating System) is a free software, sourced and maintained by
  [Open Robotics](https://www.openrobotics.org/). You must have ROS in order to run this project on your system
        Follow all the instructions to [install ROS Melodic](http://wiki.ros.org/melodic/Installation), including calls to [rosdep]().
  
*MoveIt
  MoveIt is an open source project that is the result of the combined efforts of a large international community and multiple organizations.
  To Install on Ubuntu 18.04:
  
        sudo apt install ros-melodic-moveit

  You can also follow the official [MoveIt website](https://moveit.ros.org/) to know more about it.

### Installation

1. Clone the repo

  ```sh
  git clone https://shahwazk@bitbucket.org/telexistence/dev-shahwaz-khan.git
  ```

<!-- USAGE EXAMPLES -->
## Build

Once you have all the necessary files and hardware arranged, you can build your project.

```sh
cd your_project_directory
catkin_make
```

In order to save processing power, you can also use:

```sh
catkin_make -j7
```

Here, 7 denotes the number of cores you want to assign during make process. You can assign however amount of cores.

<!-- COMPONENTS USED -->

## Involved Components

The two important components involved in this project.


### Mobile Base
Mobile base and ABB IRB2400 Industrial robot. The mobile
base is a carrier for the ABB robot is the primary mode of transportation of Robot from pick place to place position.
The base has a payload capacity of 3000lbs and can easily lift the robot, accompanying power source and weight of the boxes.

The mobile is a four wheel differential drive system and uses a custom package made of SolidWorks designs, URDFs and differential
controllers for left and right back wheels.

To launch the robot on RVIZ and Gazebo,

```sh
source your catkin directory

roslaunch mobilebot_launch diff_drive.launch
```

The corresponding windows that open on RViz and Gazebo along with rqt_steering can be seen in the images below.The working
of the differential wheel drive can also be seen in the video.

### Images
<p align="center">
  <a href="https://drive.google.com/file/d/1e1KW6Z8X4mplqPg4JuSg7ZqsprAp57db/view?usp=sharing">
    <img src="src/resources/rviz.png" alt="Logo" width="800" height="650">
  </a>

###

<p align="center">
  <a href="https://drive.google.com/file/d/1Tj8ectDukG06Gy1YywKBGDEnCmVcy4gh/view?usp=sharing">
    <img src="src/resources/gazebo.png" alt="Logo" width="800" height="650">
  </a>

### Video




### ABB IRB2600 Robot
The ABB robot is a 6 DOF Industrial arm its main task to pick the boxes that can range from 10 -15 kg and place it onto
the corresponding containers. This robot has a payload capacity of 20kg and thus can easily lift the boxes.



<!-- ROADMAP -->

## Run

After building the project, the project can be run for the pick and place operation performed on RViz using MoveIt visualization

```sh
roslaunch pick_n_place robot_planning.launch
```


## Usage
Check out the video to visualize the complete pick and place operation performed by ABB IRB2600 robot mounted over
a mobile base. In the video, it can observed that the robot will successfully complete the pick and place operation
for three robots and then will move to the home position.

![Packaging video](https://drive.google.com/file/d/1ZqCYGY2boIU0i4A6bUEENG2Xz630SbSV/view?usp=sharing)

<!-- ASSUMPTIONS -->

## Assumptions


<!-- ERROR HANDLING -->

## Error Handling


<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request



<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE` for more information.



<!-- CONTACT -->
## Contact

Your Name - [Shahwaz Khan](sshaizkhan@gmail.com)

Project Link:  [Amazon_ws](https://github.com/sshaizkhan/amazon_ws.git)



<!-- ACKNOWLEDGEMENTS -->
## Acknowledgements

[comment]: <> (* [GitHub Emoji Cheat Sheet]&#40;https://www.webpagefx.com/tools/emoji-cheat-sheet&#41;)

[comment]: <> (* [Img Shields]&#40;https://shields.io&#41;)

[comment]: <> (* [Choose an Open Source License]&#40;https://choosealicense.com&#41;)

[comment]: <> (* [GitHub Pages]&#40;https://pages.github.com&#41;)

[comment]: <> (* [Animate.css]&#40;https://daneden.github.io/animate.css&#41;)

[comment]: <> (* [Loaders.css]&#40;https://connoratherton.com/loaders&#41;)

[comment]: <> (* [Slick Carousel]&#40;https://kenwheeler.github.io/slick&#41;)

[comment]: <> (* [Smooth Scroll]&#40;https://github.com/cferdinandi/smooth-scroll&#41;)

[comment]: <> (* [Sticky Kit]&#40;http://leafo.net/sticky-kit&#41;)

[comment]: <> (* [JVectorMap]&#40;http://jvectormap.com&#41;)

[comment]: <> (* [Font Awesome]&#40;https://fontawesome.com&#41;)





[comment]: <> (<!-- MARKDOWN LINKS & IMAGES -->)

[comment]: <> (<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->)

[comment]: <> ([contributors-shield]: https://img.shields.io/github/contributors/othneildrew/Best-README-Template.svg?style=for-the-badge)

[comment]: <> ([contributors-url]: https://github.com/othneildrew/Best-README-Template/graphs/contributors)

[comment]: <> ([forks-shield]: https://img.shields.io/github/forks/othneildrew/Best-README-Template.svg?style=for-the-badge)

[comment]: <> ([forks-url]: https://github.com/othneildrew/Best-README-Template/network/members)

[comment]: <> ([stars-shield]: https://img.shields.io/github/stars/othneildrew/Best-README-Template.svg?style=for-the-badge)

[comment]: <> ([stars-url]: https://github.com/othneildrew/Best-README-Template/stargazers)

[comment]: <> ([issues-shield]: https://img.shields.io/github/issues/othneildrew/Best-README-Template.svg?style=for-the-badge)

[comment]: <> ([issues-url]: https://github.com/othneildrew/Best-README-Template/issues)

[comment]: <> ([license-shield]: https://img.shields.io/github/license/othneildrew/Best-README-Template.svg?style=for-the-badge)

[comment]: <> ([license-url]: https://github.com/othneildrew/Best-README-Template/blob/master/LICENSE.txt)

[comment]: <> ([linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555)

[comment]: <> ([linkedin-url]: https://linkedin.com/in/othneildrew)

[comment]: <> ([product-screenshot]: images/screenshot.png)
