#include "color.hpp"
#include <SDL2/SDL_pixels.h>
#include <algorithm>

color::color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) : r(red), g(green), b(blue), a(alpha) {}

color::color(uint32_t hex) {
	r = (hex >> 24) & 0xff;
	g = (hex >> 16) & 0xff;
	b = (hex >> 8 ) & 0xff;
	a = (hex >> 0 ) & 0xff;
}

uint32_t color::get_RGBA() {
	uint32_t out = 0;
	out |= r;
	out <<= 8;
	out |= g;
	out <<= 8;
	out |= b;
	out <<= 8;
	out |= a;
	return out;
}

uint32_t color::get_ARGB() {
	uint32_t out = 0;
	out |= a;
	out <<= 8;
	out |= r;
	out <<= 8;
	out |= g;
	out <<= 8;
	out |= b;
	return out;
}

uint32_t color::get_SDL(const SDL_PixelFormat* format) {
	return SDL_MapRGBA(format, r, g, b, a);
}
