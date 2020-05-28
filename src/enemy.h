#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <vector>
#include <thread>
#include "SDL.h"
#include "gameobject.h"

class Enemy : public GameObject
{
 public:
  Enemy(int grid_width, int grid_height);
  void Update();
  void simulate();
  void Stop();
  ~Enemy(){enemy_thread.join();} // destroy thread safely

 private:
  std::mutex _mtx;
  void UpdateDirection();
  int ChangeDirectionSec; // no of seconds to change the direction randomly
  bool running{true};
  std::thread enemy_thread;
};

#endif