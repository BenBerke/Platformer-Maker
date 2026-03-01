#include <bits/stdc++.h>
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_render.h>
using namespace std;

extern "C" SDL_Texture* create_texture(const string &fileName, SDL_Renderer *renderer) {
    uint32_t pixels[16 * 16];
    int idx = 0;
    ifstream f(fileName);

    if (!f.is_open()) {
        cerr << "Error opening the file!" << fileName << endl;
        return nullptr;
    }
    string s;
    while (getline(f, s)) {
        auto p = static_cast<uint32_t>(std::stoul(s, nullptr, 0));
        const SDL_PixelFormatDetails *fmt = SDL_GetPixelFormatDetails(SDL_PIXELFORMAT_RGBA8888);
        uint8_t r = p  >> 24 & 0xff;
        uint8_t g = p >> 16 & 0xff;
        uint8_t b = p >> 8 & 0xff;
        uint8_t a = p & 0xff;

        uint32_t t = SDL_MapRGBA(fmt, nullptr, r, g, b, a);
        if (idx < 16 * 16) pixels[idx++] = t;
    }

    SDL_Texture* tex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 16, 16);
    SDL_SetTextureScaleMode(tex, SDL_SCALEMODE_NEAREST);
    SDL_UpdateTexture(tex, nullptr, pixels, 16 * sizeof(uint32_t));
    f.close();
    return tex;
}