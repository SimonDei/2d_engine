#ifndef _TEXTBOX_HPP_
#define _TEXTBOX_HPP_

#include <allegro5/allegro_font.h>

#include <memory>

#include "Texture.hpp"
#include "Font.hpp"
#include "Keycodes.hpp"
#include "Drawable.hpp"
#include "Transformable.hpp"
#include "Math.hpp"


namespace sde {
	class Textbox : public Drawable, public Transformable {
		private:
			std::shared_ptr<Texture> m_texture{ nullptr };
			std::shared_ptr<Font> m_font{ nullptr };
			ALLEGRO_MOUSE_STATE m_mouse_state{ };
			ALLEGRO_COLOR m_text_color{ 0, 0, 0, 255 };
			std::string m_text{ };
			unsigned char m_max_char{ 255 };
			

		public:
			Textbox() = default;
			explicit Textbox(const Texture& texture);
			Textbox(const Texture& texture, const Font& font);
			~Textbox();

			void set_text_color(unsigned char red, unsigned char green, unsigned char blue);
			void set_max_size(unsigned char max_size);

			bool is_focused();
			bool is_focused_and_handle(const Keycode& new_char);

			void draw() const override;
			void draw(float x, float y) const override;
	};
}

#endif