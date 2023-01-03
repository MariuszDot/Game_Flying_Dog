#include "game.h"

SDL_Renderer *Game::renderer{nullptr};

Game::Game()
: end{false} {};
Game::~Game() {};

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

    int flags {0};
    if(fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(window) {
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 51, 51, 255, 255);
        }
        initialized_successfully = true;
    }else {
        initialized_successfully = false;
    }
                // Initialization of music and animated objects textures
    TTF_Init();
    Mix_Init(0);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    birdhit_sound = Mix_LoadWAV("graphics/audio/birds.wav");
    explosion_sound = Mix_LoadWAV("graphics/audio/explosion07.wav");
    Mix_VolumeChunk(birdhit_sound, 55);
    Mix_VolumeChunk(explosion_sound, 100);
    SDL_Surface* icon {IMG_Load("graphics/paws.png")};
    SDL_SetWindowIcon(window, icon);
    time_passed_fireball = time_passed_bombs = SDL_GetTicks();
    initialize_textures_black_bird(black_bird_tex, renderer);
    initialize_textures_green_bird(green_bird_tex, renderer);
    initialize_textures_blue_bird(blue_bird_tex, renderer);
    initialize_textures_fireball(fireball_tex, renderer);
    initialize_textures_explosion(explosion_tex, renderer);
    initialize_textures_bird_hit(bird_hit_tex, renderer);
}

void Game::handleEvents() {
    player->handle_events();
    if (player->close_all()) close_all_of = true; 
}

void Game::update(const Uint32 &frameStart) {
    player->update();
    if (player->ended()) end = true;
    background_sky->moving(2, true);
    background_earth->moving(2, true);
    kill_sprites();
    for (auto &val: fireballs){
        val->update(frameStart);
    }
    collision();
    add_background(frameStart);
    for (auto &val: background){
        val->moving(5, false);
    }
    add_enemies(frameStart);
    for (auto &val: black_bird) {
        val->update(frameStart);
    }
    for (auto &val: green_bird) {
        val->update(frameStart);
    }
    for (auto &val: blue_bird) {
        val->update(frameStart);
    }
    add_fireballs(frameStart);
    add_buildings(frameStart);
    for (auto &val: buildings) {
        val->moving(5, false);
    }
    add_bombs(frameStart);
    for (auto &val: bombs) {
        val->moving_down(6);
    }
    for (auto &val: explode) {
        val->update();
    }
    add_points(frameStart);
    if (lives_number == 0) end = true;
}

void Game::render(const Uint32 &frameStart) {
    SDL_RenderClear(renderer);
    background_sky->draw(renderer);
    for (auto &val: background){
        val->draw(renderer);
    }
    for (auto &val: buildings) {
        val->draw(renderer);
    }
    for (auto &val: bombs) {
        val->draw(renderer);
    }
    for (auto &val: explode) {
        val->draw(renderer, explosion_tex, frameStart);
    }
    background_earth->draw(renderer);
    for (auto &val: black_bird) {
        val->draw(renderer, black_bird_tex, frameStart);
    }
    for (auto &val: green_bird) {
        val->draw(renderer, green_bird_tex, frameStart);
    }
    for (auto &val: blue_bird) {
        val->draw(renderer, blue_bird_tex, frameStart);
    }
    for (auto &val: fireballs) {
        val->draw(renderer, fireball_tex, frameStart);
    }
    for (auto &val: sparks) {
        val->draw(renderer, bird_hit_tex, frameStart);
    }
    player->draw(renderer);
    show_score();
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    Mix_CloseAudio();
    Mix_Quit();
    SDL_Quit();
}

void Game::set_background() {
    background_sky = std::make_unique<StaticObject>("graphics/blue_sky_800_2.png", -5, 0, 2000, 800, renderer);
    background_earth = std::make_unique<StaticObject>("graphics/trawa_3000.png", -5, 650, 2200, 150, renderer);
    venom_head = std::make_unique<StaticObject>("graphics/venom_happy_450.png", 720, 0, 64, 78, renderer);
}

void Game::add_background(const Uint32 &frameStart) {
                // Random addition of background. Combination of random choosing between three and different x positions of each object, makes every playthrough very unique
    if ((frameStart-time_passed_trees) > 800) {
        int tree {rand() % 3};          // Order below is important. rand() is not evenly distributing with small numbers. We want more trees than towers.
        if (tree == 0) background.push_back(std::make_unique<StaticObject>("graphics/tree_250.png", 1650, 525, 359, 250, renderer));
        if (tree == 1) background.push_back(std::make_unique<StaticObject>("graphics/tree_300.png", 1500, 500, 300, 300, renderer));
        if (tree == 2) background.push_back(std::make_unique<StaticObject>("graphics/tower_175.png", 1400, 600, 54, 175, renderer));
        time_passed_trees = frameStart;
    }
}

void Game::kill_sprites() {
    background.erase(std::remove_if(background.begin(), background.end(), [] (std::unique_ptr<StaticObject> &p) {return (p->get_xpos()) < -360;}), background.end());
    black_bird.erase(std::remove_if(black_bird.begin(), black_bird.end(), [] (std::unique_ptr<Bird> &p) {return ((p->get_xpos()) < -100 || p->kill_getter());}), black_bird.end());
    green_bird.erase(std::remove_if(green_bird.begin(), green_bird.end(), [] (std::unique_ptr<Bird> &p) {return ((p->get_xpos()) < -50 || p->kill_getter());}), green_bird.end());
    blue_bird.erase(std::remove_if(blue_bird.begin(), blue_bird.end(), [] (std::unique_ptr<Bird> &p) {return ((p->get_xpos()) < -50 || p->kill_getter());}), blue_bird.end());
    fireballs.erase(std::remove_if(fireballs.begin(), fireballs.end(), [] (std::unique_ptr<Fireball> &p) {return (p->is_killed() || p->get_xpos() > 1300);} ), fireballs.end());
    buildings.erase(std::remove_if(buildings.begin(), buildings.end(), [] (std::unique_ptr<StaticObject> &p) { return ((p->get_xpos()) < -280 || (p->kill_is_enabled() && p->is_kill())); }), buildings.end() );
    bombs.erase(std::remove_if(bombs.begin(), bombs.end(), [] (std::unique_ptr<StaticObject> &p) { return (p->get_ypos() > 800 || p->is_kill()); }), bombs.end());
    explode.erase(std::remove_if(explode.begin(), explode.end(), [] (std::unique_ptr<Explosion> &p) { return p->is_kill(); } ), explode.end());
    sparks.erase(std::remove_if(sparks.begin(), sparks.end(), [] (std::unique_ptr<Sparks> &p) { return p->is_kill() ;} ), sparks.end() );
    
}

void Game::add_enemies(const Uint32 &frameStart) {
    if ((frameStart-time_passed_enemies) > 1000) {
        int random_bird {rand()%3};
        int random_x {rand()%100 + 1300};
        int random_y {rand()%400 + 150};
                    // Random addition of birds with random x and y positions makes every playthrough very unique
        switch (random_bird) {
            case 0:
                black_bird.push_back(std::make_unique<Bird>(random_x, random_y, 90, 64, 20, 10, 55, 40));
                break;
            case 1:
                green_bird.push_back(std::make_unique<Bird>(random_x, random_y, 41, 32, 2, 5, 33, 25));
                break;
            case 2:
                blue_bird.push_back(std::make_unique<Bird>(random_x, random_y, 49, 42, 2, 5, 33, 25));
                break;
            default: break;
        }
        time_passed_enemies = frameStart;
    }
}

void Game::add_buildings(const Uint32 &frameStart) {
    if ((frameStart-time_passed_buildings) > 2000) {
        int rand_b {rand() % 2};
        if (rand_b == 0) {
            int random {rand()%2};          // Order below is important - rand() is not evenly distributing. We want more buildings to collide with player, less chances to score points dropping bombs on black towers
            if (random == 0){
                buildings.push_back(std::make_unique<StaticObject>("graphics/building.png", 1400, 400, 187, 400, renderer)); 
                buildings.back()->init_hitbox(15, 20, 160, 380);
            }else {
                buildings.push_back(std::make_unique<StaticObject>("graphics/building_525.png", 1300, 250, 245, 525, renderer)); 
                buildings.back()->init_hitbox(20, 26, 210, 498);
            }
        }else {
            buildings.push_back(std::make_unique<StaticObject>("graphics/bad_guys_tower.png", 1600, 535, 270, 250, renderer, true));
            buildings.back()->init_hitbox(20, 150, 220, 100);
        }
        time_passed_buildings = frameStart;
    }
}

void Game::add_fireballs(const Uint32 &frameStart) {
    int time = frameStart - time_passed_fireball;
    if (player->is_fire_fireball() && time > 650) {
        fireballs.push_back(std::make_unique<Fireball>((player->get_xpos() + (player->get_width()/2)), (player->get_ypos() + (player->get_height()/2)), 64, 32, renderer));
        time_passed_fireball = frameStart;
    }
}

void Game::add_bombs(const Uint32 &frameStart) {
    int time = frameStart - time_passed_bombs;
    if (player->is_fire_bombs() && time > 800) {
        bombs.push_back(std::make_unique<StaticObject>("graphics/bomb_32x32.png", player->get_xpos(), player->get_ypos(), 32, 32, renderer));
        bombs.back()->init_hitbox(0, 0, 32, 32);
        time_passed_bombs = frameStart;
    }
}

void Game::collision() {
    // Checking collision PLAYER --> BLACK birds
    for (auto &val: black_bird) {
        if ((player->get_hitbox_x() + player->get_hitbox_width()) >= val->get_hitbox_x() &&
            (player->get_hitbox_y() + player->get_hitbox_height()) >= val->get_hitbox_y() &&
            (val->get_hitbox_x() + val->get_hitbox_width()) >= player->get_hitbox_x() &&
            (val->get_hitbox_y() + val->get_hitbox_height()) >= player->get_hitbox_y()) { 
                val->set_to_kill();
                sparks.push_back(std::make_unique<Sparks>( (val->get_xpos() + val->get_width()), (val->get_ypos()), 64, 64) );
                score_number -= 50;
                lives_number -= 1;
                Mix_PlayChannel(-1, birdhit_sound, 0);
        }
    }
    // Checking collision PLAYER --> GREEN birds
    for (auto &val: green_bird) {
        if ((player->get_hitbox_x() + player->get_hitbox_width()) >= val->get_hitbox_x() &&
            (player->get_hitbox_y() + player->get_hitbox_height()) >= val->get_hitbox_y() &&
            (val->get_hitbox_x() + val->get_hitbox_width()) >= player->get_hitbox_x() &&
            (val->get_hitbox_y() + val->get_hitbox_height()) >= player->get_hitbox_y()) { 
                val->set_to_kill();
                sparks.push_back(std::make_unique<Sparks>( (val->get_xpos() + val->get_width()), (val->get_ypos()), 64, 64) );
                score_number -= 30;
                Mix_PlayChannel(-1, birdhit_sound, 0);
        }
    }
    // Checking collision PLAYER --> BLUE birds
    for (auto &val: blue_bird) {
        if ((player->get_hitbox_x() + player->get_hitbox_width()) >= val->get_hitbox_x() &&
            (player->get_hitbox_y() + player->get_hitbox_height()) >= val->get_hitbox_y() &&
            (val->get_hitbox_x() + val->get_hitbox_width()) >= player->get_hitbox_x() &&
            (val->get_hitbox_y() + val->get_hitbox_height()) >= player->get_hitbox_y()) { 
                val->set_to_kill();
                sparks.push_back(std::make_unique<Sparks>( (val->get_xpos() + val->get_width()), (val->get_ypos()), 64, 64) );
                score_number += 30;
                Mix_PlayChannel(-1, birdhit_sound, 0);
        }
    }
    // Checking collision PLAYER --> BUILDING
    for (auto &val: buildings) {
        if ((player->get_hitbox_x() + player->get_hitbox_width()) >= val->get_hitbox_x() &&
            (player->get_hitbox_y() + player->get_hitbox_height()) >= val->get_hitbox_y() &&
            (val->get_hitbox_x() + val->get_hitbox_width()) >= player->get_hitbox_x() &&
            (val->get_hitbox_y() + val->get_hitbox_height()) >= player->get_hitbox_y()) { 
            explode.push_back(std::make_unique<Explosion>( player->get_xpos(), player->get_ypos()-50, 200, 200 ) );
            Mix_PlayChannel(-1, explosion_sound, 0);
            score_number -= 150;
            player.reset();
            player_init();
            lives_number -= 1;
        }
    }
    // Checking colision FIREBALL --> BLACK birds
    for (auto &val: fireballs) {
        for (auto &enemy: black_bird) {
            if ((val->get_hitbox_x() + val->get_hitbox_width()) >= enemy->get_hitbox_x() &&
                (val->get_hitbox_y() + val->get_hitbox_height()) >= enemy->get_hitbox_y() &&
                (enemy->get_hitbox_x() + enemy->get_hitbox_width()) >= val->get_hitbox_x() &&
                (enemy->get_hitbox_y() + enemy->get_hitbox_height()) >= val->get_hitbox_y()) {
                    enemy->set_to_kill();
                    val->set_to_kill();
                    sparks.push_back(std::make_unique<Sparks>( (enemy->get_xpos() + enemy->get_width()), (enemy->get_ypos()), 64, 64) );
                    score_number += 50;
                    Mix_PlayChannel(-1, birdhit_sound, 0);
            }
        }
    }
    // Checking colision FIREBALL --> GREEN birds
    for (auto &val: fireballs) {
        for (auto &enemy: green_bird) {
            if ((val->get_hitbox_x() + val->get_hitbox_width()) >= enemy->get_hitbox_x() &&
                (val->get_hitbox_y() + val->get_hitbox_height()) >= enemy->get_hitbox_y() &&
                (enemy->get_hitbox_x() + enemy->get_hitbox_width()) >= val->get_hitbox_x() &&
                (enemy->get_hitbox_y() + enemy->get_hitbox_height()) >= val->get_hitbox_y()) {
                    enemy->set_to_kill();
                    val->set_to_kill();
                    sparks.push_back(std::make_unique<Sparks>( (enemy->get_xpos() + enemy->get_width()), (enemy->get_ypos()), 64, 64) );
                    score_number += 30;
                    Mix_PlayChannel(-1, birdhit_sound, 0);
            }
        }
    }
    // Checking colision FIREBALL --> BLUE birds
    for (auto &val: fireballs) {
        for (auto &enemy: blue_bird) {
            if ((val->get_hitbox_x() + val->get_hitbox_width()) >= enemy->get_hitbox_x() &&
                (val->get_hitbox_y() + val->get_hitbox_height()) >= enemy->get_hitbox_y() &&
                (enemy->get_hitbox_x() + enemy->get_hitbox_width()) >= val->get_hitbox_x() &&
                (enemy->get_hitbox_y() + enemy->get_hitbox_height()) >= val->get_hitbox_y()) {
                    enemy->set_to_kill();
                    val->set_to_kill();
                    sparks.push_back(std::make_unique<Sparks>( (enemy->get_xpos() + enemy->get_width()), (enemy->get_ypos()), 64, 64) );
                    score_number += 30;
                    Mix_PlayChannel(-1, birdhit_sound, 0);
            }
        }
    }
    // Checking collision BUILDING --> BOMB
    for (auto &val: buildings) { 
        for (auto &bomb: bombs) {
            if ((bomb->get_hitbox_x() + bomb->get_hitbox_width()) >= val->get_hitbox_x() &&
                (bomb->get_hitbox_y() + bomb->get_hitbox_height()) >= val->get_hitbox_y() &&
                (val->get_hitbox_x() + val->get_hitbox_width()) >= bomb->get_hitbox_x() &&
                (val->get_hitbox_y() + val->get_hitbox_height()) >= bomb->get_hitbox_y() ) {
                    if (!val->kill_is_enabled()) { 
                        bomb->set_to_kill(); 
                        explode.push_back(std::make_unique<Explosion>( bomb->get_xpos()-50, bomb->get_ypos()-100, 200, 200 ) );
                        score_number -= 150;
                        Mix_PlayChannel(-1, explosion_sound, 0);
                    }else {
                        val->set_to_kill();
                        score_number += 100;
                        // Mix_PlayChannel(-1, explosion_sound, 0);
                    } 
                    // explode.push_back(std::make_unique<Explosion>( bomb->get_xpos(), bomb->get_ypos(), 200, 200 ) );
                    // val->set_to_kill();
                }
        }
    }
    // Checking collision BOMB --> GROUND
    for (auto &bomb: bombs) {
        if (bomb->get_ypos() > 730) {
            explode.push_back(std::make_unique<Explosion>( bomb->get_xpos()-100, bomb->get_ypos()-180, 200, 200 ));
            bomb->set_to_kill();
            Mix_PlayChannel(-1, explosion_sound, 0);
        }
    }
}

void Game::show_score() {
    TTF_Font* amatic_bold = TTF_OpenFont("graphics/fonts/Amatic-Bold.ttf", 60); 
    char score_num[6];
    strcpy(score_text, "Score: ");
    strcat(score_text, itoa(score_number, score_num, 10));
    surface_score = TTF_RenderText_Blended(amatic_bold, score_text, dark_blue);
    score = SDL_CreateTextureFromSurface(renderer, surface_score);
    score_rect.w = surface_score->w;
    score_rect.h = surface_score->h;
    SDL_RenderCopy(renderer, score, NULL, &score_rect);

    venom_head->draw(renderer);
    char lives_num[3];
    strcpy(lives_text, "X");
    strcat(lives_text, itoa(lives_number, lives_num, 10));
    surface_lives = TTF_RenderText_Blended(amatic_bold, lives_text, dark_blue);
    lives_texture = SDL_CreateTextureFromSurface(renderer, surface_lives);
    lives_rect.w = surface_lives->w;
    lives_rect.h = surface_lives->h;
    SDL_RenderCopy(renderer, lives_texture, NULL, &lives_rect);
    TTF_CloseFont(amatic_bold);
    SDL_FreeSurface(surface_score);
    SDL_DestroyTexture(score);
}

void Game::add_points(Uint32 frameStart) {
    if((frameStart-time_points) > 1000) {
        score_number += 10;
        time_points = frameStart;
    }
}

void Game::game_restart() {
    end = false;
    lives_number = 3;
    score_number = 0;
    background.clear();
    black_bird.clear();
    green_bird.clear();
    blue_bird.clear();
    fireballs.clear();
    buildings.clear();
    bombs.clear();
    explode.clear();
    sparks.clear();
    player.reset();
    player_init();
}

void Game::close_music() {
    Mix_VolumeChunk(explosion_sound, 0);
    Mix_VolumeChunk(birdhit_sound, 0);
}
