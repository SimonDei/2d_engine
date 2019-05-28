#include "Font.h"


namespace sde {
	void Font::load_font(const std::string& name, const std::string& path, int size) {
		ALLEGRO_FONT* font = al_load_ttf_font(path.c_str(), size, 0);
		m_fonts.insert(std::make_pair(name, std::move(font)));
	}

	const ALLEGRO_FONT& Font::get_font(const std::string& name) {
		return *m_fonts.at(name);
	}

	Font::~Font() {
	}
}
