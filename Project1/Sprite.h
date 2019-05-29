#pragma once

#include <allegro5/allegro.h>

#include <string>

#include "Texture.h"
#include "SubTexture.h"
#include "Drawable.h"
#include "Rectangle.h"


namespace sde {
	class Sprite : public Drawable {
		private:
			Texture* m_texture;
			float m_x = 0.0f;
			float m_y = 0.0f;
			float m_width = 0.0f;
			float m_height = 0.0f;
			float m_rotation = 0.0f;


		public:
			Sprite() = default;
			explicit Sprite(const Sprite& sprite);
			explicit Sprite(const std::string& path);
			explicit Sprite(const Texture& texture);
			Sprite(const std::string& path, float x, float y);
			Sprite(const Texture& texture, float x, float y);
			Sprite(const Texture& texture, float x, float y, float rotation);
			~Sprite();

			void draw() const override;
			void draw(float x, float y) const override;

			void set_x(float x);
			void set_y(float y);
			void set_rotation(float rotation);

			void add_x(float x);
			void add_y(float y);
			void add_rotation(float rotation);

			float get_x() const;
			float get_y() const;
			float get_rotation() const;
			float get_width() const;
			float get_height() const;
			const Texture& get_texture() const;
	};
}
