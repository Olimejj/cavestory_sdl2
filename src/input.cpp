#include "input.h"

void Input::beginNewFrame(){
    this->_pressedKeys.clear();
    this->_releasedKyes.clear();

}

void Input::keyDownEvent(const SDL_Event& event ){
    this->_pressedKeys[event.key.keysym.scancode] = true;
    this->_heldKeys[event.key.keysym.scancode] = true;
}

void Input::keyUpEvent(const SDL_Event& event ){
    this->_releasedKyes[event.key.keysym.scancode] = true;
    this->_heldKeys[event.key.keysym.scancode] = false;
}

