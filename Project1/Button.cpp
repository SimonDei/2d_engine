#include "Button.h"


namespace sde {
	Button::Button(const Texture& button_up, const Texture& button_down) {
		m_button_up = sde_ref_to_ptr(Texture, button_up);
		m_button_down = sde_ref_to_ptr(Texture, button_down);
	}

	Button::Button(const Texture& button_up, const Texture& button_down, float x, float y, float width, float height) {
		m_button_up = sde_ref_to_ptr(Texture, button_up);
		m_button_down = sde_ref_to_ptr(Texture, button_down);
		m_x = x;
		m_y = y;
		m_width = width;
		m_height = height;
	}
	
	void Button::set_position(float x, float y) {
		m_x = x;
		m_y = y;
	}

	void Button::set_size(float width, float height) {
		m_width = width;
		m_height = height;
	}

	void Button::draw() const {
		
	}

	void Button::draw(float x, float y) const {

	}

	Button::~Button() {
	}
}