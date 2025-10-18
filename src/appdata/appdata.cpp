#include "appdata.hpp"
#include <memory>

Appdata Appdata::s_instance;

void Appdata::init(std::string title, size_t w, size_t h) {
	s_instance.m_canvas = std::make_unique<Canvas_SDL>(title, w, h);
}
