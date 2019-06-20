#include "Renderer.hpp"


namespace sde {
	void Renderer::set_thickness(float thickness) {
		m_thickness = thickness;
	}

	void Renderer::draw_line(float x1, float y1, float x2, float y2) {
		al_draw_line(x1, y1, x2, y2, m_base_color, m_thickness);
	}

	void Renderer::draw_line(float x1, float y1, float x2, float y2, const Color3<unsigned char>& color) {
		al_draw_line(x1, y1, x2, y2, color.get_al_color(), m_thickness);
	}

	void Renderer::draw_rectangle(float x, float y, float width, float height, const Color3<unsigned char>& color) {
		al_draw_rectangle(x, y, width, height, color.get_al_color(), m_thickness);
	}

	void Renderer::draw_rectangle(float x, float y, float width, float height, const Color4<unsigned char>& color) {
		al_draw_rectangle(x, y, width, height, color.get_al_color(), m_thickness);
	}

	void Renderer::draw_rectangle(const Rectangle<float>& rectangle, const Color3<unsigned char>& color) {
		al_draw_rectangle(rectangle.get_x(), rectangle.get_y(), rectangle.get_width(), rectangle.get_height(), color.get_al_color(), m_thickness);
	}

	void Renderer::draw_rectangle(const Rectangle<float>& rectangle, const Color4<unsigned char>& color) {
		al_draw_rectangle(rectangle.get_x(), rectangle.get_y(), rectangle.get_width(), rectangle.get_height(), color.get_al_color(), m_thickness);
	}

	void Renderer::draw_filled_rectangle(float x, float y, float width, float height, const Color3<unsigned char>& color) {
		al_draw_filled_rectangle(x, y, width, height, color.get_al_color());
	}

	void Renderer::draw_filled_rectangle(float x, float y, float width, float height, const Color4<unsigned char>& color) {
		al_draw_filled_rectangle(x, y, width, height, color.get_al_color());
	}

	template<typename T>
	void Renderer::draw_filled_rectangle(const Rectangle<T>& rectangle, const Color3<unsigned char>& color) {
		al_draw_filled_rectangle(rectangle.get_x(), rectangle.get_y(), rectangle.get_width(), rectangle.get_height(), color.get_al_color());
	}

	template<typename T>
	void Renderer::draw_filled_rectangle(const Rectangle<T>& rectangle, const Color4<unsigned char>& color) {
		al_draw_filled_rectangle(rectangle.get_x(), rectangle.get_y(), rectangle.get_width(), rectangle.get_height(), color.get_al_color());
	}

	void Renderer::draw_circle(float x, float y, float radius) {
		al_draw_circle(x, y, radius, m_base_color, m_thickness);
	}

	void Renderer::draw_circle(float x, float y, float radius, float red, float green, float blue) {
		al_draw_circle(x, y, radius, al_map_rgb(red, green, blue), m_thickness);
	}

	void Renderer::draw_circle(float x, float y, float radius, const Color3<unsigned char>& color) {
		al_draw_circle(x, y, radius, color.get_al_color(), m_thickness);
	}

	void Renderer::draw_circle(float x, float y, float radius, const Color4<unsigned char>& color) {
		al_draw_circle(x, y, radius, color.get_al_color(), m_thickness);
	}

	void Renderer::draw_filled_circle(float x, float y, float radius, const Color3<unsigned char>& color) {
		al_draw_filled_circle(x, y, radius, color.get_al_color());
	}

	void Renderer::draw_filled_circle(float x, float y, float radius, const Color4<unsigned char>& color) {
		al_draw_filled_circle(x, y, radius, color.get_al_color());
	}

	void Renderer::draw_text(const std::string& text, const Font& font, float x, float y) {
		al_draw_text(font.get_font(), m_base_color, x, y, 0, text.c_str());
	}

	void Renderer::draw_colored_text(const std::string& text, const Font& font, const Color3<unsigned char>& color, float x, float y) {
		al_draw_text(font.get_font(), color.get_al_color(), x, y, 0, text.c_str());
	}

	void Renderer::draw_colored_text(const std::string& text, const Font& font, unsigned char red, unsigned char green, unsigned char blue, float x, float y) {
		al_draw_text(font.get_font(), al_map_rgb(red, green, blue), x, y, 0, text.c_str());
	}

	void Renderer::draw_sprite_queue(const SpriteQueue& sprite_queue) {
		for (auto& sprite : sprite_queue.get_sprite_map()) {
			al_draw_rotated_bitmap((*sprite.second).get_texture().get_texture(), sprite.second->get_width() / 2.0f, sprite.second->get_height() / 2.0f, sprite.second->get_x() + sprite.second->get_width() / 2.0f, sprite.second->get_y() + sprite.second->get_height() / 2.0f, sprite.second->get_rotation(), 0);
		}
	}

	void Renderer::draw_object(const Drawable& drawable) {
		drawable.draw();
	}

	void Renderer::draw_object(const Drawable& drawable, float x, float y) {
		drawable.draw(x, y);
	}

	void Renderer::draw_screen(const Screen& screen) {
		
	}

	Renderer::~Renderer() {
	}
}
