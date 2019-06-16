#ifndef _TEXTURESHEET_HPP_
#define _TEXTURESHEET_HPP_

#include <allegro5/allegro.h>

#include <string>
#include <unordered_map>

#include "Texture.hpp"
#include "NullException.hpp"


namespace sde {
	class TextureSheet : public Texture {
		private:
			std::unordered_map<unsigned int, Texture> m_sub_bitmaps{ };
			unsigned int m_tile_width{ 0 };
			unsigned int m_tile_height{ 0 };

			void load();


		public:
			TextureSheet() = default;
			TextureSheet(const std::string& path, unsigned int tile_width, unsigned int tile_height);
			~TextureSheet();

			void set_tile_width(float width);
			void set_tile_height(float height);
			void set_tile_size(float width, float height);

			float get_tile_width() const;
			float get_tile_height() const;

			const Texture& get_texture_rect(unsigned int index);

			ALLEGRO_BITMAP* get_texture_sheet() const;

			void dispose() override;
	};
}

#endif