#ifndef _TEXTUREGRID_HPP_
#define _TEXTUREGRID_HPP_

#include <vector>

#include "Texture.hpp"
#include "Rectangle.hpp"
#include "Drawable.hpp"
#include "Transformable.hpp"


namespace sde {
	class TextureGrid : public Drawable, public Transformable {
		private:
			std::vector<std::pair<Rectangle<unsigned int>, std::shared_ptr<Texture>>> m_rects{ };


		public:
			TextureGrid() = default;
			TextureGrid(int width, int height, int tile_size);
			~TextureGrid() = default;

			void set_rect_texture(int x, int y, const Texture& texture);

			void set_fill_texture(const Texture& texture);

			void draw() const override;
			void draw(float x, float y) const override;
	};
}

#endif