#ifndef STATE_H
#define STATE_H


/**
 * @file State.hpp
 * @author Maximilien ANTOINE
 * @brief To manage states (start, display, delete)
 * @version 0.1
 * @date 2020-10-12
 * 
 */
#include <Player.hpp>

class State {
    private:
        // Variables
        sf::RenderWindow* window;
        bool quit;

        // Pure virtual functions
        virtual void initKeybinds() = 0;

    public:
        /**
         * @brief Construct a new State object
         * 
         * @param window The window to render, update, etc.
         */
        State(sf::RenderWindow* window);

        /**
         * @brief Destroy the State object
         * 
         */
        virtual ~State();

        /**
         * @brief Get the Quit object
         * 
         * @return true if quit == true
         * @return false otherwise
         */
        const bool& getQuit();

        /**
         * @brief If escape is pressed, quit = true
         * 
         */
        virtual void checkQuitState();

        // Pure virtual functions
        virtual void updateInputs(const float &dt) = 0;
        virtual void endState() = 0;
        virtual void update(const float& dt) = 0;
        virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

#endif