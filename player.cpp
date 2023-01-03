#include "player.h"

SDL_Texture* Player::load(SDL_Renderer* renderer) {
    SDL_Surface* tempSurface = IMG_Load(path_relative);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    return tex;
}

Player::Player(SDL_Renderer* renderer, std::string path_given, int x, int y, int hitbox_x, int hitbox_y, int hitbox_width, int hitbox_height)
:path{path_given}, objTexture{Player::load(renderer)}, xpos{x}, ypos{y}, xpos_h{xpos + hitbox_x}, ypos_h{ypos + hitbox_y}, width_h{hitbox_width}, height_h{hitbox_height} { }

void Player::draw(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, objTexture, NULL, &destRect);
}

void Player::handle_events() {
    SDL_Event event;
    SDL_PollEvent (&event);
    if (event.type == SDL_QUIT) close_all_of = true;
    const Uint8* state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_RIGHT]) moving_right = true;
    if (!state[SDL_SCANCODE_RIGHT] || destRect.x > 1000) moving_right = false;
    if (state[SDL_SCANCODE_DOWN]) moving_down = true;
    if (!state[SDL_SCANCODE_DOWN] || destRect.y > 500) moving_down = false;
    if (state[SDL_SCANCODE_UP]) moving_up = true;
    if (!state[SDL_SCANCODE_UP] || destRect.y < 50) moving_up = false;
    if (state[SDL_SCANCODE_LEFT]) moving_left = true;
    if (!state[SDL_SCANCODE_LEFT] || destRect.x < 10) moving_left = false;
    if (state[SDL_SCANCODE_LCTRL]) fire_fireball = true;
    if (!state[SDL_SCANCODE_LCTRL]) fire_fireball = false;
    if (state[SDL_SCANCODE_SPACE]) fire_bombs = true;
    if (!state[SDL_SCANCODE_SPACE]) fire_bombs = false;
    if (state[SDL_SCANCODE_ESCAPE]) close_all_of = true;
}

void Player::moving(){
    if (moving_right) {
        destRect.x += 8;
        hitbox.x += 8;
    }
    if (moving_left) {
        destRect.x -= 8;
        hitbox.x -= 8;
    }
    if (moving_up) {
        destRect.y -= 8;
        hitbox.y -= 8;
    }
    if (moving_down) {
        destRect.y += 8;
        hitbox.y += 8;
    }
}

void Player::update(){
    this->moving();
}