#include "Game.h"
#include "text.h"
Game *game = nullptr;

int main(int argc, char **argv)
{
    game = new Game();

    const int FPS = 60;
    const int Framedelay = 1000/FPS;

    Uint32 framestart;
    int frametime;

    game->init("Archery", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1300, 800, false);
    text text(Game::renderer,"ARCADECLASSIC.TTF",30,"Scoreboard:",{255,0,0,255});
    while(game->running())
    {

        framestart = SDL_GetTicks();
        game->handle_events();
        game->update();
        game->render();
        text.display(100,100,Game::renderer);
        frametime = SDL_GetTicks() - framestart;

        if(Framedelay > frametime)  SDL_Delay(Framedelay-frametime);
    }
    game->clean();
    return 0;
}