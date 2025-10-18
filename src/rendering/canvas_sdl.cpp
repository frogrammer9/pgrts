#include "canvas_sdl.hpp"
#include <SDL2/SDL_render.h>
#include <iostream>

#include <SDL2/SDL.h>

Canvas_SDL::Canvas_SDL(std::string title, size_t w, size_t h) : m_bg(0, 0, 0) {
	if(SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cerr << "SDL failed to initialize\n";
		return;
	}

	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, 0);
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	m_open = true;
}

Canvas_SDL::~Canvas_SDL() {
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Canvas_SDL::begin_frame() {
	SDL_Event e;
	while(SDL_PollEvent(&e)) {
		if(e.type == SDL_QUIT) m_open = false;
	}

	SDL_SetRenderDrawColor(m_renderer, m_bg.r, m_bg.g, m_bg.b, m_bg.a);
	SDL_RenderClear(m_renderer);
}

void Canvas_SDL::end_frame() {

	SDL_RenderPresent(m_renderer);
}

bool Canvas_SDL::is_open() { return m_open; }

void Canvas_SDL::set_background_color(color bg) { m_bg = bg; }

std::pair<size_t, size_t> Canvas_SDL::get_screen_size() {
	int w, h;
	SDL_GetWindowSize(m_window, &w, &h);
	return {w, h};
}

void Canvas_SDL::draw_hex(size_t x, size_t y, size_t radius, size_t border_size, color tilecol, color borcol) {
	draw_raw_hex(x, y, radius, borcol);
	draw_raw_hex(x, y, radius - border_size, tilecol);
}

void Canvas_SDL::draw_raw_hex(size_t x, size_t y, size_t radius, color col) {
	SDL_Vertex verts[6];

	for(size_t i = 0; i < 6; ++i) {
		const double ang = 1.04719755 /*60deg*/ * i;
		const float cx = x + radius * sin(ang);
		const float cy = y + radius * cos(ang);
		verts[i] = {{cx, cy}, {col.r, col.g, col.b, col.a}, {0, 0}};
	}
	int indacies[] = {
		0, 1, 2,
		0, 2, 3,
		0, 3, 4,
		0, 4, 5
	};

	SDL_RenderGeometry(m_renderer, nullptr, verts, 6, indacies, 12);
}
