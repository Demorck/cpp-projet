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
#include <States/MainMenuState.hpp>

class Game
{
    private:
        // Variables
        sf::RenderWindow* window;
        sf::VideoMode videoMode; 
        sf::Event event;

        // Variables for time & ticks
        sf::Clock dtClock;  // time to update & render 1 frame
        float deltaTime;    // time to update & render 1 frame

        // Stack for states to switch easily
        std::stack<State*> states;

        // Functions
        // Initialize variables
        void initVariables();
        // Initialize windows
        void initWindow();
        // Initialize states
        void initStates();

    public:
        // Constructor / destructor
        Game();
        virtual ~Game();

        /**
         * @brief Poll event from keyboard
         * 
         */
        void pollEvents();

        /*!
         * @brief Update the game
         * 
         */
        void update();

        /*!
         * @brief Render game
         * 
         */
        void render();

        /*!
         * @brief Return true if windows is open
         * 
         * @return true if windows is open
         * @return false otherwise
         */
        bool isOpen() const;

        /*!
         * @brief Update the delta time between each tick
         * 
         */
        void updateDeltaTime();

        /*!
         * @brief Main loop for the game
         * 
         */
        void run();
};


#endif