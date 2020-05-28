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

  // Add enemies to the game
  for (int enemy_no = 0; enemy_no < 5; enemy_no++)
  {
    enemies.push_back(Enemy(grid_width, grid_height));
  }
}

bool Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;
  bool win_state = false;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, pacman);
    Update();
    renderer.Render(pacman, food, enemies);

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

  win_state = (food.empty()) ? true : false;

  return win_state;
}

// Initial Grid of food for the PACMAN
void Game::PlaceFood() 
{
  SDL_Point fooditem;

  for (int i = 0; i < _grid_width; i++)
  {
    for (int j = 0; j < _grid_width; j++)
    {
      fooditem.x = i;
      fooditem.y = j;
      food.push_back(fooditem);
    }
  }
}

void Game::Update() 
{
  // Check if pacman died or win the game
  // if ((!pacman.alive) || food.empty()) return;

  if (food.empty()) return;

  pacman.Update();

  //enemies[2].head_x = 20;

  for (int i = 0; i < 5; i++)
  {
    enemies[i].Update();
  }

  //std::cout << enemies[2].head_x << std::endl;

  int new_x = static_cast<int>(pacman.head_x);
  int new_y = static_cast<int>(pacman.head_y);
  
  std::vector<SDL_Point>::iterator fooditem;

  // Check if there's food over here
  for (fooditem = food.begin(); fooditem != food.end(); fooditem++)
  {
    if ((*fooditem).x == new_x && (*fooditem).y == new_y) 
    {
      // increase the score
      score++;

      // remove food from its place
      food.erase(fooditem);

      break;
    }
  }
}

int Game::GetScore() const { return score; }
