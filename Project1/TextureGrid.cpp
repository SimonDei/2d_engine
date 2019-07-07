#include "TextureGrid.hpp"


namespace sde {
	TextureGrid::TextureGrid(int width, int height, int tile_size) {
		for (int i = 0; i < width * height; i++) {
			m_rects.push_back(std::make_pair(Rectangle<unsigned int>((i % width) * tile_size, (i / width) * tile_size, tile_size, tile_size), nullptr));
		}
	}

	void TextureGrid::set_rect_texture(int x, int y, const Texture& texture) {
		m_rects.at(m_rects.size() * y + x).second = std::make_shared<Texture>(texture);
	}

	void TextureGrid::set_fill_texture(const Texture& texture) {
		for (auto it = m_rects.begin(); it != m_rects.end(); it++) {
			it->second = std::make_shared<Texture>(texture);
		}
	}

	void TextureGrid::draw() const {
		for (auto it = m_rects.begin(); it != m_rects.end(); it++) {
			al_draw_bitmap(it->second->get_texture(), m_x, m_y, 0);
		}
	}

	void TextureGrid::draw(float x, float y) const {
		for (auto it = m_rects.begin(); it != m_rects.end(); it++) {
			al_draw_bitmap(it->second->get_texture(), x, y, 0);
		}
	}

	TextureGrid::~TextureGrid() {
	}
}