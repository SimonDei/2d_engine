#ifndef _RENDERER_HPP_
#define _RENDERER_HPP_

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "SpriteQueue.hpp"
#include "Drawable.hpp"
#include "Font.hpp"
#include "Camera.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Color3.hpp"
#include "Color4.hpp"


namespace sde {
	class Renderer {
		private:
			Camera* m_camera{ nullptr };
			ALLEGRO_COLOR m_base_color{ 1.0f, 1.0f, 1.0f, 1.0f };
			float m_thickness{ 1.0f };


		public:
			Renderer() = default;
			~Renderer();

			void set_thickness(float thickness);
			void set_camera(Camera* camera);

			void draw_line(float x1, float y1, float x2, float y2);
			void draw_line(float x1, float y1, float x2, float y2, const Color3<unsigned char>& color);

			void draw_rectangle(float x, float y, float width, float height);
			void draw_rectangle(const Rectangle<float>& rectangle);
			void draw_rectangle(float x, float y, float width, float height, const Color3<unsigned char>& color);
			void draw_rectangle(float x, float y, float width, float height, const Color4<unsigned char>& color);
			void draw_rectangle(const Rectangle<float>& rectangle, const Color3<unsigned char>& color);
			void draw_rectangle(const Rectangle<float>& rectangle, const Color4<unsigned char>& color);

			void draw_filled_rectangle(float x, float y, float width, float height);
			void draw_filled_rectangle(const Rectangle<float>& rectangle);
			void draw_filled_rectangle(float x, float y, float width, float height, unsigned char red, unsigned char green, unsigned char blue);
			void draw_filled_rectangle(float x, float y, float width, float height, const Color3<unsigned char>& color);
			void draw_filled_rectangle(float x, float y, float width, float height, const Color4<unsigned char>& color);			
			void draw_filled_rectangle(const Rectangle<float>& rectangle, const Color3<unsigned char>& color);			
			void draw_filled_rectangle(const Rectangle<float>& rectangle, const Color4<unsigned char>& color);

			void draw_circle(float x, float y, float radius);
			void draw_circle(const Circle<float>& circle);
			void draw_circle(float x, float y, float radius, unsigned char red, unsigned char green, unsigned char blue);
			void draw_circle(const Circle<float>& circle, unsigned char red, unsigned char green, unsigned char blue);
			void draw_circle(float x, float y, float radius, const Color3<unsigned char>& color);
			void draw_circle(float x, float y, float radius, const Color4<unsigned char>& color);

			void draw_filled_circle(float x, float y, float radius);
			void draw_filled_circle(const Circle<float>& circle);
			void draw_filled_circle(float x, float y, float radius, unsigned char red, unsigned char green, unsigned char blue);
			void draw_filled_circle(float x, float y, float radius, const Color3<unsigned char>& color);
			void draw_filled_circle(float x, float y, float radius, const Color4<unsigned char>& color);

			void draw_text(const std::string& text, const Font& font, float x, float y);
			void draw_text(const std::string& text, const Font& font, float x, float y, unsigned char red, unsigned char green, unsigned char blue);
			void draw_text(const std::string& text, const Font& font, float x, float y, const Color3<unsigned char>& color);
			void draw_text(const std::string& text, const Font& font, float x, float y, const Color4<unsigned char>& color);

			void draw_object(const Drawable& drawable);
			void draw_object(const Drawable& drawable, float x, float y);
			
			void draw_sprite_queue(const SpriteQueue& sprite_queue);

			inline void clear(int color) const;
			inline void clear(unsigned char red, unsigned char green, unsigned char blue) const;
			inline void clear(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) const;
			inline void clear(const Color3<unsigned char>& color) const;
			inline void clear(const Color4<unsigned char>& color) const;

			inline void display() const;
	};
}

#endif