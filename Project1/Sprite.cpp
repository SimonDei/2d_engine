#include "Sprite.hpp"


namespace sde {
	Sprite::Sprite(const std::string& path) {
		m_texture = std::make_shared<Texture>(path);
		m_width = m_texture->get_width();
		m_height = m_texture->get_height();
	}

	Sprite::Sprite(const Texture& texture) {
		m_texture = std::make_shared<Texture>(texture);
		m_width = m_texture->get_width();
		m_height = m_texture->get_height();
	}
	
	Sprite::Sprite(const std::string& path, float x, float y) {
		m_texture = std::make_shared<Texture>(path);
		m_x = x;
		m_y = y;
		m_width = m_texture->get_width();
		m_height = m_texture->get_height();
	}

	Sprite::Sprite(const Texture& texture, float x, float y) {
		m_texture = std::make_shared<Texture>(texture);
		m_x = x;
		m_y = y;
		m_width = m_texture->get_width();
		m_height = m_texture->get_height();
	}

	Sprite::Sprite(const Texture& texture, float x, float y, float rotation) {
		m_texture = std::make_shared<Texture>(texture);
		m_x = x;
		m_y = y;
		m_width = m_texture->get_width();
		m_height = m_texture->get_height();
		m_rotation = rotation;
	}

	void Sprite::set_texture(const Texture& texture) {
		m_texture = std::make_shared<Texture>(texture);
		m_width = m_texture->get_width();
		m_height = m_texture->get_height();
	}

	void Sprite::set_rotation(float rotation) {
		m_rotation = rotation;
	}

	void Sprite::add_rotation(float rotation) {
		m_rotation += rotation;
	}

	void Sprite::draw() const {
		al_draw_scaled_bitmap(m_texture->get_texture(), 0.0f, 0.0f, m_texture->get_width(), m_texture->get_height(), m_x, m_y, m_width, m_height, 0);
	}

	void Sprite::draw(float x, float y) const {
		al_draw_scaled_bitmap(m_texture->get_texture(), 0.0f, 0.0f, m_texture->get_width(), m_texture->get_height(), x, y, m_width, m_height, 0);
	}

	float Sprite::get_rotation() const {
		return m_rotation;
	}

	const Texture& Sprite::get_texture() const {
		return *m_texture;
	}
}
