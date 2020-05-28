#include <cmath>
#include <iostream>
#include "gameobject.h"

void GameObject::Update() 
{
  UpdatePostion();
}

// Update the object position based on the direction
void GameObject::UpdatePostion() 
{
  //std::lock_guard<std::mutex> uLock(_mutex); // protect the location member variables

  switch (direction) 
  {
    case Direction::kUp:
      head_y -= speed;
      break;

    case Direction::kDown:
      head_y += speed;
      break;

    case Direction::kLeft:
      head_x -= speed;
      break;

    case Direction::kRight:
      head_x += speed;
      break;
  }

  // Wrap GameObject around to the beginning if going off of the screen.
  head_x = fmod(head_x + grid_width, grid_width);
  head_y = fmod(head_y + grid_height, grid_height);
}

// Check if the cell is occupied by GameObject or not
bool GameObject::GameObjectCell(int x, int y) 
{
  SDL_Point loc = getLocation();
  if (x == loc.x && y == loc.y) 
  {
    return true;
  }

  return false;
}

// Funtion called to get the location of object - called from another thread context
SDL_Point GameObject::getLocation()
{
  SDL_Point loc;

  //std::lock_guard<std::mutex> uLock(_mutex); // protect the location member variables

  loc.x = static_cast<int>(head_x);
  loc.y = static_cast<int>(head_y);

  return loc;
}
