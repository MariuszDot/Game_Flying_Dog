#ifndef _FIREBALL_
#define _FIREBALL_
#include "SDL2/SDL_image.h"
#include <vector>

class Fireball {
    int xpos;
    int ypos;
    int width;
    int height;
    SDL_Rect destRect {xpos, ypos, width, height};
    SDL_Rect hitbox {xpos+17, ypos+9, 47, 13};
    std::vector<SDL_Texture*> textures;
    Uint32 time_passed {SDL_GetTicks()};
    int frame_number {0};
    int total_frames_nr {8};
    bool kill {false};
    
public:
    Fireball(int xpos, int ypos, int width, int height, SDL_Renderer* renderer);
    ~Fireball() = default;
    void update(Uint32 frameStart);
    void draw(SDL_Renderer* renderer, const std::vector<SDL_Texture*> &container,const Uint32 &frameStart);
    int get_xpos() { return destRect.x; };
    int get_ypos() { return destRect.y; };
    int get_width() { return destRect.w;};
    int get_height() { return destRect.h;};
    int get_hitbox_x() { return hitbox.x; };
    int get_hitbox_y() { return hitbox.y; };
    int get_hitbox_width() { return hitbox.w; };
    int get_hitbox_height() { return hitbox.h; };
    void set_to_kill() { kill = true;};
    bool is_killed() { return kill;};
};
#endif