#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL.h>

#include <iostream>
#include <span>


int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
	if(SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cerr << "SDL failed to initialize\n";
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow("pgrts", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
	SDL_Surface* surface = SDL_GetWindowSurface(window);

	bool running = true;

	while(running) {
		SDL_Event e;
		while(SDL_PollEvent(&e)) {
			if(e.type == SDL_QUIT) running = false;
		}

		auto pixels = std::span{
			reinterpret_cast<uint32_t*>(surface->pixels),
			static_cast<size_t>(surface->h * surface->w)
		};

		for(uint32_t& pixel : pixels) {
			pixel = SDL_MapRGBA(surface->format, 255, 0, 0, 4);
		}

		SDL_UpdateWindowSurface(window);
		SDL_Delay(16);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
