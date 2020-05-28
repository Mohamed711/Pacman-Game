
#include "enemy.h"
#include <cmath>
#include <random>
#include <iostream>

Enemy::Enemy(int grid_width, int grid_height)
      : GameObject(grid_width, grid_height)
{
  ChangeDirectionSec = 0;

  // Initialize the default direction to be random
  UpdateDirection();

  // Random location at the X but at the top of the game
  head_x = rand() % grid_width;
  head_y = 0;
}

void Enemy::Update()
{
  //std::this_thread::sleep_for(std::chrono::milliseconds(10));
  ChangeDirectionSec++;

  // Change direction each two seconds
  if (ChangeDirectionSec >= 200)
  {
    UpdateDirection();
    ChangeDirectionSec = 0;
  }

  UpdatePostion();
}

// Change the direction of the enemy randomly
void Enemy::UpdateDirection()
{
  int dir_index = rand() % 4;
    
  switch (dir_index)
  {
      case 0: 
          direction = Direction::kUp;
          break;

      case 1: 
          direction = Direction::kDown;
          break;

      case 2: 
          direction = Direction::kLeft;
          break;

      case 3: 
          direction = Direction::kRight;
          break;
  }
}