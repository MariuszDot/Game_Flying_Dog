#include "fireball.h"

Fireball::Fireball (int xpos, int ypos, int width, int height, SDL_Renderer* renderer)
: xpos{xpos}, ypos{ypos}, width{width}, height{height} { }

void Fireball::update(Uint32 frameStart) {
    destRect.x += 7;
    hitbox.x += 7;
}

void Fireball::draw(SDL_Renderer* renderer, const std::vector<SDL_Texture*> &container,const Uint32 &frameStart) {
    SDL_RenderCopy(renderer, container.at(frame_number), NULL, &destRect);
    int time = frameStart - time_passed;
    if (time > 50) {
        frame_number++;         // incrementing to the next frame
        time_passed = frameStart;
        if (frame_number >= total_frames_nr) frame_number = 0;
    }
}