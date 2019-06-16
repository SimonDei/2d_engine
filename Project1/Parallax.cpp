#include "Parallax.hpp"


namespace sde {
	void Parallax::add_parallax_sprite(unsigned int level, float pos_x, float pos_y, float speed_x, float speed_y, const Texture& texture) {
		m_scroll_sprites.insert(m_scroll_sprites.begin() + level, ScrollSprite{ level, pos_x, pos_y, speed_x, speed_y, texture });
	}

	void Parallax::update(double delta) {
		for (auto& sprite : m_scroll_sprites) {
			sprite.m_offset_x += sprite.m_speed_x * delta * 25.0f;
			sprite.m_offset_y += sprite.m_speed_y * delta * 25.0f;
			if (sprite.m_offset_x >= sprite.m_texture->get_width()) sprite.m_offset_x = 0.0f;
			if (sprite.m_offset_y >= sprite.m_texture->get_height()) sprite.m_offset_y = 0.0f;
		}
	}

	void Parallax::draw() const {
		for (auto& sprite : m_scroll_sprites) {
			al_draw_bitmap_region(sprite.m_texture->get_texture(),
								  0.0f,												 0.0f,
								  sprite.m_texture->get_width() - sprite.m_offset_x, sprite.m_texture->get_height(),
								  sprite.m_pos_x + sprite.m_offset_x,				 sprite.m_pos_y + sprite.m_offset_y,
								  0);

			al_draw_bitmap_region(sprite.m_texture->get_texture(),
								  sprite.m_texture->get_width() - sprite.m_offset_x, 0.0f,
								  sprite.m_offset_x,								 sprite.m_texture->get_height(),
								  sprite.m_pos_x,									 sprite.m_pos_y,
								  0);
		}
	}

	void Parallax::draw(float x, float y) const {
		for (auto& sprite : m_scroll_sprites) {
			//al_draw_scaled_bitmap(sprite.m_texture->get_texture(), 0.0f, 0.0f, sprite.m_texture->get_width(), sprite.m_texture->get_height(), x + sprite.m_pos_x, y + sprite.m_pos_y, m_width, m_height, 0);
		}
	}

	Parallax::~Parallax() {
	}
}