# CPPND: Capstone Project: Patrol Guard FSM

## Project description
This project presents a simulation of an autonomous guard agent patrolling an area. The guard behavour is modelled as a Finite State Machine with four states:

* OnBase:  In this state the guard stays at a base for having a break. When a fixed break time is up the guard moves out to the patrol area (change to state InPatrol). 

* InPatrol:  In this state the guard patrols the area for a certain on duty period. When the time is up, the guard returns to the base for a break (change to state OnBase). If an intruder is detected, the guard start pursuing him (change to state InPursuit) 

* InPursuit:  The guard chases an intruder.  If intruder fired at the guard, the guard finds cover and shoots back (change to state ShootBack).
If an intruder left the area, the guard return to patrolling the territory (change to state InPatrol)

* ShootBack:  The guard find cover and shoots back at an intruder. If an intruder continues attacking the guard, the guard retreats to the base (change to state OnBase). Otherwise, the guard continues pursuing an intruder (change to state InPursuit).

The guard FSM project is realized using an C++ OOP approach following the Programming Game AI by Example (Chapter 2) by Mat Buckland 2002 (https://www.amazon.com/-/es/Mat-Buckland/dp/1556220782), and has been submitted as the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions
1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./guard`.

## Compliance with the Udacity Capstone Project rubric
* Compiling and Testing
  * The submission must compile and run (The project uses cmake and make) 

* Loops, Functions, I/O
  * The project demonstrates an understanding of C++ functions and control structures. (for loop, functions)
  * The project accepts user input and processes the input (std::cin, std::cout)

* Object Oriented Programming (classes StateMachine, State, Guard, states of FSM)
  * The project uses Object Oriented Programming techniques 
  * Classes use appropriate access specifiers for class members.
  * Class constructors utilize member initialization lists.
  * Classes encapsulate behavior.
  * Classes follow an appropriate inheritance hierarchy.
  * Overloaded functions allow the same function to operate on different parameters.
  * Derived class functions override virtual base class functions.
  * Templates generalize functions in the project.

* Memory Management (class Guard)
  * The project uses destructors appropriately.
