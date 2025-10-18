#include "world.hpp"
#include "appdata/appdata.hpp"

static size_t calc_array_size(size_t radius_in_tiles) {
	size_t side_len = radius_in_tiles * 2 + 1;
	size_t empty_cells = radius_in_tiles * (radius_in_tiles - 1) / 2;
	return side_len * side_len - 2 * empty_cells;
}

game::World::World(size_t radius_in_tiles) :
	m_tiles(calc_array_size(radius_in_tiles)),
	m_tiles_gendata(calc_array_size(radius_in_tiles)),
	m_radius(radius_in_tiles)
{

}

game::World::~World() {

}

void game::World::render() {
	auto [w, h] = Appdata::get_canvas().get_screen_size();

}
