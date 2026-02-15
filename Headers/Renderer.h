//
// Created by berke on 2/15/2026.
//

#ifndef PLATFORMER_MAKER_RENDERER_H
#define PLATFORMER_MAKER_RENDERER_H

#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_rect.h>

#include "config.h"


class Renderer {

    public:
    SDL_Renderer* renderer = nullptr;
    void CreateWindow();
    void BeginFrame() const;
    void EndFrame() const;
    void DrawSquare(int x, int y, int r, int g, int b) const;
    void DrawTexture(SDL_Texture* texture, int x, int y) const;
};


#endif //PLATFORMER_MAKER_RENDERER_H