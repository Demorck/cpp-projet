#include <States/MainMenuState.hpp>

MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State *>* states)
    : State(window, states)
{
    this->initFonts();
    this->initKeybinds();
    this->initButtons();
    this->initBackground();
    this->initVariables();

    this->background.setFillColor(sf::Color::Yellow);
}

MainMenuState::~MainMenuState()
{
    for (auto i = this->buttons.begin(); i != this->buttons.end(); i++)
    {
        delete i->second;
    }
    
}

void MainMenuState::endState()
{
    std::cout << "Ending MainMenuState\n";
}

void MainMenuState::initVariables()
{

}

void MainMenuState::initBackground()
{
    this->background.setSize(sf::Vector2f((float)this->window->getSize().x, (float)this->window->getSize().y));

    if(!this->backgroundTexture.loadFromFile("assets/sprites/background/MainMenu.jpg"))
        throw "Error when loading background in MainMenuState";

    this->background.setTexture(&this->backgroundTexture);
}

void MainMenuState::initFonts()
{
    if (!this->font.loadFromFile("assets/fonts/Comic sans ms.ttf"))
    {
        throw("Font couldn't load in MainMenuState");
    }
}

void MainMenuState::initKeybinds()
{
    
}

void MainMenuState::initButtons()
{
    this->buttons["GAME_STATE"] = new Button(100, 100, 150, 50, "Game state", &this->font, sf::Color(138, 138, 138), sf::Color(123, 123, 123), sf::Color(52, 170, 173));
    this->buttons["EXIT_STATE"] = new Button(100, 200, 150, 50, "Exit state", &this->font, sf::Color::Red, sf::Color::Blue, sf::Color::White);

    sf::Texture tempTexture;
    if(!tempTexture.loadFromFile("assets/sprites/buttons/check.png"))
        throw "Error when loading check in MainMenuState";
    
    sf::Texture tempTextureHover;
    if(!tempTexture.loadFromFile("assets/sprites/buttons/checkHover.png"))
        throw "Error when loading check in MainMenuState";

    // this->buttons["CHECK_BTN"] = new Button(100, 400, 150, 150, tempTexture, tempTextureHover);
}

void MainMenuState::updateInputs(const float& dt)
{
    this->checkQuitState(); 
}

void MainMenuState::updateButtons()
{
    for (auto &i : this->buttons)
    {
        i.second->update(this->mousePosView);
    }

    if (this->buttons["GAME_STATE"]->isPressed())
    {
        this->states->push(new GameState(this->window, this->states));
    }
    
    if (this->buttons["EXIT_STATE"]->isPressed())
    {
        this->quit = true;
    }
}

void MainMenuState::update(const float& dt)
{
    this->updateInputs(dt);
    this->updateMousePosition();
    this->updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
    for (auto &i : this->buttons)
    {
        i.second->render(target);
    }
}

void MainMenuState::render(sf::RenderTarget* target)
{
    // if (!target)
    //     target = this->window;
    
    target->draw(this->background);
    this->renderButtons(target);
}