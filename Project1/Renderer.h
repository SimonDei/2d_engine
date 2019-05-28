#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "Sprite.h"
#include "SpriteQueue.h"
#include "Drawable.h"
#include "Rectangle.h"
#include "Color3.h"
#include "Color4.h"


namespace sde {
	class Renderer {
		private:
			float m_thickness = 1.0f;


		public:
			Renderer() = default;
			~Renderer();

			void set_thickness(float thickness);

			void draw_rectangle(int x, int y, int width, int height, const Color3<unsigned char>& color);
			void draw_rectangle(int x, int y, int width, int height, const Color4<unsigned char>& color);
			void draw_rectangle(const Rectangle<int>& rectangle, const Color3<unsigned char>& color);
			void draw_rectangle(const Rectangle<int>& rectangle, const Color4<unsigned char>& color);

			void draw_filled_rectangle(int x, int y, int width, int height, const Color3<unsigned char>& color);
			void draw_filled_rectangle(int x, int y, int width, int height, const Color4<unsigned char>& color);
			void draw_filled_rectangle(const Rectangle<int>& rectangle, const Color3<unsigned char>& color);
			void draw_filled_rectangle(const Rectangle<int>& rectangle, const Color4<unsigned char>& color);

			void draw_circle(int x, int y, int radius, const Color3<unsigned char>& color);
			void draw_circle(int x, int y, int radius, const Color4<unsigned char>& color);

			void draw_filled_circle(int x, int y, int radius, const Color3<unsigned char>& color);
			void draw_filled_circle(int x, int y, int radius, const Color4<unsigned char>& color);

			void draw_sprite(const Sprite& sprite);
			void draw_sprite(const Sprite& sprite, float x, float y);

			void draw_sprite_queue(const SpriteQueue& sprite_queue);
			
			void draw_drawable_object(const Drawable& drawable);
			void draw_drawable_object(const Drawable& drawable, float x, float y);


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
