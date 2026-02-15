//
// Created by berke on 2/15/2026.
//

#include "../Headers/Renderer.h"

void Renderer::CreateWindow() {
    SDL_Window* window;
    SDL_Renderer* _renderer;

    SDL_CreateWindowAndRenderer("My game", WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &_renderer);
    this->renderer = _renderer;
}

void Renderer::BeginFrame() const {
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->renderer);
}

void Renderer::EndFrame() const {
    SDL_RenderPresent(this->renderer);
}

void Renderer::DrawSquare(int x, int y, int r, int g, int b) const {
    SDL_FRect square = { static_cast<float>(x), static_cast<float>(y), SQUARE_SIZE, SQUARE_SIZE };
    SDL_SetRenderDrawColor(this->renderer, r, g, b, 255);
    SDL_RenderFillRect(this->renderer, &square);
}
void Renderer::DrawTexture(SDL_Texture* texture, int x, int y) const {
    SDL_FRect dst = { 50, 50, 16.0f * 24.0f, 16.0f * 24.0f };
    SDL_RenderTexture(renderer, texture, nullptr, &dst);
}