#include "TextureSheet.h"


namespace sde {
	TextureSheet::TextureSheet(const std::string& path) {
		if ((m_texture_sheet = al_load_bitmap(path.c_str())) != nullptr) {
			m_width = sde_cast(float, al_get_bitmap_width(m_texture_sheet));
			m_height = sde_cast(float, al_get_bitmap_height(m_texture_sheet));
		}
	}

	TextureSheet::TextureSheet(ALLEGRO_BITMAP* al_bitmap) {
		m_texture_sheet = al_bitmap;
		m_width = sde_cast(float, al_get_bitmap_width(m_texture_sheet));
		m_height = sde_cast(float, al_get_bitmap_height(m_texture_sheet));
	}

	TextureSheet::TextureSheet(const std::string& path, float width, float height) {
		if ((m_texture_sheet = al_load_bitmap(path.c_str())) != nullptr) {
			m_width = sde_cast(float, al_get_bitmap_width(m_texture_sheet));
			m_height = sde_cast(float, al_get_bitmap_height(m_texture_sheet));
		}
		m_tile_width = width;
		m_tile_height = height;
	}

	TextureSheet::TextureSheet(ALLEGRO_BITMAP* al_bitmap, float width, float height) {
		m_texture_sheet = al_bitmap;
		m_width = sde_cast(float, al_get_bitmap_width(m_texture_sheet));
		m_height = sde_cast(float, al_get_bitmap_height(m_texture_sheet));
		m_tile_width = width;
		m_tile_height = height;
	}

	void TextureSheet::load_texture(const std::string& path) {
		if ((m_texture_sheet = al_load_bitmap(path.c_str())) != nullptr) {
			m_width = sde_cast(float, al_get_bitmap_width(m_texture_sheet));
			m_height = sde_cast(float, al_get_bitmap_height(m_texture_sheet));
		}
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

	const ALLEGRO_BITMAP& TextureSheet::get_texture_rect(float x, float y) {
		for (auto& sub_bitmap : m_sub_bitmaps) {
			
		}
	}

	float TextureSheet::get_width() const {
		return m_width;
	}

	float TextureSheet::get_height() const {
		return m_height;
	}

	ALLEGRO_BITMAP* TextureSheet::get_texture() const {
		return m_texture_sheet;
	}

	void TextureSheet::dispose() {
		if (m_texture_sheet != nullptr && !m_disposed) {
			al_destroy_bitmap(m_texture_sheet);
			m_texture_sheet = nullptr;
			m_disposed = true;
		}
	}

	TextureSheet::~TextureSheet() {
	}
}