
#include "enemy.h"
#include <cmath>
#include <random>
#include <iostream>

void Enemy::Update()
{    
  // Update the direction of the enemy each one second
  if (updates >= 100)
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

    updates = 0;
  }

  updates++;
  UpdatePostion();
}

// Update the position of the enemy
void Enemy::UpdatePostion() 
{
  switch (direction) 
  {
    case Direction::kUp:
      this->head_y -= speed;
      break;

    case Direction::kDown:
      this->head_y += speed;
      break;

    case Direction::kLeft:
      this->head_x -= speed;
      break;

    case Direction::kRight:
      this->head_x += speed;
      break;
  }

  // Wrap enemy around to the beginning if going off of the screen.
  head_x = fmod(head_x + grid_width, grid_width);
  head_y = fmod(head_y + grid_height, grid_height);

  // std::cout << head_x << " " << head_y << " " << std::endl;
}

// Check if the cell is occupied by enemy
bool Enemy::EnemyCell(int x, int y) 
{
  if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y)) 
  {
    return true;
  }

  return false;
}
