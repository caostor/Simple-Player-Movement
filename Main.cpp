#include <iostream>
#include <SDL.h>
#include "Entity.h"

int main(int argc, char* args[])
{
    SDL_Init(SDL_INIT_VIDEO);

    int SCREEN_WIDTH = 640;
    int SCREEN_HEIGHT = 480;

    int displayIndex = 0;
    SDL_Rect displayBounds;
    SDL_GetDisplayBounds(displayIndex, &displayBounds);
    SCREEN_HEIGHT = displayBounds.h;
    SCREEN_WIDTH = displayBounds.w;

    SDL_Window* window = SDL_CreateWindow("Player Movement", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    bool IsOpen = false;

    Uint32 lastTime = SDL_GetTicks();
    float deltaTime;

    Entity player(renderer);
    float playerSpeed = 5.f;
    float playerMaxSpeed = 5.f;

    while (!IsOpen)
    {
        SDL_Event event;
        Uint32 currentTime = SDL_GetTicks();
        deltaTime = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                IsOpen = true;
                break;
            case SDL_KEYDOWN:

                break;
            }
        }

        const Uint8* state = SDL_GetKeyboardState(NULL);
        SDL_Point move = { 0, 0 };

        if (state[SDL_SCANCODE_A])
        {
            move.x -= (100 * playerSpeed) * deltaTime;
        }
        if (state[SDL_SCANCODE_D])
        {
            move.x += (100 * playerSpeed) * deltaTime;
        }
        if (state[SDL_SCANCODE_W])
        {
            move.y -= (100 * playerSpeed) * deltaTime;
        }
        if (state[SDL_SCANCODE_S])
        {
            move.y += (100 * playerSpeed) * deltaTime;
        }

        if (playerMaxSpeed < move.y)
            move.y = playerMaxSpeed;
        else if (-playerMaxSpeed > move.y)
            move.y = -playerMaxSpeed;
        if (playerMaxSpeed < move.x)
            move.x = playerMaxSpeed;
        else if (-playerMaxSpeed > move.x)
            move.x = -playerMaxSpeed;

        player.Move(move);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        player.Update();
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}