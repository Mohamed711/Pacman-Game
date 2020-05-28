#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <vector>
#include "SDL.h"

class Enemy 
{
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Enemy(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(0),
        head_y(0) 
        {
          std::cout << "Enemy Constructor " << std::endl;
          updates = 0;
        }

  ~Enemy()
  {
    // std::cout << "Destructor called" << std::endl;
  }

  void Update();
  bool EnemyCell(int x, int y);

  Direction direction = Direction::kLeft;

  float speed{0.1f};
  float head_x;
  float head_y;

 private:
  void UpdatePostion();

  int grid_width;
  int grid_height;
  int updates;
};

#endif