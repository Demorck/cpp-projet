#include "State.hpp"

State::State(sf::RenderWindow* window) {
    this->window = window;
    this->quit = false;
}

State::~State() {

}

void State::checkQuitState()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        this->quit = true;
    }
    
}

const bool& State::getQuit()
{
    return this->quit;
}
