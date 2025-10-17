#include "tilepool.hpp"
#include <cmath>
#include <iostream>

game::Tilepool::Tilepool(size_t radius_in_tiles) :
	m_w(std::ceil(radius_in_tiles * 2 * std::numbers::pi)),
    m_h(2 * radius_in_tiles),
	m_tiles(m_w *m_h),
	m_tiles_gendata(m_w * m_h)
{

}

game::Tilepool::~Tilepool() {

}

const game::Tile& game::Tilepool::operator[] (size_t idx) {
	return m_tiles[idx];
}

std::array<size_t, 6> game::Tilepool::get_neighbours(size_t idx) {
	
}

void game::Tilepool::set(size_t idx, const game::Tile& t) {
	m_tiles[idx] = t;
}

size_t game::Tilepool::size() {
	return m_tiles.size();
}

void game::Tilepool::delete_gendata() {
	m_tiles_gendata.clear();
	m_gendata_cleared = true;
}

void game::Tilepool::set_gendata(size_t idx, const game::Tile_gendata& tg) {
	if(m_gendata_cleared) { std::cout << "WARNING accessing gendata after it was cleared. Ignoring..."; return; }
	m_tiles_gendata[idx] = tg;
}

const game::Tile_gendata& game::Tilepool::get_gendata(size_t idx) {
	if(m_gendata_cleared) { std::cout << "WARNING accessing gendata after it was cleared. Ignoring..."; return game::Tile_gendata(); }
	return m_tiles_gendata[idx];
}

