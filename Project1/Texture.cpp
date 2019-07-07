#include "Texture.hpp"


namespace sde {
	Texture::Texture(const std::string& path) {
		if ((m_bitmap = al_load_bitmap(path.c_str())) != nullptr) {
			m_width = static_cast<float>(al_get_bitmap_width(m_bitmap));
			m_height = static_cast<float>(al_get_bitmap_height(m_bitmap));
		} else {
			throw SdeException{ "Texture at " + path + " does not exist." };
		}
	}

	Texture::Texture(ALLEGRO_BITMAP* al_bitmap) {
		m_bitmap = al_bitmap;
		m_width = static_cast<float>(al_get_bitmap_width(m_bitmap));
		m_height = static_cast<float>(al_get_bitmap_height(m_bitmap));
	}

	Texture::Texture(ALLEGRO_BITMAP* al_bitmap, float x, float y, float width, float height) {
		m_bitmap = al_create_sub_bitmap(al_bitmap, x, y, width, height);
		m_width = width;
		m_height = height;
	}

	void Texture::load_texture(const std::string& path) {
		if ((m_bitmap = al_load_bitmap(path.c_str())) != nullptr) {
			m_width = static_cast<float>(al_get_bitmap_width(m_bitmap));
			m_height = static_cast<float>(al_get_bitmap_height(m_bitmap));
		} else {
			throw SdeException{ "Texture at " + path + " does not exist." };
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

	unsigned int Texture::get_gl_texture() const {
		return al_get_opengl_texture(m_bitmap);
	}

	void Texture::dispose() {
		if (!m_disposed && m_bitmap != nullptr) {
			al_destroy_bitmap(m_bitmap);
			m_bitmap = nullptr;
			m_disposed = true;
		}
	}

	Texture::~Texture() {
	}
}