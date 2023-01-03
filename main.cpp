#include <SDL2/SDL.h>
#include "game.h"
#include "gameIntro.h"
#include "gameOutro.h"

Game *game = nullptr;
GameIntro *game_intro = nullptr;
GameOutro *game_outro = nullptr;

int main(int argc,  char *argv[]){
                // main game variables and initialization of SDL functions, game textures etc.
    const int FPS{60};
    const int frameDelay{1000/FPS};
    int frameTime;
    int current_level {1};
    bool close_app {false};
    game = new Game();
    game->init("Venom game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 800, false );
    game->player_init();
    game->set_background();
    game_intro = new GameIntro();                   
    game_outro = new GameOutro();
    game_outro->init_textures();
                // Main timers
    Uint32 frameBegin;
    Uint32 initialized {SDL_GetTicks()};
    Uint32 frameStart;
                // Main Game loop
    while(game->initialized()) {
        frameBegin = SDL_GetTicks();
        switch (current_level){
            case 1:
                game_intro->handleEvents();
                game_intro->render(initialized);
                if (game_intro->close_all()) close_app = true;
                if (game_intro->ended()) current_level = 2;
                break;
            case 2:
                frameStart = SDL_GetTicks();
                game->handleEvents();
                game->update(frameStart);
                game->render(frameStart);
                if (game->close_all()) close_app = true;
                if (game->ended()) {current_level = 3; game_outro->set_ended_false();}
                break;
            case 3:
                game_outro->handleEvents();                              
                game_outro->render(game->get_score(), frameBegin); 
                if (game_outro->close_all()) close_app = true;
                if (game_outro->ended()) {current_level = 2; game->game_restart(); } 
                break;
            default: break;
        }
        if (close_app) game->set_initialize_false();
        frameTime = SDL_GetTicks() - frameBegin;            
        if (frameDelay > frameTime){                        // Limiting FPS
            SDL_Delay(frameDelay - frameTime);
        }
    }
                // Closing SDL and other SDL/ packages
    game_intro->close_music();
    game->close_music();
    game->clean();
    return 0;
}
