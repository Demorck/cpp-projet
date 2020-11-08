#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include <State.hpp>
#include <States/GameState.hpp>
#include <UI/Button.hpp>

class MainMenuState:
    public State
{
    private:
        sf::RectangleShape background;
        sf::Font font;

        // Button* gameStateBtn;
        std::map<std::string, Button*> buttons;

        void initFonts();
        void initKeybinds();
        void initButtons();

    public:
        MainMenuState(sf::RenderWindow* window, std::stack<State *>* states);
        virtual ~MainMenuState();

        void endState();
        void updateInputs(const float& dt);
        void updateButtons();
        void update(const float& dt);
        void renderButtons(sf::RenderTarget* target);
        void render(sf::RenderTarget* target = nullptr);
};


#endif