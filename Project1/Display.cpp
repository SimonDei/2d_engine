#include "Display.h"


namespace sde {
	void Display::create_display(unsigned int width, unsigned int height) {
		m_width = width;
		m_height = height;
		m_display = al_create_display(sde_cast(int, m_width), sde_cast(int, m_height));
	}

	void Display::set_flags(const DisplayFlags& flags) {
		al_set_new_display_flags(sde_cast(int, flags));
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