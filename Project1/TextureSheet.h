#pragma once

#include <allegro5/allegro.h>

#include <string>
#include <vector>
#include <unordered_map>

#include "Texture.h"
#include "SubTexture.h"
#include "Disposable.h"


namespace sde {
	class TextureSheet : public Disposable {
		private:
			ALLEGRO_BITMAP* m_texture_sheet = nullptr;
			std::vector<std::shared_ptr<SubTexture>> m_sub_bitmaps;
			float m_width = 0.0f;
			float m_height = 0.0f;
			float m_tile_width = 0.0f;
			float m_tile_height = 0.0f;


		public:
			TextureSheet() = default;
			explicit TextureSheet(const std::string& path);
			explicit TextureSheet(ALLEGRO_BITMAP* al_bitmap);
			TextureSheet(const std::string& path, float width, float height);
			TextureSheet(ALLEGRO_BITMAP* al_bitmap, float width, float height);
			~TextureSheet();

			void load_texture(const std::string& path);

			void set_tile_width(float width);
			void set_tile_height(float height);
			void set_tile_size(float width, float height);

			const ALLEGRO_BITMAP& get_texture_rect(float x, float y);

			float get_width() const;
			float get_height() const;

			ALLEGRO_BITMAP* get_texture() const;

			void dispose() override;
	};
}
