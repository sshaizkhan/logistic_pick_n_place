# Install script for directory: /home/shahwaz/Documents/dev-shahwaz-khan/src/abb/abb_irb2400_support

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/shahwaz/Documents/dev-shahwaz-khan/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/shahwaz/Documents/dev-shahwaz-khan/build/abb/abb_irb2400_support/catkin_generated/installspace/abb_irb2400_support.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/abb_irb2400_support/cmake" TYPE FILE FILES
    "/home/shahwaz/Documents/dev-shahwaz-khan/build/abb/abb_irb2400_support/catkin_generated/installspace/abb_irb2400_supportConfig.cmake"
    "/home/shahwaz/Documents/dev-shahwaz-khan/build/abb/abb_irb2400_support/catkin_generated/installspace/abb_irb2400_supportConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/abb_irb2400_support" TYPE FILE FILES "/home/shahwaz/Documents/dev-shahwaz-khan/src/abb/abb_irb2400_support/package.xml")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/abb_irb2400_support" TYPE DIRECTORY FILES
    "/home/shahwaz/Documents/dev-shahwaz-khan/src/abb/abb_irb2400_support/config"
    "/home/shahwaz/Documents/dev-shahwaz-khan/src/abb/abb_irb2400_support/launch"
    "/home/shahwaz/Documents/dev-shahwaz-khan/src/abb/abb_irb2400_support/meshes"
    "/home/shahwaz/Documents/dev-shahwaz-khan/src/abb/abb_irb2400_support/urdf"
    )
endif()

