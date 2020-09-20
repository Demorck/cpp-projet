#include <Game.hpp>
#include <GL/gl.h>

int main()
{
   Game game;

    while (game.isOpen())
    {
        game.update();

        game.render(); 
    }
    

    return 0;
}