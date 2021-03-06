#include "Renderer.hpp"


namespace sde {
	void Renderer::set_thickness(float thickness) {
		m_thickness = thickness;
	}

	void Renderer::set_camera(Camera* camera) {
		m_camera = camera;
	}

	//==========================
	//===     DRAW LINES     ===
	//==========================
	void Renderer::draw_line(float x1, float y1, float x2, float y2) {
		al_draw_line(x1, y1, x2, y2, m_base_color, m_thickness);
	}

	void Renderer::draw_line(float x1, float y1, float x2, float y2, const Color3<unsigned char>& color) {
		al_draw_line(x1, y1, x2, y2, color.get_al_color(), m_thickness);
	}

	//==============================
	//===     DRAW RECTANGLE     ===
	//==============================
	void Renderer::draw_rectangle(float x, float y, float width, float height) {
		al_draw_rectangle(x, y, x + width, y + height, m_base_color, m_thickness);
	}

	void Renderer::draw_rectangle(const Rectangle<float>& rectangle) {
		al_draw_rectangle(rectangle.get_x(), rectangle.get_y(), rectangle.get_x() + rectangle.get_width() , rectangle.get_y() + rectangle.get_height(), m_base_color, m_thickness);
	}

	void Renderer::draw_rectangle(float x, float y, float width, float height, const Color3<unsigned char>& color) {
		al_draw_rectangle(x, y, x + width, y + height, color.get_al_color(), m_thickness);
	}

	void Renderer::draw_rectangle(float x, float y, float width, float height, const Color4<unsigned char>& color) {
		al_draw_rectangle(x, y, x + width, y + height, color.get_al_color(), m_thickness);
	}

	void Renderer::draw_rectangle(const Rectangle<float>& rectangle, const Color3<unsigned char>& color) {
		al_draw_rectangle(rectangle.get_x(), rectangle.get_y(), rectangle.get_x() + rectangle.get_width(), rectangle.get_y() + rectangle.get_height(), color.get_al_color(), m_thickness);
	}

	void Renderer::draw_rectangle(const Rectangle<float>& rectangle, const Color4<unsigned char>& color) {
		al_draw_rectangle(rectangle.get_x(), rectangle.get_y(), rectangle.get_x() + rectangle.get_width(), rectangle.get_y() + rectangle.get_height(), color.get_al_color(), m_thickness);
	}

	//=====================================
	//===     DRAW FILLED RECTANGLE     ===
	//=====================================
	void Renderer::draw_filled_rectangle(float x, float y, float width, float height) {
		al_draw_filled_rectangle(x, y, x + width, y + height, m_base_color);
	}

	void Renderer::draw_filled_rectangle(const Rectangle<float>& rectangle) {
		al_draw_filled_rectangle(rectangle.get_x(), rectangle.get_y(), rectangle.get_x() + rectangle.get_width(), rectangle.get_y() + rectangle.get_height(), m_base_color);
	}

	void Renderer::draw_filled_rectangle(float x, float y, float width, float height, unsigned char red, unsigned char green, unsigned char blue) {
		al_draw_filled_rectangle(x, y, x + width, y + height, al_map_rgb(red, green, blue));
	}

	void Renderer::draw_filled_rectangle(float x, float y, float width, float height, const Color3<unsigned char>& color) {
		al_draw_filled_rectangle(x, y, x + width, y + height, color.get_al_color());
	}

	void Renderer::draw_filled_rectangle(float x, float y, float width, float height, const Color4<unsigned char>& color) {
		al_draw_filled_rectangle(x, y, x + width, y + height, color.get_al_color());
	}

	void Renderer::draw_filled_rectangle(const Rectangle<float>& rectangle, const Color3<unsigned char>& color) {
		al_draw_filled_rectangle(rectangle.get_x(), rectangle.get_y(), rectangle.get_x() + rectangle.get_width(), rectangle.get_y() + rectangle.get_height(), color.get_al_color());
	}

	void Renderer::draw_filled_rectangle(const Rectangle<float>& rectangle, const Color4<unsigned char>& color) {
		al_draw_filled_rectangle(rectangle.get_x(), rectangle.get_y(), rectangle.get_x() + rectangle.get_width(), rectangle.get_y() + rectangle.get_height(), color.get_al_color());
	}

	//===========================
	//===     DRAW CIRCLE     ===
	//===========================
	void Renderer::draw_circle(float x, float y, float radius) {
		al_draw_circle(x, y, radius, m_base_color, m_thickness);
	}

	void Renderer::draw_circle(const Circle<float>& circle) {
		al_draw_circle(circle.get_x(), circle.get_y(), circle.get_radius(), m_base_color, m_thickness);
	}

	void Renderer::draw_circle(float x, float y, float radius, unsigned char red, unsigned char green, unsigned char blue) {
		al_draw_circle(x, y, radius, al_map_rgb(red, green, blue), m_thickness);
	}

	void Renderer::draw_circle(const Circle<float>& circle, unsigned char red, unsigned char green, unsigned char blue) {
		al_draw_circle(circle.get_x(), circle.get_y(), circle.get_radius(), al_map_rgb(red, green, blue), m_thickness);
	}

	void Renderer::draw_circle(float x, float y, float radius, const Color3<unsigned char>& color) {
		al_draw_circle(x, y, radius, color.get_al_color(), m_thickness);
	}

	void Renderer::draw_circle(float x, float y, float radius, const Color4<unsigned char>& color) {
		al_draw_circle(x, y, radius, color.get_al_color(), m_thickness);
	}

	//==================================
	//===     DRAW FILLED CIRCLE     ===
	//==================================
	void Renderer::draw_filled_circle(float x, float y, float radius) {
		al_draw_filled_circle(x, y, radius, m_base_color);
	}

	void Renderer::draw_filled_circle(const Circle<float>& circle) {
		al_draw_filled_circle(circle.get_x(), circle.get_y(), circle.get_radius(), m_base_color);
	}
	
	void Renderer::draw_filled_circle(float x, float y, float radius, unsigned char red, unsigned char green, unsigned char blue) {
		al_draw_filled_circle(x, y, radius, al_map_rgb(red, green, blue));
	}

	void Renderer::draw_filled_circle(float x, float y, float radius, const Color3<unsigned char>& color) {
		al_draw_filled_circle(x, y, radius, color.get_al_color());
	}

	void Renderer::draw_filled_circle(float x, float y, float radius, const Color4<unsigned char>& color) {
		al_draw_filled_circle(x, y, radius, color.get_al_color());
	}

	//=========================
	//===     DRAW TEXT     ===
	//=========================
	void Renderer::draw_text(const std::string& text, const Font& font, float x, float y) {
		al_draw_text(font.get_font(), m_base_color, x, y, 0, text.c_str());
	}

	void Renderer::draw_text(const std::string& text, const Font& font, float x, float y, unsigned char red, unsigned char green, unsigned char blue) {
		al_draw_text(font.get_font(), al_map_rgb(red, green, blue), x, y, 0, text.c_str());
	}

	void Renderer::draw_text(const std::string& text, const Font& font, float x, float y, const Color3<unsigned char>& color) {
		al_draw_text(font.get_font(), color.get_al_color(), x, y, 0, text.c_str());
	}

	void Renderer::draw_text(const std::string& text, const Font& font, float x, float y, const Color4<unsigned char>& color) {
		al_draw_text(font.get_font(), color.get_al_color(), x, y, 0, text.c_str());
	}

	//===========================
	//===     DRAW OBJECT     ===
	//===========================
	void Renderer::draw_object(const Drawable& drawable) {
		drawable.draw();
	}

	void Renderer::draw_object(const Drawable& drawable, float x, float y) {
		drawable.draw(x, y);
	}

	//=========================
	//===     DRAW MISC     ===
	//=========================
	void Renderer::draw_sprite_queue(const SpriteQueue& sprite_queue) {
		for (auto& sprite : sprite_queue.get_sprite_map()) {
			al_draw_rotated_bitmap((*sprite.second).get_texture().get_texture(), sprite.second->get_width() / 2.0f, sprite.second->get_height() / 2.0f, sprite.second->get_x() + sprite.second->get_width() / 2.0f, sprite.second->get_y() + sprite.second->get_height() / 2.0f, sprite.second->get_rotation(), 0);
		}
	}

	void Renderer::clear(int color) const {
		al_clear_to_color(al_map_rgb(color >> 16 & 0xFF, color >> 8 & 0xFF, color & 0xFF));
	}

	void Renderer::clear(unsigned char red, unsigned char green, unsigned char blue) const {
		al_clear_to_color(al_map_rgb(red, green, blue));
	}

	void Renderer::clear(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) const {
		al_clear_to_color(al_map_rgba(red, green, blue, alpha));
	}

	void Renderer::clear(const Color3<unsigned char>& color) const {
		al_clear_to_color(color.get_al_color());
	}

	void Renderer::clear(const Color4<unsigned char>& color) const {
		al_clear_to_color(color.get_al_color());
	}

	void Renderer::display() const {
		al_flip_display();
	}

	Renderer::~Renderer() {
		m_camera = nullptr;
	}
}
