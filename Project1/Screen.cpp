#include "Screen.hpp"


namespace sde {
	Screen::Screen(const Display& display) {
		m_display = display.get_display();
		al_set_new_bitmap_flags(ALLEGRO_VIDEO_BITMAP);
		m_bitmap = al_create_bitmap(static_cast<int>(display.get_width()), static_cast<int>(display.get_height()));
		al_set_new_bitmap_flags(0);
	}
	
	void Screen::set_display(const Display& display) {
		m_display = display.get_display();
		al_set_new_bitmap_flags(ALLEGRO_VIDEO_BITMAP);
		m_bitmap = al_create_bitmap(static_cast<int>(display.get_width()), static_cast<int>(display.get_height()));
		al_set_new_bitmap_flags(0);
	}

	void Screen::clear_screen(unsigned char red, unsigned char green, unsigned char blue) {
		al_set_target_bitmap(m_bitmap);
		al_clear_to_color(al_map_rgb(red, green, blue));
		al_set_target_bitmap(al_get_backbuffer(m_display));
	}

	void Screen::clear_screen(const Color3<unsigned char>& color) {
		al_set_target_bitmap(m_bitmap);
		al_clear_to_color(color.get_al_color());
		al_set_target_bitmap(al_get_backbuffer(m_display));
	}

	void Screen::clear_screen(const Color4<unsigned char>& color) {
		al_set_target_bitmap(m_bitmap);
		al_clear_to_color(color.get_al_color());
		al_set_target_bitmap(al_get_backbuffer(m_display));
	}

	void Screen::draw_to_screen(const Texture& texture) {
		al_set_target_bitmap(m_bitmap);
		al_draw_bitmap(texture.get_texture(), 0.0f, 0.0f, 0);
		al_set_target_bitmap(al_get_backbuffer(m_display));
	}

	void Screen::draw_to_screen(const Texture& texture, float x, float y) {
		al_set_target_bitmap(m_bitmap);
		al_draw_bitmap(texture.get_texture(), x, y, 0);
		al_set_target_bitmap(al_get_backbuffer(m_display));
	}

	void Screen::draw_to_screen(const Texture& texture, float x, float y, float width, float height) {
		al_set_target_bitmap(m_bitmap);
		al_draw_scaled_bitmap(texture.get_texture(), 0.0f, 0.0f, texture.get_width(), texture.get_height(), x, y, width, height, 0);
		al_set_target_bitmap(al_get_backbuffer(m_display));
	}

	void Screen::draw_to_screen(const Drawable& drawable) {
		al_set_target_bitmap(m_bitmap);
		drawable.draw();
		al_set_target_bitmap(al_get_backbuffer(m_display));
	}

	void Screen::draw_to_screen(const Drawable& drawable, float x, float y) {
		al_set_target_bitmap(m_bitmap);
		drawable.draw(x, y);
		al_set_target_bitmap(al_get_backbuffer(m_display));
	}

	void Screen::draw() const {
		al_draw_bitmap(m_bitmap, 0.0f, 0.0f, 0);
	}

	void Screen::dispose() {
		if (m_bitmap != nullptr && !m_disposed) {
			al_destroy_bitmap(m_bitmap);
			m_bitmap = nullptr;
			m_display = nullptr;
			m_disposed = true;
		}
	}

	Screen::~Screen() {
	}
}