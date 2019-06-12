#include "Display.hpp"


namespace sde {
	void Display::create_display(unsigned int width, unsigned int height) {
		m_width = width;
		m_height = height;
		m_display = al_create_display(static_cast<int>(m_width), static_cast<int>(m_height));
	}

	void Display::set_position(unsigned int x, unsigned int y) const {
		al_set_new_window_position(static_cast<int>(x), static_cast<int>(y));
	}

	void Display::set_title(const std::string& name) const {
		al_set_new_window_title(name.c_str());
	}

	void Display::set_flags(const DisplayFlags& flags) const {
		al_set_new_display_flags(static_cast<int>(flags));
	}

	float Display::get_width() const {
		return static_cast<float>(m_width);
	}

	float Display::get_height() const {
		return static_cast<float>(m_height);
	}

	ALLEGRO_DISPLAY* Display::get_display() const {
		return m_display;
	}

	void Display::dispose() {
		if (m_display != nullptr) {
			al_destroy_display(m_display);
			m_display = nullptr;
			m_disposed = true;
		}
	}

	Display::~Display() {
	}
}