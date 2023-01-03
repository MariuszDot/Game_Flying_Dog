#ifndef _BIRD_
#define _BIRD_
#include "SDL2/SDL_image.h"
#include <vector>

class Bird {
protected:
    int xpos;
    int ypos;
    int width;
    int height;
    SDL_Rect destRect {xpos, ypos, width, height};
    int xpos_h;
    int ypos_h;
    int width_h;
    int height_h;
    SDL_Rect hitbox {xpos_h, ypos_h, width_h, height_h};
    bool moving_up {true};
    bool moving_down {false};
    bool kill {false};
    Uint32 time_passed {SDL_GetTicks()};
    int frame_number{0};
    int total_frames_nr {4};
    int animation_speed {90};

public:
    Bird(int xpos, int ypos, int width, int height, int hitbox_x, int hitbox_y, int hitbox_width, int hitbox_height);
    virtual ~Bird() = default;
    void update(const Uint32 &frame);
    void draw(SDL_Renderer* renderer, const std::vector<SDL_Texture*> &container, const Uint32 &frameStart);
    void moving();
    int get_xpos() { return destRect.x;};
    int get_ypos() { return destRect.y;};
    int get_width() { return destRect.w;};
    int get_height() { return destRect.h;};
    int get_hitbox_x() { return hitbox.x;};
    int get_hitbox_y() { return hitbox.y;};
    int get_hitbox_width() { return hitbox.w;};
    int get_hitbox_height() { return hitbox.h;};
    void set_to_kill() { kill = true; };
    bool kill_getter() { return kill; };
};
#endif