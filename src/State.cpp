#include "State.hpp"

State::State(sf::RenderWindow* window, std::stack<State *>* states)
{
    this->window = window;
    this->states = states;
    this->quit = false;
}

State::~State() {

}

void State::updateMousePosition()
{
    this->mousePosScreen = sf::Mouse::getPosition();
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

void State::checkQuitState()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) //TODO: Handler to quit 1 state at once
    {
        this->quit = true;
    }
    
}

const bool& State::getQuit()
{
    return this->quit;
}
