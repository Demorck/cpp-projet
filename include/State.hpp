#ifndef STATE_H
#define STATE_H

#include <Player.hpp>

class State {
    private:
        sf::RenderWindow* window;
        bool quit;

        virtual void initKeybinds() = 0;

    public:
        State(sf::RenderWindow* window);
        virtual ~State();
        const bool& getQuit();

        virtual void checkQuitState();
        virtual void updateInputs(const float &dt) = 0;
        virtual void endState() = 0;
        virtual void update(const float& dt) = 0;
        virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

#endif