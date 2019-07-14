#include "RenderTexture.hpp"


namespace sde {
	RenderTexture::RenderTexture(const Vector2<unsigned int>& size) {
		al_set_new_bitmap_flags(ALLEGRO_VIDEO_BITMAP);
		m_bitmap = al_create_bitmap(static_cast<int>(size.get_x()), static_cast<int>(size.get_y()));
		al_set_new_bitmap_flags(0);
	}
	
	RenderTexture::RenderTexture(unsigned int width, unsigned int height) {
		al_set_new_bitmap_flags(ALLEGRO_VIDEO_BITMAP);
		m_bitmap = al_create_bitmap(static_cast<int>(width), static_cast<int>(height));
		al_set_new_bitmap_flags(0);
	}

	void RenderTexture::create(unsigned int width, unsigned int height) {
		al_set_new_bitmap_flags(ALLEGRO_VIDEO_BITMAP);
		m_bitmap = al_create_bitmap(static_cast<int>(width), static_cast<int>(height));
		al_set_new_bitmap_flags(0);
	}

	void RenderTexture::clear_texture(unsigned char red, unsigned char green, unsigned char blue) {
		m_display = al_get_current_display();
		if (m_display != nullptr) {
			al_set_target_bitmap(m_bitmap);
			al_clear_to_color(al_map_rgb(red, green, blue));
			al_set_target_bitmap(al_get_backbuffer(m_display));
		}
		m_display = nullptr;
	}

	void RenderTexture::clear_texture(const Color3<unsigned char>& color) {
		m_display = al_get_current_display();
		if (m_display != nullptr) {
			al_set_target_bitmap(m_bitmap);
			al_clear_to_color(color.get_al_color());
			al_set_target_bitmap(al_get_backbuffer(m_display));
		}
		m_display = nullptr;
	}

	void RenderTexture::clear_texture(const Color4<unsigned char>& color) {
		m_display = al_get_current_display();
		if (m_display != nullptr) {
			al_set_target_bitmap(m_bitmap);
			al_clear_to_color(color.get_al_color());
			al_set_target_bitmap(al_get_backbuffer(m_display));
		}
		m_display = nullptr;
	}

	void RenderTexture::draw_to_texture(const Texture& texture) {
		m_display = al_get_current_display();
		if (m_display != nullptr) {
			al_set_target_bitmap(m_bitmap);
			al_draw_bitmap(texture.get_texture(), 0.0f, 0.0f, 0);
			al_set_target_bitmap(al_get_backbuffer(m_display));
		}
		m_display = nullptr;
	}

	void RenderTexture::draw_to_texture(const Texture& texture, float x, float y) {
		m_display = al_get_current_display();
		if (m_display != nullptr) {
			al_set_target_bitmap(m_bitmap);
			al_draw_bitmap(texture.get_texture(), x, y, 0);
			al_set_target_bitmap(al_get_backbuffer(m_display));
		}
		m_display = nullptr;
	}

	void RenderTexture::draw_to_texture(const Texture& texture, float x, float y, float width, float height) {
		m_display = al_get_current_display();
		if (m_display != nullptr) {
			al_set_target_bitmap(m_bitmap);
			al_draw_scaled_bitmap(texture.get_texture(), 0.0f, 0.0f, texture.get_width(), texture.get_height(), x, y, width, height, 0);
			al_set_target_bitmap(al_get_backbuffer(m_display));
		}
		m_display = nullptr;
	}

	void RenderTexture::draw_to_texture(const Drawable& drawable) {
		m_display = al_get_current_display();
		if (m_display != nullptr) {
			al_set_target_bitmap(m_bitmap);
			drawable.draw();
			al_set_target_bitmap(al_get_backbuffer(m_display));
		}
		m_display = nullptr;
	}

	void RenderTexture::draw_to_texture(const Drawable& drawable, float x, float y) {
		m_display = al_get_current_display();
		if (m_display != nullptr) {
			al_set_target_bitmap(m_bitmap);
			drawable.draw(x, y);
			al_set_target_bitmap(al_get_backbuffer(m_display));
		}
		m_display = nullptr;
	}

	void RenderTexture::draw() const {
		al_draw_bitmap(m_bitmap, 0.0f, 0.0f, 0);
	}

	void RenderTexture::draw(float x, float y) const {
		al_draw_bitmap(m_bitmap, x, y, 0);
	}

	void RenderTexture::dispose() {
		if (m_bitmap != nullptr && !m_disposed) {
			al_destroy_bitmap(m_bitmap);
			m_bitmap = nullptr;
			m_display = nullptr;
			m_disposed = true;
		}
	}
}