#ifndef _SPRITE_HPP_
#define _SPRITE_HPP_

#include <allegro5/allegro.h>

#include <string>

#include "Texture.hpp"
#include "Drawable.hpp"
#include "Rectangle.hpp"


namespace sde {
	class Sprite : public Drawable {
		private:
			std::shared_ptr<Texture> m_texture = nullptr;
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

			void set_rotation(float rotation);

			void add_rotation(float rotation);

			float get_rotation() const;
			const Texture& get_texture() const;
	};
}

#endif