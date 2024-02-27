#ifndef GAME_H
#define GAME_H

#include "player.h"

class Graphics;


class Game {
    public:
    Game();
    ~Game();

    private:
    void gameLoop();
    void draw(Graphics &graphics);
    void update(float elapsedTime);
    void read_animations(std::string &filePath);

    Player _player;
    Player _face;

    //AnimatedSprite _face;
};

#endif