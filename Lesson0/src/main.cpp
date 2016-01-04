#include <iostream>
#include <string>
#include <SDL.h>
#include "res_path.h"

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
    // test the get resouce path header
    std::cout << "Resource path is: " << getResourcePath() << std::endl;

    SDL_Quit();
    return 0;
}
