#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

enum buttonState{BTN_IDLE = 0, BTN_HOVER, BTN_PRESSED};

class Button
{
    private:
        short unsigned state;

        sf::RectangleShape shape;
        sf::Font* font;
        sf::Text text;

        sf::Color idleColor;
        sf::Color hoverColor;
        sf::Color activeColor;




    public:
        Button(float x, float y, float width, float height,
                std::string text, sf::Font* font,
                sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
        ~Button();

        bool isPressed() const;
        bool isHovered() const;

        sf::RectangleShape sh();

        void update(const sf::Vector2f mousePosition);
        void render(sf::RenderTarget* target);
};

#endif