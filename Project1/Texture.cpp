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

	Texture::Texture(const std::initializer_list<TextureFlags>& flag_list) {
		for (auto& flag : flag_list) {
			m_flags.push_back(flag);
		}
	}

	Texture::Texture(ALLEGRO_BITMAP* al_bitmap, float x, float y, float width, float height) {
		m_bitmap = al_create_sub_bitmap(al_bitmap, x, y, width, height);
		m_width = width;
		m_height = height;
	}

	void Texture::load_texture(const std::string& path) {
		if (!m_flags.empty()) {
			int flag = 0;
			for (unsigned int i = 0; i < m_flags.size(); i++) {
				flag |= static_cast<int>(m_flags.at(i));
			}
			al_set_new_bitmap_flags(flag);
		}
		if ((m_bitmap = al_load_bitmap(path.c_str())) != nullptr) {
			m_width = static_cast<float>(al_get_bitmap_width(m_bitmap));
			m_height = static_cast<float>(al_get_bitmap_height(m_bitmap));
		} else {
			throw SdeException{ "Texture at " + path + " does not exist." };
		}
	}

	void Texture::lock() {
		m_region_data = al_lock_bitmap(m_bitmap, ALLEGRO_PIXEL_FORMAT_RGBA_8888, ALLEGRO_LOCK_READONLY);
	}

	void Texture::lock(int x, int y, int width, int height) {
		m_region_data = al_lock_bitmap_region(m_bitmap, x, y, width, height, ALLEGRO_PIXEL_FORMAT_RGBA_8888, ALLEGRO_LOCK_READONLY);
	}

	int Texture::get_pixel_color(int x, int y) {
		return *((int*)m_region_data->data + x + y * (m_region_data->pitch / m_region_data->pixel_size));
	}

	void Texture::unlock() {
		al_unlock_bitmap(m_bitmap);
		m_region_data = nullptr;
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