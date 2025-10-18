#include <iostream>

#include "rendering/canvas_sdl.hpp"
#include "appdata/appdata.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
	Appdata::init("pgrts", 640, 480);

	color bg(70, 90, 90);
	Appdata::get_canvas().set_background_color(bg);

	while(Appdata::get_canvas().is_open()) {
		Appdata::get_canvas().begin_frame();

		Appdata::get_canvas().draw_hex(200, 200, 20, 2, {255, 0, 0}, {0, 0, 255});

		Appdata::get_canvas().end_frame();
	}

	return 0;
}
