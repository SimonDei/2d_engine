#ifndef _CIRCLE_HPP_
#define _CIRCLE_HPP_

#include <iostream>


namespace sde {
	template<typename T>
	class __declspec(dllexport) Circle {
		private:
			T m_center_x;
			T m_center_y;
			T m_radius;


		public:
			Circle() = default;
			Circle(const T& center_x, const T& center_y, const T& radius) {
				m_center_x = center_x;
				m_center_y = center_y;
				m_radius = radius;
			}
			~Circle() { };

			const T& get_x() const {
				return m_center_x;
			}
			const T& get_y() const {
				return m_center_y;
			}
			const T& get_radius() const {
				return m_radius;
			}

			void set_x(const T& x) {
				m_center_x = x;
			}
			void set_y(const T& y) {
				m_center_y = y;
			}
			void set_radius(const T& radius) {
				m_radius = radius;
			}

			void set_circle(const T& x, const T& y, const T& radius) {
				m_center_x = x;
				m_center_y = y;
				m_radius = radius;
			}

			const Circle<T>& get_circle() const {
				return this;
			}

			inline Circle<T>& operator=(const Circle<T>& other) {
				m_center_x = other.get_x();
				m_center_y = other.get_y();
				m_radius = other.get_radius();
				return *this;
			}
	};
}

/*template<typename T>
inline std::ostream& operator<<(std::ostream& stream, const sde::Circle<T>& other) {
	stream << other.get_x() << ", " << other.get_y() << ", " << other.get_radius();
	return stream;
}*/

#endif