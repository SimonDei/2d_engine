#ifndef _GRID_HPP_
#define _GRID_HPP_

#include <vector>

#include "Rectangle.hpp"


namespace sde {
	class Grid {
		private:
			std::vector<Rectangle<unsigned int>> m_rects{ };


		public:
			Grid() = default;
			Grid(int width, int height, int tile_size);
			~Grid();
	};
}

#endif