#ifndef _TEXTURESHEET_HPP_
#define _TEXTURESHEET_HPP_

#include <allegro5/allegro.h>

#include <string>
#include <unordered_map>

#include "Texture.hpp"
#include "Rectangle.hpp"
#include "SdeException.hpp"


namespace sde {
	class TextureSheet : public Texture {
		private:
			std::unordered_map<unsigned int, Rectangle<float>> m_sub_rects{ };
			unsigned int m_tile_width{ 0 };
			unsigned int m_tile_height{ 0 };

			void load();


		public:
			TextureSheet() = default;
			TextureSheet(const std::string& path, unsigned int tile_width, unsigned int tile_height);
			~TextureSheet() = default;

			void load_texture(const std::string& path, unsigned int tile_width, unsigned int tile_height);

			void set_tile_width(float width);
			void set_tile_height(float height);
			void set_tile_size(float width, float height);

			float get_tile_width() const;
			float get_tile_height() const;

			void draw_texture_rect(unsigned int index, float dst_x, float dst_y);
			void draw_texture_rect(float src_x, float src_y, float dst_x, float dst_y) const;
			void draw_texture_rect(float src_x, float src_y, float dst_x, float dst_y, float dst_w, float dst_h) const;

			const Rectangle<float>& get_texture_rect(unsigned int index);

			void dispose() override;
	};
}

#endif