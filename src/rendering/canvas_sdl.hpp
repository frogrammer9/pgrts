#pragma once

#include "canvas.hpp"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

class Canvas_SDL : public Canvas {
public:
	Canvas_SDL(std::string title, size_t w, size_t h);
	~Canvas_SDL() override;

	void begin_frame() override;
	void end_frame() override;
	bool is_open() override;
	void set_background_color(color bg) override;

	std::pair<size_t, size_t> get_screen_size() override;

	void draw_hex(size_t x, size_t y, size_t radius, size_t border_size, color tilecol, color borcol) override;
private:
	void draw_raw_hex(size_t x, size_t y, size_t radius, color col);

	SDL_Window* m_window = nullptr;
	SDL_Renderer* m_renderer = nullptr;
	bool m_open = false;
	color m_bg;
};
