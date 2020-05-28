#ifndef PACMAN_H
#define PACMAN_H

#include <vector>
#include "SDL.h"
#include "gameobject.h"

class Pacman : public GameObject
{
 public:
  Pacman(int grid_width, int grid_height);
  
  bool alive{true};

 private:

};

#endif