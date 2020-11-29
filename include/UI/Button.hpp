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

enum buttonType{BTN_TEXT = 0, BTN_IMG};
enum buttonState{BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};

class Button
{
    private:
        short unsigned state;
        short unsigned type;

        sf::Texture textureShape;
        sf::Texture textureShapeHover;

        sf::RectangleShape shape;
        sf::Font* font;
        sf::Text text;

        sf::Color idleColor;
        sf::Color hoverColor;
        sf::Color activeColor;

    public:
        /**
         * @brief Construct a new Button
         * 
         * @param x x position
         * @param y y position
         * @param width Width
         * @param height Height
         * @param text Text on button
         * @param font Font for the current text
         * @param idleColor Color when the button is in idle state
         * @param hoverColor Color when the button is in hover state
         * @param activeColor Color when the button is in active state
         */
        Button(float x, float y, float width, float height,
                std::string text, sf::Font* font,
                sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
        
        Button(float x, float y, float width, float height,
                sf::Texture buttonTexture, sf::Texture buttonTextureHover);
        ~Button();

        /**
         * @brief Check if the button is pressed
         * 
         * @return true if it's pressed
         * @return false if not
         */
        bool isPressed() const;

        /**
         * @brief Check if the button is hovered
         * 
         * @return true if it's hovered
         * @return false if not
         */
        bool isHovered() const;

        /**
         * @brief Update the button
         * 
         * @param mousePosition 
         */
        void update(const sf::Vector2f mousePosition);

        /**
         * @brief Render the button
         * 
         * @param target Current window
         */
        void render(sf::RenderTarget* target);
};

#endif