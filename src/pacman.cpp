#include "pacman.h"
#include <cmath>
#include <iostream>

Pacman::Pacman(int grid_width, int grid_height)
    : GameObject(grid_width, grid_height)
{
  // Initialize the direction of pacman
  direction = Direction::kUp;

  // Initialize the first location of pacman (lower-center)
  head_x = grid_width / 2;
  head_y = grid_height;
}