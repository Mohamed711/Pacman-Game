#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "pacman.h"

class Game {
 public:
  Game(const std::size_t screen_width, const std::size_t screen_height, 
             std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

 private:
  std::size_t _grid_width;
  std::size_t _grid_height;
  std::size_t _screen_width;
  std::size_t _screen_height;

  Pacman pacman;
  std::vector<SDL_Point> food;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  void PlaceFood();
  void Update();
};

#endif