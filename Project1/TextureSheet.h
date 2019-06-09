#pragma once

#include <allegro5/allegro.h>

#include <string>
#include <unordered_map>

#include "Texture.h"
#include "NullException.h"


namespace sde {
	class TextureSheet : public Texture {
		private:
			std::unordered_map<std::string, Texture> m_sub_bitmaps;
			float m_tile_width = 0.0f;
			float m_tile_height = 0.0f;


		public:
			TextureSheet() = default;
			explicit TextureSheet(const std::string& path);
			explicit TextureSheet(ALLEGRO_BITMAP* al_bitmap);
			~TextureSheet();

			void set_tile_width(float width);
			void set_tile_height(float height);
			void set_tile_size(float width, float height);

			const Texture& get_texture_rect(float x, float y, float width, float height);

			ALLEGRO_BITMAP* get_texture_sheet() const;

			void dispose() override;
	};
}
