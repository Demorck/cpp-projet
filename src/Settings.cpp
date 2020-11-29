#include <Settings.hpp>

Settings::Settings()
{
    INIReader reader("config/Settings.ini");

    if (reader.ParseError() < 0)
        std::cout << "Can't load Settings in Game.cpp";
    
    this->windowWidth = reader.GetInteger("WINDOW", "WIDTH", 800);
    this->windowHeight = reader.GetInteger("WINDOW", "HEIGHT", 600);
    this->title = reader.GetString("WINDOW", "TITLE", "Default title");
}

Settings::~Settings()
{

}

int Settings::getWindowWidth()
{
    return this->windowWidth;
}

int Settings::getWindowHeight()
{
    return this->windowHeight;
}

sf::String Settings::getTitle()
{
    return this->title;
}
