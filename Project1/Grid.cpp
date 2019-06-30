#include "Grid.hpp"


namespace sde {
	Grid::Grid(int width, int height, int tile_size) {
		for (int i = 0; i < width * height; i++) {
			m_rects.push_back(Rectangle<unsigned int>((i % width) * tile_size, (i / width) * tile_size, tile_size, tile_size));
		}
	}

	Grid::~Grid() {
	}
}