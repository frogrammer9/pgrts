#pragma once

#include "tiles/tilepool/tilepool.hpp"
#include <random>

namespace game {
	void generate_world(game::Tilepool& tp, unsigned int seed);
}

namespace _worldgen_internal {
	void gen_continents_data(game::Tilepool& tp, std::mt19937& rng);
}
