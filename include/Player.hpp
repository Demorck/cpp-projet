#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <stack>
#include <map>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <Constants.hpp>

class Player
{
    private:
        bool isCrewmate;

    protected:
        sf::RectangleShape shape; // For hitbox
        float movementSpeed;

    public:
        Player();
        virtual ~Player();

        virtual void move(const float& dt, const float east, const float north);
        virtual void update(const float& dt); // Change to pure virtual ?
        virtual void render(sf::RenderTarget* target); // Change to pure virtual ?
};

#endif