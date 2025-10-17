#pragma once

#include "tiles/tile/tile.hpp"
#include <array>
#include <cstddef>
#include <vector>

namespace game {
class Tilepool {
public:
	explicit Tilepool(size_t radius_in_tiles);
	~Tilepool();

	Tilepool(Tilepool&&) = delete;
	Tilepool(const Tilepool&) = delete;
	Tilepool& operator=(Tilepool&&) = delete;
	Tilepool& operator=(const Tilepool&) = delete;

	const game::Tile& operator[] (size_t idx);
	std::array<size_t, 6> get_neighbours(size_t idx);
	void set(size_t idx, const game::Tile& t);
	size_t size();

	void delete_gendata();
	void set_gendata(size_t idx, const game::Tile_gendata& tg);
	const game::Tile_gendata& get_gendata(size_t idx);

private:
	size_t m_w;
	size_t m_h;
	std::vector<game::Tile> m_tiles;
	bool m_gendata_cleared = false;
	std::vector<game::Tile_gendata> m_tiles_gendata;
};
}

