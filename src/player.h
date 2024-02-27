#ifndef PLAYER_H
#define PLAYER_H

#include "animated_sprite.h"
#include <string>

class Graphics;

class Player : public AnimatedSprite {
    public:
    Player();
    Player(Graphics &graphics, std::string &filePath, float x, float y);
    void draw(Graphics &graphics);
    void update(float elapsedTime);

    virtual void animationDone(std::string currentAnimation);
    virtual void setupAnimations();


    private:
};

#endif