#include "Textbox.hpp"


namespace sde {
	Textbox::Textbox(const Texture& texture) {
		m_texture = std::make_shared<Texture>(texture);
	}

	Textbox::Textbox(const Texture& texture, const Font& font) {
		m_texture = std::make_shared<Texture>(texture);
		m_font = std::make_shared<Font>(font);
	}

	void Textbox::set_text_color(unsigned char red, unsigned char green, unsigned char blue) {
		m_text_color = al_map_rgb(red, green, blue);
	}

	void Textbox::set_max_size(unsigned char max_size) {
		m_max_char = max_size;
	}

	bool Textbox::is_focused() {
		al_get_mouse_state(&m_mouse_state);
		if (math::collision_rect_vec(m_x, m_y, m_width, m_height, static_cast<float>(m_mouse_state.x), static_cast<float>(m_mouse_state.y))) {
			return true;
		}
		return false;
	}

	bool Textbox::is_focused_and_handle(const Keycode& new_char) {
		al_get_mouse_state(&m_mouse_state);
		if (math::collision_rect_vec(m_x, m_y, m_width, m_height, static_cast<float>(m_mouse_state.x), static_cast<float>(m_mouse_state.y))) {
			if (m_text.size() < m_max_char) {
				m_text += static_cast<char>(static_cast<char>(new_char) + 96);
			}
			return true;
		}
		return false;
	}

	void Textbox::draw() const {
		al_draw_scaled_bitmap(m_texture->get_texture(), 0.0f, 0.0f, m_texture->get_width(), m_texture->get_height(), m_x, m_y, m_width, m_height, 0);
		al_draw_text(m_font->get_font(), m_text_color, m_x + m_width / 33.0f, m_y + m_height / 3.0f, 0, m_text.c_str());
	}

	void Textbox::draw(float x, float y) const {
		al_draw_scaled_bitmap(m_texture->get_texture(), 0.0f, 0.0f, m_texture->get_width(), m_texture->get_height(), x, y, m_width, m_height, 0);
		al_draw_text(m_font->get_font(), m_text_color, x + m_width / 33.0f, y + m_height / 3.0f, 0, m_text.c_str());
	}

	Textbox::~Textbox() {
	}
}