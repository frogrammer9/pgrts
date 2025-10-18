#pragma once

#include <SDL2/SDL_pixels.h>
#include <cstdint>
#include <cstddef>

struct color {
	color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255);
	explicit color(uint32_t hex);

	uint32_t get_RGBA();
	uint32_t get_ARGB();

	uint32_t get_SDL(const SDL_PixelFormat* format);

	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
};
