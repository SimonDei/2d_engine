#ifndef _PARALLAX_HPP_
#define _PARALLAX_HPP_

#include <allegro5/allegro.h>

#include <vector>
#include <memory>

#include "Texture.hpp"
#include "Updateable.hpp"
#include "Drawable.hpp"


namespace sde {
	struct ScrollSprite {
		unsigned int m_level{ 0 };
		float m_pos_x{ 0.0f };
		float m_pos_y{ 0.0f };
		float m_offset_x{ 0.0f };
		float m_offset_y{ 0.0f };
		float m_speed_x{ 0.0f };
		float m_speed_y{ 0.0f };
		std::shared_ptr<Texture> m_texture{ nullptr };


		ScrollSprite(unsigned int level, float pos_x, float pos_y, float speed_x, float speed_y, const Texture& texture) {
			m_level = level;
			m_pos_x = pos_x;
			m_pos_y = pos_y;
			m_speed_x = speed_x;
			m_speed_y = speed_y;
			m_texture = std::make_shared<Texture>(texture);
		}
	};

	class Parallax : public Drawable, public Updateable {
		private:
			std::vector<ScrollSprite> m_scroll_sprites{ };


		public:
			Parallax() = default;
			~Parallax();
			
			void add_parallax_sprite(unsigned int level, float pos_x, float pos_y, float speed_x, float speed_y, const Texture& texture);

			void update(float delta) override;

			void draw() const override;
			void draw(float x, float y) const override;
	};
}

#endif