#include "Font.hpp"


namespace sde {
	void Font::load_font(const std::string& name, const std::string& path, int size) {
		if ((m_font = al_load_ttf_font(path.c_str(), size, 0)) == nullptr) {
			throw NullException("Font at " + path + " does not exist.");
		}
	}

	const ALLEGRO_FONT& Font::get_font() {
		return *m_font;
	}

	void Font::dispose() {
		if (m_font != nullptr && !m_disposed) {
			al_destroy_font(m_font);
			m_font = nullptr;
			m_disposed = true;
		}
	}

	Font::~Font() {
	}
}