#ifndef _SPRITE_HPP_
#define _SPRITE_HPP_

#include <allegro5/allegro.h>

#include <iostream>
#include <string>

#include "Texture.hpp"
#include "Transformable.hpp"
#include "Drawable.hpp"
#include "Rectangle.hpp"


namespace sde {
	class Sprite : public Drawable, public Transformable {
		private:
			std::shared_ptr<Texture> m_texture{ nullptr };
			float m_rotation{ 0.0f };


		public:
			Sprite() = default;
			explicit Sprite(const std::string& path);
			explicit Sprite(const Texture& texture);
			Sprite(const std::string& path, float x, float y);
			Sprite(const Texture& texture, float x, float y);
			Sprite(const Texture& texture, float x, float y, float rotation);
			~Sprite();

			void set_texture(const Texture& texture);

			void set_rotation(float rotation);
			void add_rotation(float rotation);

			void draw() const override;
			void draw(float x, float y) const override;

			float get_rotation() const;
			const Texture& get_texture() const;
	};
}

#endif