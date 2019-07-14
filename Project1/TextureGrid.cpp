#include "TextureGrid.hpp"


namespace sde {
	TextureGrid::TextureGrid(int width, int height, int tile_size) {
		for (int i = 0; i < width * height; i++) {
			m_rects.emplace_back(Rectangle<unsigned int>((i % width) * tile_size, (i / width) * tile_size, tile_size, tile_size), nullptr);
		}
	}

	void TextureGrid::set_rect_texture(int x, int y, const Texture& texture) {
		m_rects.at(m_rects.size() * y + x).second = std::make_shared<Texture>(texture);
	}

	void TextureGrid::set_fill_texture(const Texture& texture) {
		for (auto& m_rect : m_rects) {
			m_rect.second = std::make_shared<Texture>(texture);
		}
	}

	void TextureGrid::draw() const {
		for (const auto& m_rect : m_rects) {
			al_draw_bitmap(m_rect.second->get_texture(), m_x, m_y, 0);
		}
	}

	void TextureGrid::draw(float x, float y) const {
		for (const auto& m_rect : m_rects) {
			al_draw_bitmap(m_rect.second->get_texture(), x, y, 0);
		}
	}
}