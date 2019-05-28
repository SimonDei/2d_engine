#pragma once

#include <iostream>


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
	};
}

template<typename T>
inline std::ostream& operator<<(std::ostream& stream, const sde::Rectangle<T>& other) {
	stream << other.get_x() << ", " << other.get_y() << ", " << other.get_width() << ", " << other.get_height();
	return stream;
}