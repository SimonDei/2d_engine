#include "Renderer.h"


namespace sde {
	void Renderer::set_thickness(float thickness) {
		m_thickness = thickness;
	}

	void Renderer::draw_rectangle(int x, int y, int width, int height, const Color3<unsigned char>& color) {
		al_draw_rectangle(x, y, width, height, color.get_al_color(), m_thickness);
	}

	void Renderer::draw_rectangle(int x, int y, int width, int height, const Color4<unsigned char>& color) {
		al_draw_rectangle(x, y, width, height, color.get_al_color(), m_thickness);
	}

	void Renderer::draw_rectangle(const Rectangle<int>& rectangle, const Color3<unsigned char>& color) {
		al_draw_rectangle(rectangle.get_x(), rectangle.get_y(), rectangle.get_width(), rectangle.get_height(), color.get_al_color(), m_thickness);
	}

	void Renderer::draw_rectangle(const Rectangle<int>& rectangle, const Color4<unsigned char>& color) {
		al_draw_rectangle(rectangle.get_x(), rectangle.get_y(), rectangle.get_width(), rectangle.get_height(), color.get_al_color(), m_thickness);
	}

	void Renderer::draw_filled_rectangle(int x, int y, int width, int height, const Color3<unsigned char>& color) {
		al_draw_filled_rectangle(x, y, width, height, color.get_al_color());
	}

	void Renderer::draw_filled_rectangle(int x, int y, int width, int height, const Color4<unsigned char>& color) {
		al_draw_filled_rectangle(x, y, width, height, color.get_al_color());
	}

	void Renderer::draw_filled_rectangle(const Rectangle<int>& rectangle, const Color3<unsigned char>& color) {
		al_draw_filled_rectangle(rectangle.get_x(), rectangle.get_y(), rectangle.get_width(), rectangle.get_height(), color.get_al_color());
	}

	void Renderer::draw_filled_rectangle(const Rectangle<int>& rectangle, const Color4<unsigned char>& color) {
		al_draw_filled_rectangle(rectangle.get_x(), rectangle.get_y(), rectangle.get_width(), rectangle.get_height(), color.get_al_color());
	}

	void Renderer::draw_circle(int x, int y, int radius, int red, int green, int blue) {
		al_draw_circle(x, y, radius, al_map_rgb(red, green, blue), m_thickness);
	}

	void Renderer::draw_circle(int x, int y, int radius, const Color3<unsigned char>& color) {
		al_draw_circle(x, y, radius, color.get_al_color(), m_thickness);
	}

	void Renderer::draw_circle(int x, int y, int radius, const Color4<unsigned char>& color) {
		al_draw_circle(x, y, radius, color.get_al_color(), m_thickness);
	}

	void Renderer::draw_filled_circle(int x, int y, int radius, const Color3<unsigned char>& color) {
		al_draw_filled_circle(x, y, radius, color.get_al_color());
	}

	void Renderer::draw_filled_circle(int x, int y, int radius, const Color4<unsigned char>& color) {
		al_draw_filled_circle(x, y, radius, color.get_al_color());
	}

	void Renderer::draw_sprite(const Sprite& sprite) {
		al_draw_rotated_bitmap(sprite.get_texture().get_texture(), sprite.get_width() / 2.0f, sprite.get_height() / 2.0f, sprite.get_x() + sprite.get_width() / 2.0f, sprite.get_y() + sprite.get_height() / 2.0f, sprite.get_rotation(), 0);
	}

	void Renderer::draw_sprite(const Sprite& sprite, float x, float y) {
		al_draw_rotated_bitmap(sprite.get_texture().get_texture(), x + sprite.get_width() / 2.0f, y + sprite.get_height() / 2.0, x, y, sprite.get_rotation(), 0);
	}

	void Renderer::draw_sprite_queue(const SpriteQueue& sprite_queue) {
		for (auto& sprite : sprite_queue.get_sprite_map()) {
			al_draw_rotated_bitmap((*sprite.second).get_texture().get_texture(), sprite.second->get_width() / 2.0f, sprite.second->get_height() / 2.0f, sprite.second->get_x() + sprite.second->get_width() / 2.0f, sprite.second->get_y() + sprite.second->get_height() / 2.0f, sprite.second->get_rotation(), 0);
		}
	}

	void Renderer::draw_drawable_object(const Drawable& drawable) {
		drawable.draw();
	}

	void Renderer::draw_drawable_object(const Drawable& drawable, float x, float y) {
		drawable.draw(x, y);
	}

	Renderer::~Renderer() {
	}
}
