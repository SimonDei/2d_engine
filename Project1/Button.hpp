#ifndef _BUTTON_HPP_
#define _BUTTON_HPP_

#include "Texture.hpp"
#include "Drawable.hpp"


namespace sde {
	class Button : public Drawable {
		private:
			Texture* m_button_up = nullptr;
			Texture* m_button_down = nullptr;
			float m_x = 0.0f;
			float m_y = 0.0f;
			float m_width = 0.0f;
			float m_height = 0.0f;


		public:
			Button() = default;
			Button(const Texture& button_up, const Texture& button_down);
			Button(const Texture& button_up, const Texture& button_down, float x, float y, float width, float height);
			~Button();

			void set_position(float x, float y);
			void set_size(float width, float height);
			
			void draw() const override;
			void draw(float x, float y) const override;
	};
}

#endif