#pragma once

#include <iostream>


namespace sde {
	template<typename T>
	class Vector2 {
		private:
			T m_val1;
			T m_val2;

		public:
			Vector2() = default;
			Vector2(T val1, T val2) {
				m_val1 = val1;
				m_val2 = val2;
			}
			~Vector2() { }

			const T& get_x() const {
				return m_val1;
			}
			const T& get_y() const {
				return m_val2;
			}

			void set_x(const T& x) {
				m_val1 = x;
			}
			void set_y(const T& y) {
				m_val2 = y;
			}

			void set_vector(const T& x, const T& y) {
				m_val1 = x;
				m_val2 = y;
			}

			void add_x(const T& x) {
				m_val1 += x;
			}
			void add_y(const T& y) {
				m_val2 += y;
			}

			void multiply(const T& x, const T& y) {
				m_val1 *= x;
				m_val2 *= y;
			}
			void divide(const T& x, const T& y) {
				m_val1 /= x;
				m_val2 /= y;
			}

			const Vector2<T>& get_vector() const {
				return this;
			}

			inline Vector2<T>& operator=(const Vector2<T>& other) {
				m_val1 = other.get_x();
				m_val2 = other.get_y();
				return *this;
			}
	};
}

template<typename T>
inline std::ostream& operator<<(std::ostream& stream, const sde::Vector2<T>& other) {
	stream << other.get_x() << ", " << other.get_y();
	return stream;
}