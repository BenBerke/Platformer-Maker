#include <iostream>
#include <cstring>

#include "../Headers/InputManager.h"

void InputManager::BeginFrame() {
     if (!keyboardState) keyboardState = SDL_GetKeyboardState(nullptr);
     std::memcpy(prevKeyboardState, keyboardState, SDL_SCANCODE_COUNT * sizeof(bool));
     SDL_PumpEvents();
     SDL_GetMouseState(&mouseX, &mouseY);
     mousePos = Vector2(mouseX, mouseY);
}
