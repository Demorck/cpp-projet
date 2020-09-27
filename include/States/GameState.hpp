#ifndef GAMESTATE_H
#define GFAMESTATE_H

#include <State.hpp>
#include <Libs/INIReader.h>

class GameState:
    public State
{
    private:
        Player player;
        void initKeybinds();
        std::map<std::string, int> keybinds;

    public:
        GameState(sf::RenderWindow* window);
        virtual ~GameState();

        void endState();
        void updateInputs(const float& dt);
        void update(const float& dt);
        void render(sf::RenderTarget* target = nullptr);
};

#endif