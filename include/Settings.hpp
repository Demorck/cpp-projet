#ifndef SETTINGS_H
#define SETTINGS_H

#include <iostream>
#include <Libs/iniReader.h>
#include <SFML/System.hpp>

class Settings
{
    private:
        int windowWidth;
        int windowHeight;
        sf::String title;

    public:
        Settings(/* args */);
        ~Settings();
        
        void initVariables();
        
        // void setSettings();

        // Accessors
        int getWindowWidth();
        int getWindowHeight();
        sf::String getTitle();
};


#endif