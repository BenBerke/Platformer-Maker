#include <iostream>
#include <SDL3/SDL.h>

#include "../Headers/Player.h"
#include "../Headers/Renderer.h"

extern "C" SDL_Texture* create_texture(const std::string& fileName, SDL_Renderer* renderer);

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

    bool isPlaying = true;
    SDL_Event event;
    while (isPlaying) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                isPlaying = false;
            }
            else if (event.type == SDL_EVENT_KEY_DOWN) {
                if (event.key.key == SDLK_SPACE) {
                }
            }
        }

        render.BeginFrame();
        // for (int i = 0; i < WORLD_HEIGHT; i++) {
        //     for (int j = 0; j < WORLD_WIDTH; j++) {
        //         switch (tiles[i][j]) {
        //             case 0: render.DrawSquare(j * SQUARE_SIZE, i * SQUARE_SIZE, 255, 255, 255); break;
        //             case 1: render.DrawSquare(j * SQUARE_SIZE, i * SQUARE_SIZE, 0, 255, 255); break;
        //             case 2: render.DrawSquare(j * SQUARE_SIZE, i * SQUARE_SIZE, 255, 0, 255); break;
        //             case 3: render.DrawSquare(j * SQUARE_SIZE, i * SQUARE_SIZE, 255, 255, 0); break;
        //             default: break;
        //         }
        //     }
        // }
        render.DrawTexture(texture, 50, 50);
        render.EndFrame();
    }

    return 0;
}