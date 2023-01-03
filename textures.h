#ifndef _TEXTURES_
#define _TEXTURES_
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include <vector>

                // Initializing textures. Storing those functions in other files would make code there hard to read and unnecessary long
void initialize_textures_black_bird(std::vector<SDL_Texture*> &container, SDL_Renderer* renderer); 
void initialize_textures_green_bird(std::vector<SDL_Texture*> &container, SDL_Renderer* renderer); 
void initialize_textures_blue_bird(std::vector<SDL_Texture*> &container, SDL_Renderer* renderer);
void initialize_textures_fireball(std::vector<SDL_Texture*> &container, SDL_Renderer* renderer);
void initialize_textures_explosion(std::vector<SDL_Texture*> &container, SDL_Renderer* renderer);
void initialize_textures_bird_hit(std::vector<SDL_Texture*> &container, SDL_Renderer* renderer);
#endif
