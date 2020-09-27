#include "Game.hpp"

void Game::initVariables()
{
    this->window = nullptr;
}

void Game::initWindow()
{
    this->videoMode.height = WINDOW_HEIGHT;
    this->videoMode.width = WINDOW_WIDTH;
    this->window = new sf::RenderWindow(this->videoMode, "Game", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(120);
}

void Game::initStates()
{
    this->states.push(new GameState(this->window));
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
        case sf::Event::KeyPressed:
            // if (this->event.key.code == sf::Keyboard::Escape)
            //     this->window->close();
            
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