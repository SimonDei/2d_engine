#ifndef _TRANSFORMABLE_HPP_
#define _TRANSFORMABLE_HPP_

#include "Vector2.hpp"


namespace sde {
	class Transformable {
		protected:
			float m_x{ 0.0f };
			float m_y{ 0.0f };
			float m_width{ 0.0f };
			float m_height{ 0.0f };


		public:
			Transformable() = default;
			virtual ~Transformable() = default;

			virtual void set_x(float x) { m_x = x; };
			virtual void set_y(float y) { m_y = y; }
			virtual void set_width(float width) { m_width = width; }
			virtual void set_height(float height) { m_height = height; }

			virtual void set_position(float x, float y) { m_x = x; m_y = y; }
			virtual void set_position(const Vector2<float>& position) { m_x = position.get_x(); m_y = position.get_y(); }
			virtual void set_size(float width, float height) { m_width = width; m_height = height; }

			virtual void add_x(float x) { m_x += x; }
			virtual void add_y(float y) { m_y += y; }
			virtual void sub_x(float x) { m_x -= x; }
			virtual void sub_y(float y) { m_y -= y; }
			virtual void add_position(float x, float y) { m_x += x; m_y += y; }
			virtual void sub_position(float x, float y) { m_x -= x; m_y -= y; }

			virtual float get_x() const { return m_x; }
			virtual float get_y() const { return m_y; }
			virtual float get_center_x() const { return m_x + m_width / 2.0f; }
			virtual float get_center_y() const { return m_y + m_height / 2.0f; }
			virtual Vector2<float> get_center_position() const { return Vector2<float>{ m_x + m_width / 2.0f, m_y + m_height / 2.0f }; }
			
			virtual Vector2<float> get_top_left() const { return Vector2<float>{ m_x, m_y }; }
			virtual Vector2<float> get_top_right() const { return Vector2<float>{ m_x + m_width, m_height }; }
			virtual Vector2<float> get_bottom_left() const { return Vector2<float>{ m_x, m_y + m_height }; }
			virtual Vector2<float> get_bottom_right() const { return Vector2<float>{ m_x + m_width, m_y + m_height}; }

			virtual float get_width() const { return m_width; }
			virtual float get_height() const { return m_height; }
			virtual Vector2<float> get_size() const { return Vector2<float>{ m_width, m_height }; }
			virtual float get_half_width() const { return m_width / 2.0f; }
			virtual float get_half_height() const { return m_height / 2.0f; }
	};
}

#endif