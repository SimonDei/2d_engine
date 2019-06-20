#include "Textbox.hpp"


namespace sde {
	Textbox::Textbox(const Texture& texture) {
		m_texture = std::make_shared<Texture>(texture);
	}

	void Textbox::set_text_color(unsigned char red, unsigned char green, unsigned char blue) {
		m_text_color = al_map_rgb(red, green, blue);
	}

	bool Textbox::is_focused() {
		al_get_mouse_state(&m_mouse_state);
		if (al_mouse_button_down(&m_mouse_state, 1)) {
			if (math::collision_rect_vec(m_x, m_y, m_width, m_height, static_cast<float>(m_mouse_state.x), static_cast<float>(m_mouse_state.y))) {
				m_focused = true;
			}
		} else {
			m_focused = false;
		}
		return m_focused;
	}

	bool Textbox::is_focused_and_handle(const Keycode& new_char) {
		al_get_mouse_state(&m_mouse_state);
		if (al_mouse_button_down(&m_mouse_state, 1)) {
			if (math::collision_rect_vec(m_x, m_y, m_width, m_height, static_cast<float>(m_mouse_state.x), static_cast<float>(m_mouse_state.y))) {
				m_text += static_cast<char>(static_cast<char>(new_char) + 96);
				m_focused = true;
			}
		} else {
			m_focused = false;
		}
		return m_focused;
	}

	void Textbox::draw() const {
		al_draw_bitmap(m_texture->get_texture(), m_x, m_y, 0);
		al_draw_text(m_font->get_font(), m_text_color, m_x, m_y + al_get_font_line_height(m_font->get_font()) / 2.0f, 0, m_text.c_str());
	}

	void Textbox::draw(float x, float y) const {
		al_draw_bitmap(m_texture->get_texture(), x, y, 0);
		al_draw_text(m_font->get_font(), m_text_color, x, y + al_get_font_line_height(m_font->get_font()) / 2.0f, 0, m_text.c_str());

	}

	Textbox::~Textbox() {
	}
}