#ifndef _STATIC_OBJECT_
#define _STATIC_OBJECT_
#include "SDL2/SDL_image.h"

class StaticObject {
private:
    const char* path;
    int xpos;
    int ypos;
    int width;
    int height;
    SDL_Rect destRect {xpos, ypos, width, height};
    SDL_Rect hitbox {0, 0, 0, 0};
    SDL_Texture* objTexture;
    bool moving_left{false};
    bool moving_right{false};
    bool kill_enabled {false};
    bool kill {false};

public:
    StaticObject(const char* path, int xpos, int ypos, int width, int height, SDL_Renderer* renderer, bool killable = false);
    ~StaticObject() = default;
    void draw(SDL_Renderer* renderer);
    SDL_Texture* init_texture(SDL_Renderer* renderer);
    void moving(int speed, bool move_and_return);
    void moving_down(int speed);
    int get_xpos() { return destRect.x; };
    int get_ypos() { return destRect.y; };
    int get_width() { return destRect.w; };
    int get_height() { return destRect.h; };
    int get_hitbox_x() { return hitbox.x; };
    int get_hitbox_y() { return hitbox.y; };
    int get_hitbox_width() { return hitbox.w; };
    int get_hitbox_height() { return hitbox.h; };
    void init_hitbox(int x, int y, int width_h, int height_h);
    void set_to_kill() { kill = true; };
    bool is_kill() { return kill; };
    bool kill_is_enabled() { return kill_enabled; };
};
#endif