#ifndef MOVEMENT_HELPER_H
#define MOVEMENT_HELPER_H

/**
 * @file MovementHelper.hpp
 * @author Maximilien ANTOINE
 * @brief File to help us to move with velocity, acceleration, etc. (Smooth movement in fact)
 * @version 0.1
 * @date 2020-10-13
 * 
 */
#include <headers.hpp>

class MovementHelper
{
    private:
        sf::Sprite& sprite;

        // Variables
        float maxVelocity;
        float minVelocity;

        sf::Vector2f velocity;
        float acceleration;
        float deceleration;

    public:
        /**
         * @brief Construct a new Movement Helper object
         * 
         * @param maxVelocity max velocity to avoid glitches, bugs & infinite speed forward
         * @param minVelocity min velocity to avoid glitches, bugs & infinite speed backward (like SM64 & WW) (not implemented yet)
         */
        MovementHelper(sf::Sprite& sprite, float maxVelocity, float acceleration, float deceleration);

        /**
         * @brief Destroy the Movement Helper object
         * 
         */
        virtual ~MovementHelper();

        /**
         * @brief Get the Velocity object
         * 
         * @return const sf::Vector2f& 
         */
        const sf::Vector2f& getVelocity() const;

        /**
         * @brief Move the entity
         * 
         * @param directionX 1.f if east, -1.f if west
         * @param directionY 1.f if north, -1.f if south
         */
        void move(const float directionX, const float directionY);

        /**
         * @brief Update the movement
         * 
         * @param dt the deltatime
         */
        void update(const float& dt);
};

#endif