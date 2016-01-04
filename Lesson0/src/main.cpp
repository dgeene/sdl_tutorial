#include <iostream>
#include <SDL.h>

/*
 * Sanity check for SDL library
 */
int main(int, char**)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "SDL Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    SDL_Quit();
    return 0;
}
