#include <iostream>
#include <string>
#include <SDL.h>
#include "res_path.h"

/*
 * Lesson 1: Draw bitmap
 */
int main()
{

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "SDL Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }


    //create a window
    SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (win == nullptr)
    {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return 1;
    }
}
