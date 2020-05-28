#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{16};
  constexpr std::size_t kGridHeight{16};
  constexpr std::size_t kNoOfEnemies{5};

  bool win_state = false;

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight, kNoOfEnemies);
  win_state = game.Run(controller, renderer, kMsPerFrame);

  if (win_state == false)
  {
    std::cout << "Game has terminated successfully (GOOD LUCK)! \n";
  }
  else
  {
    std::cout << "Congratualtions!! (YOU WON THE GAME) \n";
  }

  std::cout << "Score: " << game.GetScore() << "\n";
  return 0;
}