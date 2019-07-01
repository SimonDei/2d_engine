#ifndef _RECTANGLE_HPP_
#define _RECTANGLE_HPP_

#include <iostream>

#include "Vector2.hpp"


namespace sde {
	template<typename T>
	class Rectangle {
		private:
			T m_x;
			T m_y;
			T m_width;
			T m_height;


		public:
			Rectangle() = default;
			Rectangle(T x, T y, T width, T height) {
				m_x = x;
				m_y = y;
				m_width = width;
				m_height = height;
			}
			~Rectangle() { }

			const T& get_x() const {
				return m_x;
			}
			const T& get_y() const {
				return m_y;
			}
			const T& get_width() const {
				return m_width;
			}
			const T& get_height() const {
				return m_height;
			}

			void set_x(const T& x) {
				m_x = x;
			}
			void set_y(const T& y) {
				m_y = y;
			}
			void set_width(const T& width) {
				m_width = width;
			}
			void set_height(const T& height) {
				m_height = height;
			}

			void set_rectangle(const T& x, const T& y, const T& width, const T& height) {
				m_x = x;
				m_y = y;
				m_width = width;
				m_height = height;
			}

			bool intersects(const Rectangle<T>& other) {
				if ((other.m_x <= m_x + m_width || other.m_x + other.m_width >= m_x) &&
					(other.m_y <= m_y + m_height || other.m_y + other.m_height >= m_y)) {
					return true;
				}
				return false;
			}

			bool contains(const Vector2<T>& other) {
				if ((other.m_x >= m_x && other.m_x <= m_x + m_width) &&
					(other.m_y >= m_y && other.m_y <= m_y + m_height)) {
					return true;
				}
				return false;
			}

			const Rectangle<T>& get_rectangle() const {
				return this;
			}

			inline Rectangle<T>& operator=(const Rectangle<T>& other) {
				m_x = other.get_x();
				m_y = other.get_y();
				m_width = other.get_width();
				m_height = other.get_height();
				return *this;
			}

			inline const std::string to_string() const {
				return std::to_string(m_x) + ", " + std::to_string(m_y) + ", " + std::to_string(m_width) + ", " + std::to_string(m_height);
			}
	};
}

#endif