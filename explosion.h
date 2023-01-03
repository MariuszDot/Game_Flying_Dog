#ifndef _EXPLOSION_
#define _EXPLOSION_
#include "SDL2/SDL_image.h"
#include <vector>

class Explosion {
protected:
    int xpos;
    int ypos;
    int width;
    int height;
    SDL_Rect destRect {xpos, ypos, width, height};
    int frame_number {0};
    int total_frames_nr {23};
    Uint32 time_passed {0};
    bool kill {false};
    int animation_speed {30};

public:
    Explosion(int xpos, int ypos, int width, int height);
    virtual ~Explosion() = default;
    virtual void update();
    void draw(SDL_Renderer* renderer, const std::vector<SDL_Texture*> &container,const Uint32 &frameStart);
    bool is_kill() { return kill; };
};

class Sparks : public Explosion {
public:
    Sparks(int xpos, int ypos, int width, int height);
    ~Sparks() = default;
    void update() override;
};
#endif