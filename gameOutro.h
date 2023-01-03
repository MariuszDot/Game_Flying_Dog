#ifndef _GAME_OUTRO_
#define _GAME_OUTRO_
#include "gameIntro.h"
#include "game.h"

class GameOutro: public GameIntro {
private:
    bool end {false};
    bool close_all_of{false};
    char score_text[25];
    StaticObject venom{"graphics/venom_manual_200_1.png", 1100, 520, 200, 283, renderer};
    StaticObject black_tower {"graphics/bad_guys_tower.png", 500, 380, 128, 120, renderer};
    StaticObject bomb {"graphics/bomb_32x32.png", 280, 530, 32, 32, renderer};
                // Containers for textures of animated objects
    std::vector<SDL_Texture*> black_bird_tex;
    std::vector<SDL_Texture*> green_bird_tex;
    std::vector<SDL_Texture*> blue_bird_tex;
    std::vector<SDL_Texture*> fireball_tex;
    Bird black_bird{950, 400, 90, 64, 0, 0, 0, 0};
    Bird green_bird{1000, 320, 41, 32, 0, 0, 0, 0};
    Bird blue_bird{550, 320, 49, 42, 0, 0, 0, 0};
    Fireball fireball{250, 430, 64, 32, renderer};
                // Variables to print text, named after first word of sentence
    TTF_Font* amatic_bold;
    SDL_Color dark_blue {9, 9, 111};

    std::vector<SDL_Texture*> textures;
    SDL_Surface* congrat_surf;
    SDL_Texture* congrat_texture;
    SDL_Rect congrats_rect{350, 10, 0, 0};

    SDL_Surface* press_surf;
    SDL_Texture* press_texture;
    SDL_Rect press_rect{100, 150, 0, 0};

    SDL_Surface* arrows_surf;
    SDL_Texture* arrows_texture;
    SDL_Rect arrows_rect{30, 300, 0, 0};

    SDL_Surface* lctrl_surf;
    SDL_Texture* lctrl_texture;
    SDL_Rect lctrl_rect{80, 400, 0, 0};

    SDL_Surface* space_surf;
    SDL_Texture* space_texture;
    SDL_Rect space_rect{80, 500, 0, 0};

    SDL_Surface* press_space_surf;
    SDL_Texture* press_space_texture;
    SDL_Rect press_space_rect{450, 720, 0, 0};
    
public:
    GameOutro();
    ~GameOutro() = default;
    void handleEvents() override;
    void render(int score, Uint32 &frameStart);
    bool ended() {return end;}
    bool close_all() {return close_all_of;};
    void set_ended_false() {end = false;};
    void init_textures();
    void display_text(int score);
};
#endif