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

    //create the renderer
    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == nullptr)
    {
        SDL_DestroyWindow(win);
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }


    // load a bitmap image and get a surface
    std::string imagePath = getResourcePath("Lesson1") + "hello.bmp";
    SDL_Surface *bmp = SDL_LoadBMP(imagePath.c_str());
    if (bmp == nullptr)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        std::cout << "SDL LoadBitmap Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }


    // load image to the renderer and get a texture. We can then free the surface
    SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
    SDL_FreeSurface(bmp);
    if (tex == nullptr)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        std::cout << "SDL CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }


    for (int i = 0; i < 3; ++i)
    {
        // clear renderer
        SDL_RenderClear(ren);
        // draw texture
        SDL_RenderCopy(ren, tex, NULL, NULL);
        // update screen
        SDL_RenderPresent(ren);
        SDL_Delay(1000);
    }



    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
