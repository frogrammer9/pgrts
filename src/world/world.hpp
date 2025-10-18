#pragma once

#include "tile/tile.hpp"
#include <array>
#include <cstddef>
#include <vector>

namespace game {
class World {
public:
	explicit World(size_t radius_in_tiles);
	~World();

	World(World&&) = delete;
	World(const World&) = delete;
	World& operator=(World&&) = delete;
	World& operator=(const World&) = delete;

	void render();

private:
	std::vector<game::Tile> m_tiles;
	bool m_gendata_cleared = false;
	std::vector<game::Tile_gendata> m_tiles_gendata;
	size_t m_radius;
};
}

