# CPPND: Capstone Pacman Game Project

This project is about 

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./PacmanGame`.


## File Structure

* controller.cpp: controller class source code.
* controller.h	: controller class header file.
* enemy.cpp		: enemy class source code.
* enemy.h		: enemy class header file.
* game.cpp		: game class source code.
* game.h 		: game class header file.
* gameobject.cpp: game object class source code.
* gameobject.h 	: game object class header file.
* main.cpp 		: Start the application source code.
* pacman.cpp 	: pacman class source code.
* pacman.h 		: pacman class header file.
* renderer.cpp 	: renderer class source code.
* renderer.h 	: renderer class header file.

## Rubric Points

* Loops, Functions, I/O
	* The project demonstrates an understanding of C++ functions and control structures: These exist at all of the project files implementation.

* Object Oriented Programming
	* The project uses Object Oriented Programming techniques: The project is constructed of different classes, each has its own responsinility.
	* Classes use appropriate access specifiers for class member
	* Class constructors utilize member initialization lists.
	* Classes follow an appropriate inheritance hierarchy.