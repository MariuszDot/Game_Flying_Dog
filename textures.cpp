#include "textures.h"

void initialize_textures_black_bird(std::vector<SDL_Texture*> &container, SDL_Renderer* renderer) {
    SDL_Surface* tempSurface = IMG_Load("graphics/enemies/enemy_1_0.png");
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/enemies/enemy_1_1.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/enemies/enemy_1_2.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/enemies/enemy_1_3.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
}

void initialize_textures_green_bird(std::vector<SDL_Texture*> &container, SDL_Renderer* renderer) {
    SDL_Surface* tempSurface = IMG_Load("graphics/enemies/enemy_0.png");
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/enemies/enemy_1.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/enemies/enemy_2.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/enemies/enemy_3.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
}

void initialize_textures_blue_bird(std::vector<SDL_Texture*> &container, SDL_Renderer* renderer) {
    SDL_Surface* tempSurface = IMG_Load("graphics/enemies/friend_0.png");
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/enemies/friend_1.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/enemies/friend_2.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/enemies/friend_3.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
}

void initialize_textures_fireball(std::vector<SDL_Texture*> &container, SDL_Renderer* renderer) {
    SDL_Surface* tempSurface = IMG_Load("graphics/fire_balls/fire_0.png");
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/fire_balls/fire_1.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/fire_balls/fire_2.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/fire_balls/fire_3.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/fire_balls/fire_4.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/fire_balls/fire_5.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/fire_balls/fire_6.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/fire_balls/fire_7.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
}

void initialize_textures_explosion(std::vector<SDL_Texture*> &container, SDL_Renderer* renderer) {
    SDL_Surface* tempSurface = IMG_Load("graphics/Explosion/explosion_0_200x200.png");
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/Explosion/explosion_1_200x200.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/Explosion/explosion_2_200x200.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/Explosion/explosion_3_200x200.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/Explosion/explosion_4_200x200.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/Explosion/explosion_5_200x200.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/Explosion/explosion_6_200x200.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/Explosion/explosion_7_200x200.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/Explosion/explosion_8_200x200.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/Explosion/explosion_9_200x200.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/Explosion/explosion_10_200x200.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/Explosion/explosion_11_200x200.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/Explosion/explosion_12_200x200.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/Explosion/explosion_13_200x200.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/Explosion/explosion_14_200x200.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/Explosion/explosion_15_200x200.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/Explosion/explosion_16_200x200.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/Explosion/explosion_17_200x200.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/Explosion/explosion_18_200x200.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/Explosion/explosion_19_200x200.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/Explosion/explosion_20_200x200.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/Explosion/explosion_21_200x200.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/Explosion/explosion_22_200x200.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
}

void initialize_textures_bird_hit(std::vector<SDL_Texture*> &container, SDL_Renderer* renderer) {
    SDL_Surface* tempSurface = IMG_Load("graphics/fire_balls/sparks_0.png");
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/fire_balls/sparks_1.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/fire_balls/sparks_2.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
    tempSurface = IMG_Load("graphics/fire_balls/sparks_3.png");
    tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    container.push_back(tex);
    SDL_FreeSurface(tempSurface);
}

