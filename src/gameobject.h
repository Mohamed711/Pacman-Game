#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <vector>
#include <mutex>
#include "SDL.h"

class GameObject 
{
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  GameObject(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2),
        head_y(grid_height / 2) {}

  virtual void Update();
  bool GameObjectCell(int x, int y);
  SDL_Point getLocation();

  Direction direction;
  float speed{0.1f};
  float head_x;
  float head_y;

 protected:
  void UpdatePostion();
  int grid_width;
  int grid_height;
};

#endif