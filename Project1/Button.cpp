#include "Button.hpp"


namespace sde {
	Button::Button(const Texture& button_up, const Texture& button_down) {
		m_button_up = std::make_shared<Texture>(button_up);
		m_button_down = std::make_shared<Texture>(button_down);
	}

	Button::Button(const Texture& button_up, const Texture& button_down, float x, float y, float width, float height) {
		m_button_up = std::make_shared<Texture>(button_up);
		m_button_down = std::make_shared<Texture>(button_down);
		m_x = x;
		m_y = y;
		m_width = width;
		m_height = height;
	}
	
	void Button::set_handle_function(const std::function<void()>& function) {
		m_press_function = function;
	}

	bool Button::is_pressed() {
		al_get_mouse_state(&m_mouse_state);
		if (al_mouse_button_down(&m_mouse_state, 1) != al_mouse_button_down(&m_old_mouse_state, 1)) {
			m_state_change = true;
		}
		if (al_mouse_button_down(&m_mouse_state, 1)) {
			if (math::collision_rect_vec(m_x, m_y, m_width, m_height, static_cast<float>(m_mouse_state.x), static_cast<float>(m_mouse_state.y))) {
				m_pressed = true;
			}
		} else {
			m_pressed = false;
		}
		m_old_mouse_state = m_mouse_state;
		return m_pressed;
	}

	bool Button::is_pressed_and_handle() {
		al_get_mouse_state(&m_mouse_state);
		if (al_mouse_button_down(&m_mouse_state, 1) != al_mouse_button_down(&m_old_mouse_state, 1)) {
			m_state_change = true;
		}
		if (al_mouse_button_down(&m_mouse_state, 1)) {
			if (math::collision_rect_vec(m_x, m_y, m_width, m_height, static_cast<float>(m_mouse_state.x), static_cast<float>(m_mouse_state.y))) {
				if (m_state_change) {
					m_press_function();
					m_state_change = false;
				}
				m_pressed = true;
			}
		} else {
			m_pressed = false;
		}
		m_old_mouse_state = m_mouse_state;
		return m_pressed;
	}

	void Button::handle() {
		if (m_state_change && m_pressed) {
			m_press_function();
			m_state_change = false;
		}
	}

	void Button::draw() const {
		if (m_pressed) {
			al_draw_scaled_bitmap(m_button_down->get_texture(), 0.0f, 0.0f, m_button_down->get_width(), m_button_down->get_height(), m_x, m_y, m_width, m_height, 0);
		} else {
			al_draw_scaled_bitmap(m_button_up->get_texture(), 0.0f, 0.0f, m_button_up->get_width(), m_button_up->get_height(), m_x, m_y, m_width, m_height, 0);
		}
	}

	void Button::draw(float x, float y) const {
		if (m_pressed) {
			al_draw_scaled_bitmap(m_button_down->get_texture(), 0.0f, 0.0f, m_button_down->get_width(), m_button_down->get_height(), x, y, m_width, m_height, 0);
		} else {
			al_draw_scaled_bitmap(m_button_up->get_texture(), 0.0f, 0.0f, m_button_up->get_width(), m_button_up->get_height(), x, y, m_width, m_height, 0);
		}
	}

	Button::~Button() {
	}
}