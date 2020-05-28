#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "pacman.h"
#include "enemy.h"

void Controller::ChangeDirection(Pacman &pacman, Pacman::Direction input,
                                 Pacman::Direction opposite) const {
  if (pacman.direction != opposite || pacman.size == 1) pacman.direction = input;
  return;
}

void Controller::HandleInput(bool &running, Pacman &pacman) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection(pacman, Pacman::Direction::kUp,
                          Pacman::Direction::kDown);
          break;

        case SDLK_DOWN:
          ChangeDirection(pacman, Pacman::Direction::kDown,
                          Pacman::Direction::kUp);
          break;

        case SDLK_LEFT:
          ChangeDirection(pacman, Pacman::Direction::kLeft,
                          Pacman::Direction::kRight);
          break;

        case SDLK_RIGHT:
          ChangeDirection(pacman, Pacman::Direction::kRight,
                          Pacman::Direction::kLeft);
          break;
      }
    }
  }
}