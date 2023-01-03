#include "static_object.h"

StaticObject::StaticObject(const char* path, int x, int y, int width, int height, SDL_Renderer* renderer, bool killable)
: path{path}, xpos{x}, ypos{y}, width{width}, height{height}, kill_enabled{killable} { objTexture = init_texture(renderer); }

SDL_Texture* StaticObject::init_texture(SDL_Renderer* renderer){
    SDL_Surface* tempSurface = IMG_Load(path);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    return tex;
}

void StaticObject::draw(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, objTexture, NULL, &destRect);
}

void StaticObject::moving(int speed, bool move_and_return) {
    if (move_and_return){
        if (destRect.x > -10){
            moving_right = false;
            moving_left = true;
        }
        if (destRect.x < -680){
            moving_left = false;
            moving_right = true;
        }
        if (moving_left) {
            destRect.x -= speed;
        }
        if (moving_right) {
            destRect.x += speed;
        }
    }else {
        destRect.x -= speed;
        hitbox.x -= speed;
    }
}

void StaticObject::moving_down(int speed) {
    destRect.y += speed;
    hitbox.y += speed;
}

void StaticObject::init_hitbox(int x, int y, int width_h, int height_h) {
    hitbox.x = xpos + x;
    hitbox.y = ypos + y;
    hitbox.w = width_h;
    hitbox.h = height_h;
}