#include <iostream>
#include <SDL3/SDL.h>

#include "../Headers/Player.h"
#include "../Headers/Renderer.h"
#include "../Headers/InputManager.h"

extern "C" SDL_Texture* create_texture(const std::string& fileName, SDL_Renderer* renderer);

enum CurrentState {
    DRAWING,
    VIEWING,
};

CurrentState currentState = VIEWING;

int main () {
    if (!SDL_Init(SDL_INIT_VIDEO)) { SDL_Log("Error on init application: %s", SDL_GetError()); return -1; }

    int tiles[WORLD_HEIGHT][WORLD_WIDTH] = {
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {2, 2, 2, 2},
        {3, 3, 3, 3}
    };
    Renderer render;
    render.CreateWindow();

    SDL_Texture* texture = create_texture("src/textFile.txt", render.renderer);

    bool running = true;
    while (running) {
        uint64_t start = SDL_GetPerformanceCounter();
        InputManager::BeginFrame();

        if (InputManager::GetKeyDown(SDL_SCANCODE_ESCAPE)) running = false;
        
        render.BeginFrame();
        render.DrawTexture(texture, 50, 50);

        render.EndFrame();
        const uint64_t end = SDL_GetPerformanceCounter();
        const double elapsedSeconds = static_cast<double>(end - start) * 1000.0f / static_cast<double>(SDL_GetPerformanceFrequency());
        if (const double delay =TARGET_FRAME_MS - elapsedSeconds; delay > 0) SDL_Delay(static_cast<uint32_t>(delay));
    }

    return 0;
}