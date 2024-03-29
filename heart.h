#ifndef hrt
#define hrt
#include "Game.h"

class Heart
{
    private:
        int x, y;
        SDL_Texture* obtex;
        SDL_Rect src, dst;
    public:
        Heart(const char* texsheet, int inx, int iny);
        ~Heart();
        void update();
        void render();
};
#endif