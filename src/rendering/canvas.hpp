#pragma once

#include <cstddef>
#include <string>
#include "color.hpp"

class Canvas {
public:
	virtual ~Canvas() = default;

	virtual void begin_frame() = 0;
	virtual void end_frame() = 0;
	virtual bool is_open() = 0;
	virtual void draw_hex(size_t x, size_t y, size_t radius, size_t border_size, color tilecol, color borcol) = 0;
	virtual void set_background_color(color bg) = 0;
	virtual std::pair<size_t, size_t> get_screen_size() = 0;
};
