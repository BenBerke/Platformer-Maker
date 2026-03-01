//
// Created by berke on 2/15/2026.
//

#ifndef PLATFORMER_MAKER_CONFIG_H
#define PLATFORMER_MAKER_CONFIG_H

constexpr int WINDOW_WIDTH = 960;
constexpr int WINDOW_HEIGHT = 960;

constexpr int SQUARE_SIZE = 200;

constexpr int WORLD_WIDTH = WINDOW_WIDTH / SQUARE_SIZE;
constexpr int WORLD_HEIGHT = WINDOW_HEIGHT / SQUARE_SIZE;

constexpr int TARGET_FPS = 60;
constexpr double TARGET_FRAME_MS = 1000.0 / TARGET_FPS;
#endif //PLATFORMER_MAKER_CONFIG_H