#include "include/SDL.h"
#include <cmath>

//thanks to https://discourse.libsdl.org/t/query-how-do-you-draw-a-circle-in-sdl2-sdl2/33379
void SDL_RenderDrawCircle(SDL_Renderer *renderer, int32_t centreX, int32_t centreY, int32_t radius)
{
    const int32_t diameter = (radius * 2);

    int32_t x = (radius - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - diameter);

    while (x >= y)
    {
        // Each of the following renders an octant of the circle
        SDL_RenderDrawLine(renderer, centreX + x, centreY - y, centreX, centreY);
        SDL_RenderDrawLine(renderer, centreX + x, centreY + y, centreX, centreY);
        SDL_RenderDrawLine(renderer, centreX - x, centreY - y, centreX, centreY);
        SDL_RenderDrawLine(renderer, centreX - x, centreY + y, centreX, centreY);
        SDL_RenderDrawLine(renderer, centreX + y, centreY - x, centreX, centreY);
        SDL_RenderDrawLine(renderer, centreX + y, centreY + x, centreX, centreY);
        SDL_RenderDrawLine(renderer, centreX - y, centreY - x, centreX, centreY);
        SDL_RenderDrawLine(renderer, centreX - y, centreY + x, centreX, centreY);

        if (error <= 0)
        {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0)
        {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
}

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("2D RTX", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderDrawCircle(renderer, 320,240,50);
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);

    return 0;
}