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

			void load_font(const std::string& path, unsigned int size);

			ALLEGRO_FONT* get_font() const;

			void dispose() override;
	};

	struct FontStruct {
		std::string m_path{ };
		Font m_font{ };
		unsigned int m_size{ 12 };
		bool m_loaded{ false };

		void load_font() {
			m_font.load_font(m_path, m_size);
		}

		FontStruct() = default;
		explicit FontStruct(const std::string& path) {
			m_path = path;
		}
		FontStruct(const std::string& path, unsigned int size) {
			m_path = path;
			m_size = size;
		}
		~FontStruct() {
			m_font.dispose();
		}
	};
}

#endif