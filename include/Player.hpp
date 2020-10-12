#ifndef PLAYER_H
#define PLAYER_H

/**
 * @file Player.hpp
 * @author Maximilien ANTOINE
 * @brief Player main header
 * @version 0.1
 * @date 2020-10-12
 * 
 */
#include <vector>
#include <stack>
#include <map>
#include <iostream>

#include <Helpers/AnimationHelper.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <Constants.hpp>


class Player
{
    private:
        // Variables
        sf::Texture texture;
        sf::Sprite sprite;
        sf::RectangleShape shape; // For hitbox ?

        // Variables Helper
        AnimationHelper* animationHelper;
        MovementHelper* movementHelper;

        // Function
        // Create sprite
        void createSprite(sf::Texture& texture);

    public:
        /**
         * @brief Construct a new Player object
         * 
         * @param x default position on x
         * @param y default position on y
         * @param texture texture sheet of player
         */
        Player(float x, float y, sf::Texture& textureSheet);

        /**
         * @brief Destroy the Player object
         * 
         * Destroy helpers variables
         */
        virtual ~Player();

        /**
         * @brief Create a Animation Helper object 
         * 
         * @param textureSheet textureSheet for animation
         */
        void createAnimationHelper(sf::Texture& textureSheet);

        /**
         * @brief Create a Movement Helper object
         * 
         * @param maxVelocity max velocity to avoid glitches, bugs & infinite speed forward
         * @param minVelocity min velocity to avoid glitches, bugs & infinite speed backward (like SM64 & WW) (not implemented yet)
         */
        void createMovementHelper(const float maxVelocity, const float minVelocity);

        /**
         * @brief Set the Position of player 
         * 
         * @param x position on x
         * @param y position on y
         */
        virtual void setPosition(const float x, const float y);

        /**
         * @brief Move the player
         * 
         * @param dt the delta time
         * @param directionX 1.f if east, -1.f if west
         * @param directionY 1.f if north, -1.f if south
         */
        virtual void move(const float& dt, const float directionX, const float directionY);

        /**
         * @brief Update the player
         * 
         * @param dt the delta time
         */
        virtual void update(const float& dt);

        /**
         * @brief Render the player
         * 
         * @param target the window
         */
        virtual void render(sf::RenderTarget* target);
};

#endif