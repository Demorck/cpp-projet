#ifndef MOVEMENT_HELPER_H
#define MOVEMENT_HELPER_H

#include <map>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class MovementHelper
{
    private:
        float maxVelocity;
        float minVelocity;

        sf::Vector2f velocity;
        sf::Vector2f acceleration;
        sf::Vector2f deceleration;

    public:
        MovementHelper(float maxVelocity, float minVelocity);
        virtual ~MovementHelper();

        const sf::Vector2f& getVelocity() const;

        void move(const float directionX, const float directionY);
        void update(const float& dt);
};

#endif