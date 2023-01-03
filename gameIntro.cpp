#include "gameIntro.h"

GameIntro::GameIntro()
: Game::Game(), end{false} {};

void GameIntro::handleEvents() {
    SDL_Event event;
    SDL_PollEvent (&event);
    switch (event.type) {
        case SDL_QUIT:
            close_all_of = true;
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym){
                case SDLK_SPACE:
                    end = true;
                    SDL_FreeSurface(surface_message);
                    SDL_DestroyTexture(message);
                    if(!music_playing) {
                        Mix_PlayMusic(music, -1);
                        Mix_VolumeMusic(25);
                        music_playing = true;
                    }
                    break;
                case SDLK_ESCAPE:
                    close_all_of = true;
                default: break;
                }
        default:
            break;
    }
}

void GameIntro::text() {
    if (!end)
        SDL_RenderCopy(renderer, message, NULL, &message_rect);
}

void GameIntro::render(Uint32 frameStart) {
    SDL_RenderClear(renderer);
    venom.draw(renderer);
    venom_right.draw(renderer);
    Uint32 time_passed {SDL_GetTicks()};
    if (time_passed - frameStart > 1000){
        venom_center.draw(renderer);
        if(!music_playing) {
            Mix_PlayMusic(music, -1);
            Mix_VolumeMusic(25);
            music_playing = true;
        }
    }
    text();
    SDL_RenderPresent(renderer);
}

