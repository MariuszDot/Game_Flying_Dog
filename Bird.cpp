#include "Bird.h"

Bird::Bird(int xpos, int ypos, int width, int height, int hitbox_x, int hitbox_y, int hitbox_width, int hitbox_height)
: xpos{xpos}, ypos{ypos}, width{width}, height{height}, xpos_h{xpos + hitbox_x}, ypos_h{ypos + hitbox_y}, width_h{hitbox_width}, height_h{hitbox_height} { }

void Bird::update(const Uint32 &frame) {
    moving();
}

void Bird::draw(SDL_Renderer* renderer,const std::vector<SDL_Texture*> &container,const Uint32 &frameStart) {
    SDL_RenderCopy(renderer, container.at(frame_number), NULL, &destRect);
    int time = (frameStart - time_passed);
    if (time > animation_speed) {
        frame_number++;    // increment to the next frame of animation
        time_passed = frameStart;
        if (frame_number >= total_frames_nr) frame_number = 0;
    }
}

void Bird::moving() {
    destRect.x -= 2;
    hitbox.x -= 2;
    if(moving_up) {
        destRect.y -= 2;
        hitbox.y -= 2;
    }
    if(moving_down) {
        destRect.y += 2;
        hitbox.y += 2;
    }
    if (destRect.x > 800 && destRect.x < 1100) {moving_down = true; moving_up = false;}
    else if (destRect.x > 500 && destRect.x < 800) { moving_down = false; moving_up = true;}
    else if (destRect.x > 250 && destRect.x < 500) { moving_down = true; moving_up = false;}
    else if (destRect.x < 250) { moving_down = false; moving_up = true;}
}

