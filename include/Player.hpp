#ifndef PLAYER_H
#define PLAYER_H

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
        bool isCrewmate;
        sf::Texture texture;
        void createSprite(sf::Texture& texture);

        AnimationHelper* animationHelper;
        MovementHelper* movementHelper;

    protected:
        sf::RectangleShape shape; // For hitbox
        sf::Sprite sprite;

    public:
        Player(float x, float y, sf::Texture& texture);
        virtual ~Player();

        void createAnimationHelper(sf::Texture& textureSheet);
        void createMovementHelper(const float maxVelocity, const float minVelocity);

        virtual void setPosition(const float x, const float y);
        virtual void move(const float& dt, const float east, const float north);

        virtual void update(const float& dt); // Change to pure virtual ?
        virtual void render(sf::RenderTarget* target); // Change to pure virtual ?
};

#endif