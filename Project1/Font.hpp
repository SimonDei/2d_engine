#ifndef _FONT_HPP_
#define _FONT_HPP_

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include <string>
#include <unordered_map>

#include "NullException.hpp"
#include "Disposable.hpp"


namespace sde {
	class Font : public Disposable {
		private:
			ALLEGRO_FONT* m_font = nullptr;


		public:
			Font() = default;
			~Font();

			void load_font(const std::string& name, const std::string& path, int size);

			const ALLEGRO_FONT& get_font();

			void dispose() override;
	};
}

#endif