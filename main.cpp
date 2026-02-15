#define SDL_MAIN_HANDLED 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>

int main() {
    SDL_SetMainReady();

    if (!SDL_Init(SDL_INIT_VIDEO)) { std::cerr << "SDL_Init failed: " << SDL_GetError() << "\n"; return 1; }

    SDL_Window* window = SDL_CreateWindow("SDL3", 800, 600, 0);
    if (!window) {
        std::cerr << "SDL_CreateWindow failed: " << SDL_GetError() << "\n";
        SDL_Quit();
        return 1;
    }

    bool running = true;
    while (running) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) running = false;
        }
        SDL_Delay(16);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
