#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <vector>
#include "SDL.h"
#include "gameobject.h"

class Enemy : public GameObject
{
 public:
  Enemy(int grid_width, int grid_height);
  void Update();

 private:
  void UpdateDirection();
  int updates;
};

#endif