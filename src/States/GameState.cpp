#include <States/GameState.hpp>

GameState::GameState(sf::RenderWindow* window, std::stack<State *>* states)
    : State(window, states)
{
    this->initKeybinds();
    this->initTextures();
    this->initTextures();
    this->initPlayers();
}

GameState::~GameState()
{
    delete this->player;

    for (auto i = this->players.begin(); i != this->players.end(); i++)
    {
        delete i->second;
    }
}

void GameState::endState()
{
    std::cout << "Ending GameState\n";
}

void GameState::initKeybinds()
{
    INIReader reader("config/Settings.ini");

    if (reader.ParseError() < 0)
    {
        std::cout << "Can't load 'Settings.ini'";
    }
    else
    {
        this->keybinds["MOVE_UP"] = reader.GetInteger("INPUT", "MOVE_UP", -1);
        this->keybinds["MOVE_LEFT"] = reader.GetInteger("INPUT", "MOVE_LEFT", -1);
        this->keybinds["MOVE_RIGHT"] = reader.GetInteger("INPUT", "MOVE_RIGHT", -1);
        this->keybinds["MOVE_DOWN"] = reader.GetInteger("INPUT", "MOVE_DOWN", -1);
    }
    
}

void GameState::initTextures()
{
    sf::Texture currentTexture;
    if (currentTexture.loadFromFile("assets/sprites/player/spritesheet.png"))
    {
        this->textures["PLAYER_SHEET"] = currentTexture;
    }
    else
    {
        std::cout << "Erreur";
    }   
}

void GameState::initPlayers()
{
    this->player = new Player(50, 50, this->textures["PLAYER_SHEET"]);

    this->players["Bot1"] = new Player(300, 300, this->textures["PLAYER_SHEET"]);
}

void GameState::updateInputs(const float& dt)
{
    this->checkQuitState(); 

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
        this->player->move(dt, 0.0f, -1.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
        this->player->move(dt, -1.0f, 0.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
        this->player->move(dt, 0.0f, 1.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
        this->player->move(dt, 1.0f, 0.0f);

    
}

void GameState::update(const float& dt)
{
    this->updateInputs(dt);
    this->updateMousePosition();
    this->player->update(dt);
    this->players["Bot1"]->update(dt);

    if (this->player->getHitboxHelper()->isIntersect(this->players["Bot1"]->getHitboxHelper()->getNextPosition(sf::Vector2f(0, 0))))
    {
        this->player->getHitboxHelper()->textIntersect();
        this->players["Bot1"]->getHitboxHelper()->textIntersect();
    }
    
    
}

void GameState::render(sf::RenderTarget* target)
{
    this->player->render(target);
    this->players["Bot1"]->render(target);
}
