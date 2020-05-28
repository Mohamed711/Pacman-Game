#ifndef GAME_H
#define GAME_H

#include <random>
#include <thread>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "pacman.h"
#include "enemy.h"

class Game {
 public:
  Game(const std::size_t screen_width, const std::size_t screen_height, 
             std::size_t grid_width, std::size_t grid_height, std::size_t enemies_no);
  bool Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

 private:
  std::size_t _grid_width;
  std::size_t _grid_height;
  std::size_t _screen_width;
  std::size_t _screen_height;
  std::size_t _enemies_no;

  Pacman pacman;
  // std::vector<std::thread> threads; 
  std::vector<std::unique_ptr<Enemy>> enemies; 
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