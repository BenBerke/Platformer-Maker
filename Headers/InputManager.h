#ifndef PLATFORMER_MAKER_INPUTMANAGER_H
#define PLATFORMER_MAKER_INPUTMANAGER_H

#include <SDL3/SDL.h>

#include "Vector.h"

class InputManager {
    inline static bool prevKeyboardState[SDL_SCANCODE_COUNT]{};
    inline static const bool* keyboardState = nullptr;
    inline static float mouseX;
    inline static float mouseY;
    inline static Vector2 mousePos;
public:
    static void BeginFrame();
    static bool GetKey(SDL_Scancode key) { return keyboardState[key]; }
    static bool GetKeyDown(SDL_Scancode key) { return keyboardState[key] && !prevKeyboardState[key]; }
    static bool GetKeyUp(SDL_Scancode key) { return !keyboardState[key] && prevKeyboardState[key]; }

    static Vector2 MousePos() { return mousePos; }
};

#endif
