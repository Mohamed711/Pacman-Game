#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "pacman.h"
#include "enemy.h"

void Controller::HandleInput(bool &running, Pacman &pacman) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          pacman.direction = Pacman::Direction::kUp;
          break;

        case SDLK_DOWN:
          pacman.direction = Pacman::Direction::kDown;
          break;

        case SDLK_LEFT:
          pacman.direction = Pacman::Direction::kLeft;
          break;

        case SDLK_RIGHT:
          pacman.direction = Pacman::Direction::kRight;
          break;
      }
    }
  }
}