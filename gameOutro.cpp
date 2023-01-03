#include "gameOutro.h"

GameOutro::GameOutro()
:GameIntro::GameIntro(), end{false}{}

void GameOutro::handleEvents()  {
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
                    break;
                case SDLK_ESCAPE:
                    close_all_of = true;
                default: break;
            }
        default:
            break;
        }    
}

void GameOutro::render(int score, Uint32 &frameStart) {
    SDL_RenderClear(renderer);
    bomb.draw(renderer);
    venom.draw(renderer);
    black_tower.draw(renderer);
    black_bird.draw(renderer, black_bird_tex, frameStart);
    green_bird.draw(renderer, green_bird_tex, frameStart);
    blue_bird.draw(renderer, blue_bird_tex, frameStart);
    fireball.draw(renderer, fireball_tex, frameStart);
    display_text(score);
    SDL_RenderPresent(renderer);
}

void GameOutro::init_textures() {
    initialize_textures_black_bird(black_bird_tex, renderer);
    initialize_textures_green_bird(green_bird_tex, renderer);
    initialize_textures_blue_bird(blue_bird_tex, renderer);
    initialize_textures_fireball(fireball_tex, renderer);

    amatic_bold = TTF_OpenFont("graphics/fonts/Amatic-Bold.ttf", 60);

    press_surf = TTF_RenderText_Blended(amatic_bold, "Press:                                                     You gain:                                               You lose:", dark_blue);
    press_texture = SDL_CreateTextureFromSurface(renderer, press_surf);
    press_rect.w = press_surf->w;
    press_rect.h = press_surf->h;
    SDL_FreeSurface(press_surf);

    arrows_surf = TTF_RenderText_Blended(amatic_bold, "[ARROWS] to move                                                     30 pts                                                     30 pts", dark_blue);
    arrows_texture = SDL_CreateTextureFromSurface(renderer, arrows_surf);
    arrows_rect.w = arrows_surf->w;
    arrows_rect.h = arrows_surf->h;
    SDL_FreeSurface(arrows_surf);

    lctrl_surf = TTF_RenderText_Blended(amatic_bold, "[LCTRL] to                                                            100 pts                                               50 pts, 1 life", dark_blue);
    lctrl_texture = SDL_CreateTextureFromSurface(renderer, lctrl_surf);
    lctrl_rect.w = lctrl_surf->w;
    lctrl_rect.h = lctrl_surf->h;
    SDL_FreeSurface(lctrl_surf);

    space_surf = TTF_RenderText_Blended(amatic_bold, "[SPACE] to", dark_blue);
    space_texture = SDL_CreateTextureFromSurface(renderer, space_surf);
    space_rect.w = space_surf->w;
    space_rect.h = space_surf->h;
    SDL_FreeSurface(space_surf);

    press_space_surf = TTF_RenderText_Blended(amatic_bold, "Press [SPACE] to play again !", dark_blue);
    press_space_texture = SDL_CreateTextureFromSurface(renderer, press_space_surf);
    press_space_rect.w = press_space_surf->w;
    press_space_rect.h = press_space_surf->h;
    SDL_FreeSurface(press_space_surf);
}

void GameOutro::display_text(int score) { 
    amatic_bold = TTF_OpenFont("graphics/fonts/Amatic-Bold.ttf", 60); 
    char score_num[6];
    strcpy(score_text, "Congrats!   You scored  ");
    strcat(score_text, itoa(score, score_num, 10));
    strcat(score_text, "  points !");
    congrat_surf = TTF_RenderText_Blended(amatic_bold, score_text, dark_blue);
    congrat_texture = SDL_CreateTextureFromSurface(renderer, congrat_surf);
    congrats_rect.w = congrat_surf->w;
    congrats_rect.h = congrat_surf->h;
    SDL_RenderCopy(renderer, congrat_texture, NULL, &congrats_rect);

    SDL_RenderCopy(renderer, press_texture, NULL, &press_rect);
    SDL_RenderCopy(renderer, arrows_texture, NULL, &arrows_rect);
    SDL_RenderCopy(renderer, lctrl_texture, NULL, &lctrl_rect);
    SDL_RenderCopy(renderer, space_texture, NULL, &space_rect);
    SDL_RenderCopy(renderer, press_space_texture, NULL, &press_space_rect);

    TTF_CloseFont(amatic_bold);
    SDL_FreeSurface(congrat_surf);
    SDL_DestroyTexture(congrat_texture);
}
