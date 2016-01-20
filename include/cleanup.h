#ifndef CLEANUP_H
#define CLEANUP_H

#include <utility>
#include <SDL.h>
/*
 * Provides and easy way to cleanup SDL for error handling or program exit.
 */



/*
 * Recurse through the list of arguments to clean up, cleaning up
 * the first one in the list each iteration.
 */
template<typename T, typename... Args>
void cleanup(T *t, Args&&.. Args)
{
    cleanup(t); // clean first item in the list
    cleanup(std::forward<Args>(args)...); // recurse to clean up remaining args
}







/*
 * These serve to free the passed argument and provide the base cases
 * for the recursive call aove, eg. when args is only a single item
 * one of the specials below will be called by
 * cleanup(std::forward<Args>(args)...), ending the recursion.
 * We'll make it safe to pass nullptrs to handle situations where we
 * don't want to bother finding out which values failed to load.
 * But rather we may just want to clean everything up and let cleanup sort it out.
 */
template<>
void cleanup<SDL_Window>(SDL_Window *win)
{
    if (!win)
        return;
    SDL_DestroyWindow(win);
}


template<>
void cleanup<SDL_Renderer>(SDL_Renderer *ren)
{
    if (!ren)
        return;
    SDL_DestroyRenderer(ren);
}


template<>
void cleanup<SDL_Texture>(SDL_Texture *tex)
{
    if (!tex)
        return;
    SDL_DestroyTexture(tex);
}


template<>
void cleanup<SDL_Surface>(SDL_Surface *surf)
{
    if (!surf)
        return;
    SDL_FreeSurface(surf);
}
#endif
