#ifndef _SCREEN_HPP_
#define _SCREEN_HPP_

#include <allegro5/allegro.h>

#include "Display.hpp"
#include "Texture.hpp"
#include "Color3.hpp"
#include "Color4.hpp"
#include "Drawable.hpp"
#include "Disposable.hpp"


namespace sde {
	class Screen : public Drawable, public Disposable {
		private:
			ALLEGRO_BITMAP* m_bitmap{ nullptr };
			ALLEGRO_DISPLAY* m_display{ nullptr };


		public:
			Screen() = default;
			Screen(const Display& display);
			~Screen();

			void set_display(const Display& display);

			void clear_screen(unsigned char red, unsigned char green, unsigned char blue);
			void clear_screen(const Color3<unsigned char>& color);
			void clear_screen(const Color4<unsigned char>& color);

			void draw_to_screen(const Texture& texture);
			void draw_to_screen(const Texture& texture, float x, float y);
			void draw_to_screen(const Texture& texture, float x, float y, float width, float height);

			void draw_to_screen(const Drawable& drawable);
			void draw_to_screen(const Drawable& drawable, float x, float y);

			void draw() const override;

			void dispose() override;
	};
}

#endif