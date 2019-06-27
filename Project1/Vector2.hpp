#ifndef _VECTOR2_HPP_
#define _VECTOR2_HPP_

#include <iostream>


namespace sde {
	template<typename T>
	class Vector2 {
		private:
			T m_x;
			T m_y;


		public:
			Vector2() = default;
			Vector2(const T& val1, const T& val2) {
				m_x = val1;
				m_y = val2;
			}
			~Vector2() { }

			const T& get_x() const {
				return m_x;
			}
			const T& get_y() const {
				return m_y;
			}

			void set_x(const T& x) {
				m_x = x;
			}
			void set_y(const T& y) {
				m_y = y;
			}

			void set_vector(const T& x, const T& y) {
				m_x = x;
				m_y = y;
			}

			void invert_x() {
				m_x = -m_x;
			}
			void invert_y() {
				m_y = -m_y;
			}

			void add_x(const T& x) {
				m_x += x;
			}
			void add_y(const T& y) {
				m_y += y;
			}

			void multiply(const T& x, const T& y) {
				m_x *= x;
				m_y *= y;
			}
			void divide(const T& x, const T& y) {
				m_x /= x;
				m_y /= y;
			}
			const T& get_length() const {
				return static_cast<T>(std::sqrt(std::pow(m_x, 2) + std::pow(m_y, 2)));
			}

			const Vector2<T>& get_vector() const {
				return this;
			}

			inline Vector2<T>& operator=(const Vector2<T>& other) {
				m_x = other.get_x();
				m_y = other.get_y();
				return *this;
			}
	};
}

/*template<typename T>
inline std::ostream& operator<<(std::ostream& stream, const sde::Vector2<T>& other) {
	stream << other.get_x() << ", " << other.get_y();
	return stream;
}*/

#endif