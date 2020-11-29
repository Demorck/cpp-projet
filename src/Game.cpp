#include "Game.hpp"

void Game::initVariables()
{
    this->window = nullptr;
    this->settings = new Settings();
}

void Game::initWindow()
{

    this->videoMode.height = this->settings->getWindowHeight();
    this->videoMode.width = this->settings->getWindowWidth();
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    this->window = new sf::RenderWindow(this->videoMode, this->settings->getTitle(), sf::Style::Titlebar | sf::Style::Close, settings);
    this->window->setFramerateLimit(120);
}

void Game::initStates()
{
    this->states.push(new MainMenuState(this->window, &this->states));
}

Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initStates();

}

Game::~Game()
{
    delete this->window;
    delete this->settings;

    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
    
}

void Game::pollEvents()
{
    while(this->window->pollEvent(this->event))
    {
        switch (this->event.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        default:
            break;
        }
    }
}

void Game::update()
{
    this->pollEvents();

    if (!this->states.empty())
    {
        this->states.top()->update(this->deltaTime);

        if (this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    else
    {
        this->window->close();
    }
    
}

void Game::render()
{
    this->window->clear(sf::Color(0, 0, 0, 255));

    if (!this->states.empty())
        this->states.top()->render(this->window);
    

    this->window->display();
}

bool Game::isOpen() const
{
    return this->window->isOpen();
}

void Game::updateDeltaTime()
{
    this->deltaTime = this->dtClock.restart().asSeconds();
}

void Game::run()
{
    while (this->isOpen())
    {
        this->updateDeltaTime();
        this->update();
        this->render(); 
    }
}