#include "include/SDL.h"
#include "include/SDL2_gfxPrimitives.h"
#include <cmath>


int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("2D RTX", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // draw here
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    circleRGBA(renderer,320,240,50,0,255,0,255);

    SDL_RenderPresent(renderer);
    SDL_Delay(3000);

    return 0;
}