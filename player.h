#ifndef _PLAYER_
#define _PLAYER_
#include "SDL2/SDL_image.h"
#include <string>

class Player {
private:
    std::string path;
    const char* path_relative = path.c_str();
    SDL_Texture* objTexture;
    SDL_Rect srcRect; 
    int xpos;
    int ypos;
    int height{98};
    int width{124};
    SDL_Rect destRect {xpos, ypos, width , height};
    int xpos_h;
    int ypos_h;
    int width_h;
    int height_h;
    SDL_Rect hitbox {xpos_h, ypos_h, width_h, height_h};
    bool close_all_of {false};
    bool end {false};
    SDL_Texture* load(SDL_Renderer* renderer);
    bool moving_left{false};
    bool moving_right{false};
    bool moving_up{false};
    bool moving_down{false};
    bool fire_fireball {false};
    bool fire_bombs {false};
    bool kill {false};

public:
    Player(SDL_Renderer* renderer, std::string path_given, int x, int y, int hitbox_x, int hitbox_y, int hitbox_width, int hitbox_height);
    ~Player() = default;
    void update();
    void draw(SDL_Renderer* renderer);
    void handle_events();
    bool close_all(){return close_all_of; };
    void moving();
    void set_end_false() {end = false; };
    bool ended() {return end;};
    int get_xpos() { return destRect.x; };
    int get_ypos() { return destRect.y; };
    int get_width() { return destRect.w; };
    int get_height() { return destRect.h; };
    int get_hitbox_x() { return hitbox.x; };
    int get_hitbox_y() { return hitbox.y; };
    int get_hitbox_width() { return hitbox.w; };
    int get_hitbox_height() { return hitbox.h; };
    bool is_fire_fireball() { return fire_fireball; };
    bool is_fire_bombs() { return fire_bombs; };
    bool is_kill() { return kill; };
    void set_to_kill() { kill = true; };
};
#endif