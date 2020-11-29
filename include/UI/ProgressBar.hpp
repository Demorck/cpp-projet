#ifndef PROGRESS_BAR_H
#define PROGRESS_BAR_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class ProgressBar
{
    private:
        std::string barString;
        sf::Text text;
        float maxWidth;
        sf::RectangleShape back;
        sf::RectangleShape inner;

    public:
        ProgressBar(float x, float y, float width, float height, sf::Color innerColor, sf::Font* font = NULL);
        ~ProgressBar();

        void update(const int currentValue, const int maxValue);
        void render(sf::RenderTarget* target);
};

#endif