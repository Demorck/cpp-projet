#ifndef GAMESTATE_H
#define GFAMESTATE_H

#include <State.hpp>
#include <Libs/INIReader.h>

class GameState:
    public State
{
    private:
        Player* player;
        std::map<std::string, int> keybinds;

        std::map<std::string, Player*> players;

        std::map<std::string, sf::Texture> textures;
        

        void initKeybinds();
        void initTextures();
        void initPlayers();

    public:
        GameState(sf::RenderWindow* window, std::stack<State *>* states);
        virtual ~GameState();

        void endState();
        void updateInputs(const float& dt);
        void update(const float& dt);
        void render(sf::RenderTarget* target = nullptr);
};

#endif