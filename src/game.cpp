#include <SDL2/SDL.h>

#include "graphics.h"
#include "game.h"
#include "input.h"
#include <iostream>

namespace {
    const int FPS = 50;
    const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}

Game::Game(){
    SDL_Init(SDL_INIT_EVERYTHING);
    this->gameLoop();
}

Game::~Game(){}

void Game::gameLoop(){
    Graphics graphics;
    Input input;
    SDL_Event event;
    
    this->_player = Sprite(graphics, "media/sprites/MyChar.png", 0, 0, 16, 16, 100, 100);

    while(true){
        Uint64 start = SDL_GetPerformanceCounter();
        input.beginNewFrame();
        if(SDL_PollEvent(&event)){
            cout << event.type << endl;
            if(event.type == SDL_KEYDOWN){
               if(event.key.repeat == 0){
                input.keyDownEvent(event);
               } 
            }
            else if(event.type == SDL_KEYUP){
                input.keyUpEvent(event);
            }

            else if(event.type == SDL_QUIT){
                return;
            }
            
        }
        if(input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true){
            return;
        }


        this->draw(graphics);
        Uint64 end = SDL_GetPerformanceCounter();
        float elapsedMS = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;

        SDL_Delay(floor(16.666f - elapsedMS));
        float elapsed = (end - start) / (float) SDL_GetPerformanceFrequency();
        cout << "Current FPS: " << to_string(1.0f / elapsed) << endl;
    }
}
void Game::draw(Graphics &graphics){
    graphics.clear();

    this->_player.draw(graphics, 100, 100);

    graphics.flip();

}

void Game::update(float elapsedTime){

}