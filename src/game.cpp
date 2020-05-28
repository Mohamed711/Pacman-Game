#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(const std::size_t screen_width, const std::size_t screen_height, 
                 std::size_t grid_width, std::size_t grid_height)
    : pacman(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width)),
      random_h(0, static_cast<int>(grid_height)) {

  _screen_width = screen_width;
  _screen_height = screen_height;
  _grid_width = grid_width;
  _grid_height = grid_height;
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, pacman);
    Update();
    renderer.Render(pacman, food);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  SDL_Point fooditem;

  for (int i = 0; i < _grid_width; i = i + 1)
  {
    for (int j = 0; j < _grid_width; j = j + 1)
    {
      fooditem.x = i;
      fooditem.y = j;
      food.push_back(fooditem);
    }
  }
}

void Game::Update() {
  if (!pacman.alive) return;

  pacman.Update();

  int new_x = static_cast<int>(pacman.head_x);
  int new_y = static_cast<int>(pacman.head_y);

  // Check if there's food over here
 // if (food.x == new_x && food.y == new_y) {
    score++;
    // Grow pacman and increase speed.
    //pacman.GrowBody();
    //pacman.speed += 0.02;
  //}
}

int Game::GetScore() const { return score; }
