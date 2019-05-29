#include "Texture.h"


namespace sde {
	Texture::Texture(const std::string& path) {
		if ((m_bitmap = al_load_bitmap(path.c_str())) != nullptr) {
			m_width = sde_cast(float, al_get_bitmap_width(m_bitmap));
			m_height = sde_cast(float, al_get_bitmap_height(m_bitmap));
		} else {
			throw NullException("Texture at " + path + " does not exist.");
		}
	}

	Texture::Texture(const Texture& texture) {
		m_bitmap = texture.get_texture();
		m_width = texture.get_width();
		m_height = texture.get_height();
	}

	Texture::Texture(ALLEGRO_BITMAP* al_bitmap) {
		m_bitmap = al_bitmap;
		m_width = sde_cast(float, al_get_bitmap_width(m_bitmap));
		m_height = sde_cast(float, al_get_bitmap_height(m_bitmap));
	}

	void Texture::load_texture(const std::string& path) {
		if ((m_bitmap = al_load_bitmap(path.c_str())) != nullptr) {
			m_width = sde_cast(float, al_get_bitmap_width(m_bitmap));
			m_height = sde_cast(float, al_get_bitmap_height(m_bitmap));
		} else {
			throw NullException("Texture at " + path + " does not exist.");
		}
	}

	float Texture::get_width() const {
		return m_width;
	}

	float Texture::get_height() const {
		return m_height;
	}

	ALLEGRO_BITMAP* Texture::get_texture() const {
		if (m_bitmap != nullptr) {
			return m_bitmap;
		}
		return nullptr;
	}

	void Texture::dispose() {
		if (m_bitmap != nullptr && !m_disposed) {
			al_destroy_bitmap(m_bitmap);
			m_bitmap = nullptr;
			m_disposed = true;
		}
	}

	Texture::~Texture() {
	}
}