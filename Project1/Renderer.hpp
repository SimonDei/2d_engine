#ifndef _RENDERER_HPP_
#define _RENDERER_HPP_

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "Sprite.hpp"
#include "SpriteQueue.hpp"
#include "Drawable.hpp"
#include "Font.hpp"
#include "Rectangle.hpp"
#include "Color3.hpp"
#include "Color4.hpp"


namespace sde {
	class Renderer {
		private:
			ALLEGRO_COLOR m_base_color{ 255, 255, 255, 255 };
			float m_thickness = 1.0f;


		public:
			Renderer() = default;
			~Renderer();

			void set_thickness(float thickness);

			void draw_line(float x1, float y1, float x2, float y2);
			void draw_line(float x1, float y1, float x2, float y2, const Color3<unsigned char>& color);

			void draw_rectangle(float x, float y, float width, float height, const Color3<unsigned char>& color);
			void draw_rectangle(float x, float y, float width, float height, const Color4<unsigned char>& color);
			void draw_rectangle(const Rectangle<float>& rectangle, const Color3<unsigned char>& color);
			void draw_rectangle(const Rectangle<float>& rectangle, const Color4<unsigned char>& color);

			void draw_filled_rectangle(float x, float y, float width, float height, const Color3<unsigned char>& color);
			void draw_filled_rectangle(float x, float y, float width, float height, const Color4<unsigned char>& color);			
			template<typename T>
			void draw_filled_rectangle(const Rectangle<T>& rectangle, const Color3<unsigned char>& color);			
			template<typename T>
			void draw_filled_rectangle(const Rectangle<T>& rectangle, const Color4<unsigned char>& color);

			void draw_circle(float x, float y, float radius);
			void draw_circle(float x, float y, float radius, float red, float green, float blue);
			void draw_circle(float x, float y, float radius, const Color3<unsigned char>& color);
			void draw_circle(float x, float y, float radius, const Color4<unsigned char>& color);

			void draw_filled_circle(float x, float y, float radius, const Color3<unsigned char>& color);
			void draw_filled_circle(float x, float y, float radius, const Color4<unsigned char>& color);

			void draw_sprite(const Sprite& sprite);
			void draw_sprite(const Sprite& sprite, float x, float y);

			void draw_sprite_queue(const SpriteQueue& sprite_queue);
			
			void draw_drawable_object(const Drawable& drawable);
			void draw_drawable_object(const Drawable& drawable, float x, float y);

			void draw_text(const std::string& text, const Font& font, float x, float y);
			
			void draw_colored_text(const std::string& text, const Font& font, const Color3<unsigned char>& color, float x, float y);
			void draw_colored_text(const std::string& text, const Font& font, unsigned char red, unsigned char green, unsigned char blue, float x, float y);

			inline void clear(unsigned char red, unsigned char green, unsigned char blue) const {
				al_clear_to_color(al_map_rgb(red, green, blue));
			}
			inline void clear(const Color3<unsigned char>& color) const {
				al_clear_to_color(color.get_al_color());
			}
			
			inline void display() const {
				al_flip_display();
			}
	};
}

#endif