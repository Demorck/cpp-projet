#pragma once

/*!
 * @file Game.hpp
 * @author Maximilien ANTOINE
 * @brief Game statement and a lot of stuffs
 * @version 0.1
 * @date 2020-09-21
 */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <Constants.hpp>


class Game
{
    private:
        sf::RenderWindow* window;
        sf::VideoMode videoMode; 
        sf::Event event;

        void initVariables();
        void initWindow();

    public:
        /*!
         * @brief Constructor
         * 
         * Construct the game class
         */
        Game();

        /*!
         * @brief Destructeur
         * 
         * Destruct the game class
         */
        virtual ~Game();

        /*!
         * @brief Poll events
         * 
         * Poll events from window
         */
        void pollEvents();

        /*!
         * @brief Update game class
         * 
         * Update game's logic
         */
        void update();

        /*!
         * @brief Render game window
         * 
         * 
         * Draw object and render game window
         */
        void render();

        /*!
         * @brief Test if the window is open
         * 
         * @return true if the window is open
         */
        bool isOpen() const;
};