#ifndef GAME_H
#define GAME_H

/*!
 * @file Game.hpp
 * @author Maximilien ANTOINE
 * @brief Game statement and a lot of stuffs
 * @version 0.1
 * @date 2020-09-21
 */
#include <States/GameState.hpp>

class Game
{
    private:
        sf::RenderWindow* window;
        sf::VideoMode videoMode; 
        sf::Event event;

        sf::Clock dtClock;  // time to update & render 1 frameT
        float deltaTime;    // time to update & render 1 frameT

        std::stack<State*> states;

        void initVariables();
        void initWindow();
        void initStates();

    public:
        Game();
        virtual ~Game();

        
        void pollEvents();
        void update();
        void render();

        bool isOpen() const;
        void updateDeltaTime();
        void run();
};


#endif