#include "explosion.h"

Explosion::Explosion(int xpos, int ypos, int width, int height)
: xpos{xpos}, ypos{ypos}, width{width}, height{height} { }

void Explosion::draw(SDL_Renderer* renderer, const std::vector<SDL_Texture*> &container,const Uint32 &frameStart) {
    SDL_RenderCopy(renderer, container.at(frame_number), NULL, &destRect);
    int time = frameStart - time_passed;
    if (time > animation_speed) {
        frame_number++;
        time_passed = frameStart;
        if (frame_number >= total_frames_nr) {
            frame_number = 0;
            kill = true;
        }
    }
}

void Explosion::update() {
    destRect.x -= 5;
}

Sparks::Sparks(int xpos, int ypos, int width, int height)
: Explosion(xpos, ypos, width, height) { total_frames_nr = 4; animation_speed = 50; }

void Sparks::update() {
    destRect.x -= 2;
}