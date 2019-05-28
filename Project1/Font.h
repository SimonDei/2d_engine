#pragma once

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include <string>
#include <unordered_map>


namespace sde {
	class Font {
		private:
			std::unordered_map<std::string, ALLEGRO_FONT*> m_fonts;

		public:
			Font() = default;
			~Font();

			void load_font(const std::string& name, const std::string& path, int size);

			const ALLEGRO_FONT& get_font(const std::string& name);
	};
}
