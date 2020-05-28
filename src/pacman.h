#ifndef PACMAN_H
#define PACMAN_H

#include <vector>
#include "SDL.h"

class Pacman {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Pacman(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2),
        head_y(grid_height / 2) {}

  void Update();
  bool PacmanCell(int x, int y);

  Direction direction = Direction::kUp;

  float speed{0.1f};
  float head_x;
  float head_y;
  bool alive{true};

 private:
  void UpdatePostion();

  int grid_width;
  int grid_height;
};

#endif