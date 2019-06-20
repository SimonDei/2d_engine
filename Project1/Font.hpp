#ifndef _FONT_HPP_
#define _FONT_HPP_

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include <string>
#include <unordered_map>

#include "SdeException.hpp"
#include "Disposable.hpp"


namespace sde {
	class Font : public Disposable {
		private:
			ALLEGRO_FONT* m_font{ nullptr };


		public:
			Font() = default;
			Font(const std::string& path, unsigned int size);
			~Font();

			void load_font(const std::string& name, const std::string& path, unsigned int size);

			ALLEGRO_FONT* get_font() const;

			void dispose() override;
	};
}

#endif