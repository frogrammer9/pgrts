#pragma once

#include <memory>

#include "rendering/canvas_sdl.hpp"

class Appdata {
	explicit Appdata() = default;
public:
	~Appdata() = default;
	Appdata(Appdata&&) = delete;
	Appdata(const Appdata&) = delete;
	Appdata& operator=(Appdata&&) = delete;
	Appdata& operator=(const Appdata&) = delete;
	
	static void init(std::string title, size_t w, size_t h);
	static Canvas& get_canvas() { return *s_instance.m_canvas; }
private:
	static Appdata s_instance; 
	std::unique_ptr<Canvas> m_canvas;
};
