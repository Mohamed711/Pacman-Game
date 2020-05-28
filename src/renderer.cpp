#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) 
{
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Pacman Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() 
{
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(Pacman const pacman, std::vector<SDL_Point> const &food, 
              std::vector<std::unique_ptr<Enemy>> &enemies)
{
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;
  static int trial = 0;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Render food
  for (auto fooditem : food)
  {      
    SDL_Rect food;
    food.w = block.w * 0.2;
    food.h = block.h * 0.2;

    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
    food.x = fooditem.x * block.w + (block.w / 2);
    food.y = fooditem.y * block.h + (block.h / 2);
    SDL_RenderFillRect(sdl_renderer, &food);
  }

  for (auto enemy = enemies.begin(); enemy != enemies.end(); enemy++)
  {
    SDL_Rect enemy_block;
    SDL_Point enemy_loc = (*enemy)->getLocation();

    // std::cout << "enemy entered " << static_cast<int>(enemy.head_x)  << std::endl;
    enemy_block.w = screen_width / grid_width;
    enemy_block.h = screen_height / grid_height;
    enemy_block.x = enemy_loc.x * block.w;
    enemy_block.y = enemy_loc.y * block.h;
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(sdl_renderer, &enemy_block);
  }

  // Render pacman head
  block.x = pacman.head_x * block.w;
  block.y = pacman.head_y * block.h;
  if (pacman.alive) 
  {
    SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
  } 
  else 
  {
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
  }
  SDL_RenderFillRect(sdl_renderer, &block);

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, int fps) 
{
  std::string title{"Pacman Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
