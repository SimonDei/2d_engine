#ifndef _BUTTON_HPP_
#define _BUTTON_HPP_

#include <functional>

#include "Texture.hpp"
#include "Drawable.hpp"
#include "Transformable.hpp"
#include "Math.hpp"


namespace sde {
	class Button : public Drawable, public Transformable {
		private:
			std::shared_ptr<Texture> m_button_up{ nullptr };
			std::shared_ptr<Texture> m_button_down{ nullptr };
			ALLEGRO_MOUSE_STATE m_mouse_state{ };
			ALLEGRO_MOUSE_STATE m_old_mouse_state{ };
			std::function<void()> m_press_function{ };
			bool m_pressed{ false };
			bool m_state_change{ false };


		public:
			Button() = default;
			Button(const Texture& button_up, const Texture& button_down);
			Button(const Texture& button_up, const Texture& button_down, float x, float y, float width, float height);
			~Button() = default;

			void set_handle_function(const std::function<void()>& function);

			bool is_pressed();
			bool is_pressed_and_handle();

			void handle();

			void draw() const override;
			void draw(float x, float y) const override;
	};
}

#endif