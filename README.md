# Coordinate-Transformation-Sim
A C++ tool using the Eigen library to transform coordinates between a mobile camera frame and a fixed global frame.
Coordinate Transformation Simulator

A C++ implementation for transforming point coordinates from a local camera frame (Frame B) to a global reference frame (Frame A) using Homogeneous Transformation Matrices.
Overview

This project simulates a common task in robotics and computer vision: taking a point detected by a mobile sensor (like a camera) and calculating its "real-world" position based on the sensor's current location and rotation.

The simulation uses the Eigen library to handle matrix multiplication and vector operations efficiently.
Features

    User Input Interface: Prompts for camera position (xc​,yc​), rotation angle (θ), and the coordinates of a point P relative to the camera.

    Homogeneous Coordinates: Utilizes a 3×3 transformation matrix to combine rotation and translation into a single calculation.

    Trigonometric Precision: Converts degrees to radians for accurate SO(2) rotation matrix construction.

The Math Behind It

The program constructs a transformation matrix T based on the following formula:
T=​cosθsinθ0​−sinθcosθ0​xc​yc​1​​

The final global coordinates are found by multiplying this matrix by the homogeneous point vector:
PA​=T⋅PB​
Getting Started
Prerequisites

To run this code, you need:

    A C++ compiler (GCC, Clang, or MSVC).

    The Eigen library. You can find it at eigen.tuxfamily.org.

Compilation

If you have Eigen installed in your system include path, you can compile using:
Bash

g++ -I /usr/include/eigen3 coordinate_transformation.cpp -o transform_sim

Usage

Run the executable and follow the terminal prompts:

    Enter the camera's (x,y) position.

    Enter the camera's rotation angle in degrees.

    Enter the point's coordinates relative to the camera.
