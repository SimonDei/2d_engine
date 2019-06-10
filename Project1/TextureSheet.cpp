#include "TextureSheet.hpp"


namespace sde {
	TextureSheet::TextureSheet(const std::string& path) {
		if ((m_bitmap = al_load_bitmap(path.c_str())) != nullptr) {
			m_width = static_cast<float>(al_get_bitmap_width(m_bitmap));
			m_height = static_cast<float>(al_get_bitmap_height(m_bitmap));
		} else {
			throw NullException("Texture at " + path + " does not exist.");
		}
		m_auto_disposed = true;
	}

	TextureSheet::TextureSheet(ALLEGRO_BITMAP* al_bitmap) {
		m_bitmap = al_bitmap;
		m_width = static_cast<float>(al_get_bitmap_width(m_bitmap));
		m_height = static_cast<float>(al_get_bitmap_height(m_bitmap));
		m_auto_disposed = true;
	}

	void TextureSheet::set_tile_width(float width) {
		m_tile_width = width;
	}

	void TextureSheet::set_tile_height(float height) {
		m_tile_height = height;
	}

	void TextureSheet::set_tile_size(float width, float height) {
		m_tile_width = width;
		m_tile_height = height;
	}

	const Texture& TextureSheet::get_texture_rect(float x, float y, float width, float height) {
		for (auto& sub_bitmap : m_sub_bitmaps) {
			if (sub_bitmap.first == ("x_" + std::to_string(x) + "y_" + std::to_string(y) + "w_" + std::to_string(width) + "h_" + std::to_string(height))) {
				return sub_bitmap.second;
			}
		}
		m_sub_bitmaps.insert(std::make_pair("x_" + std::to_string(x) + "y_" + std::to_string(y) + "w_" + std::to_string(width) + "h_" + std::to_string(height), Texture(m_bitmap, x, y, width, height)));
		return m_sub_bitmaps.at("x_" + std::to_string(x) + "y_" + std::to_string(y) + "w_" + std::to_string(width) + "h_" + std::to_string(height));
	}

	ALLEGRO_BITMAP* TextureSheet::get_texture_sheet() const {
		return m_bitmap;
	}

	void TextureSheet::dispose() {
		for (auto& sub_texture : m_sub_bitmaps) {
			sub_texture.second.dispose();
		}
		if (m_bitmap != nullptr && !m_disposed) {
			al_destroy_bitmap(m_bitmap);
			m_bitmap = nullptr;
			m_disposed = true;
		}
	}

	TextureSheet::~TextureSheet() {
	}
}