#include "TextureSheet.hpp"


namespace sde {
	TextureSheet::TextureSheet(const std::string& path, unsigned int tile_width, unsigned int tile_height) {
		if ((m_bitmap = al_load_bitmap(path.c_str())) != nullptr) {
			m_width = static_cast<float>(al_get_bitmap_width(m_bitmap));
			m_height = static_cast<float>(al_get_bitmap_height(m_bitmap));
		} else {
			throw SdeException{ "Texture at " + path + " does not exist." };
		}
		m_tile_width = tile_width;
		m_tile_height = tile_height;
		load();
		m_auto_disposed = true;
	}

	void TextureSheet::load() {
		m_sub_rects.clear();
		for (unsigned int y = 0; y < m_height; y += m_tile_height) {
			for (unsigned int x = 0; x < m_width; x += m_tile_height) {
				m_sub_rects.insert(std::make_pair(x / m_tile_width + (y * m_height) / m_tile_height, Rectangle<float>{ static_cast<float>(x), static_cast<float>(y), static_cast<float>(m_tile_width), static_cast<float>(m_tile_height) }));			}
		}
	}

	void TextureSheet::set_tile_width(float width) {
		m_tile_width = width;
		load();
	}

	void TextureSheet::set_tile_height(float height) {
		m_tile_height = height;
		load();
	}

	void TextureSheet::set_tile_size(float width, float height) {
		m_tile_width = width;
		m_tile_height = height;
		load();
	}

	float TextureSheet::get_tile_width() const {
		return m_tile_width;
	}

	float TextureSheet::get_tile_height() const {
		return m_tile_height;
	}

	void TextureSheet::draw_texture_rect(unsigned int index, float x, float y) {
		Rectangle<float>& index_rect = m_sub_rects.at(index);
		al_draw_bitmap_region(m_bitmap, index_rect.get_x(), index_rect.get_y(), index_rect.get_width(), index_rect.get_height(), x, y, 0);
	}

	const Rectangle<float>& TextureSheet::get_texture_rect(unsigned int index) {
		return m_sub_rects.at(index);
	}
	
	void TextureSheet::dispose() {
		if (m_bitmap != nullptr && !m_disposed) {
			al_destroy_bitmap(m_bitmap);
			m_bitmap = nullptr;
			m_disposed = true;
		}
	}

	TextureSheet::~TextureSheet() {
	}
}