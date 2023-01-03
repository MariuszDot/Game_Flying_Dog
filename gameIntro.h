#ifndef _GAME_INTRO_
#define _GAME_INTRO_
#include "game.h"
#include "static_object.h"

class GameIntro : public Game {
private:
    bool end{false};
    bool close_all_of{false};
    bool music_playing {false};
    StaticObject venom{"graphics/small_venom_350x408.png", 100, 250, 350, 408, renderer};
    StaticObject venom_right{"graphics/venom_351.png", 750, 250, 480, 427, renderer};
    StaticObject venom_center{"graphics/venom_happy_450.png", 400, 50, 400, 490, renderer};
    TTF_Font* amatic_bold = TTF_OpenFont("graphics/fonts/Amatic-Bold.ttf", 60); 
    SDL_Color dark_blue {9, 9, 111};
    SDL_Surface* surface_message {TTF_RenderText_Blended(amatic_bold, "Press  [SPACE]  to start the game !", dark_blue)};
    SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surface_message);
    SDL_Rect message_rect {400, 650, surface_message->w, surface_message->h};
    Mix_Music* music = Mix_LoadMUS("graphics/audio/achievement.wav");

public:
    GameIntro();
    virtual ~GameIntro() = default;
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) = delete;   // delete because don't want to initialize SDL2 in derived classes
    void clean() = delete;          // delete because don't want to clean up SDL2 in derived classes
    void handleEvents() override;
    void render(Uint32 frameStart);
    void text();
    bool ended() {return end;};
    bool close_all() {return close_all_of;};
    void close_music() { Mix_FadeOutMusic(0); };
};
#endif