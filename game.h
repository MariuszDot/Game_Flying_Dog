#ifndef _GAME_H_
#define _GAME_H_
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_mixer.h"
#include "static_object.h"
#include "player.h"
#include "Bird.h"
#include "fireball.h"
#include "textures.h"
#include "explosion.h"
#include <memory>
#include <vector>
#include <algorithm>

class Game {
private:
                // Timers for adding enemies, background and limiting amount of player fire (bombs and fireballs)
    Uint32 time_passed_fireball {0};
    Uint32 time_passed_bombs {0};
    Uint32 time_points {0};
    Uint32 time_passed_enemies {0};
    Uint32 time_passed_buildings {0};
    Uint32 time_passed_trees {0};
    SDL_Window *window{nullptr};
    bool initialized_successfully{false};
    bool close_all_of {false};
    bool end {false};
                // Containers for game objects, enemies, buildings etc.
    std::unique_ptr<Player> player;
    std::unique_ptr<StaticObject> background_sky;
    std::unique_ptr<StaticObject> background_earth;
    std::unique_ptr<StaticObject> venom_head;
    std::vector<std::unique_ptr<StaticObject>> background;
    std::vector<std::unique_ptr<Bird>> black_bird;
    std::vector<std::unique_ptr<Bird>> green_bird;
    std::vector<std::unique_ptr<Bird>> blue_bird;
    std::vector<std::unique_ptr<Fireball>> fireballs;
    std::vector<std::unique_ptr<StaticObject>> buildings;
    std::vector<std::unique_ptr<StaticObject>> bombs;
    std::vector<std::unique_ptr<Explosion>> explode;
    std::vector<std::unique_ptr<Sparks>> sparks;
                // Displaying score and remaining lives
    SDL_Surface* surface_score;
    SDL_Texture* score;
    SDL_Rect score_rect {500, 0, 0, 0};
    int score_number {0};
    char score_text[20] ; 
    SDL_Surface* surface_lives;
    SDL_Texture* lives_texture;
    SDL_Rect lives_rect {800, 0, 0, 0};
    int lives_number {3};
    char lives_text[5];
    SDL_Color dark_blue {9, 9, 111};
                // Containers for textures of animated objects
    std::vector<SDL_Texture*> black_bird_tex;
    std::vector<SDL_Texture*> green_bird_tex;
    std::vector<SDL_Texture*> blue_bird_tex;
    std::vector<SDL_Texture*> fireball_tex;
    std::vector<SDL_Texture*> explosion_tex;
    std::vector<SDL_Texture*> bird_hit_tex;
    
    Mix_Chunk* birdhit_sound;
    Mix_Chunk* explosion_sound;

public:
    Game();
    virtual ~Game();
    static SDL_Renderer* renderer;
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    virtual void handleEvents();
    virtual void update(const Uint32 &frameStart);
    void render(const Uint32 &frameStart);
    void clean();
    bool ended() {return end;};
    void set_ended_false() {end = false; player->set_end_false();};
    bool initialized() {return initialized_successfully;};
    void set_initialize_false() {initialized_successfully = false;};
    bool close_all() {return close_all_of;};
    void player_init(){player = std::make_unique<Player>(renderer, "graphics/Venom_in_airplane_124x98.png", 300, 150, 10, 5, 105, 85);};
    void set_background();
    void kill_sprites();
    void add_background(const Uint32 &frameStart);
    void add_enemies(const Uint32 &frameStart);
    void collision();
    void add_fireballs(const Uint32 &frameStart);
    void add_buildings(const Uint32 &frameStart);
    void add_bombs(const Uint32 &frameStart);
    void show_score();
    void add_points(Uint32 frameStart);
    void game_restart();
    int get_score() { return score_number; };
    void close_music();
};
#endif