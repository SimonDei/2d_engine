#pragma once

#include <iostream>


namespace sde {
	template<typename T>
	class Vector3 {
		private:
			T m_val1;
			T m_val2;
			T m_val3;

		public:
			Vector3() = default;
			Vector3(T val1, T val2, T val3) {
				m_val1 = val1;
				m_val2 = val2;
				m_val3 = val3;
			}
			~Vector3() { }

			const T& get_x() const {
				return m_val1;
			}
			const T& get_y() const {
				return m_val2;
			}
			const T& get_z() const {
				return m_val3;
			}

			void set_x(const T& x) {
				m_val1 = x;
			}
			void set_y(const T& y) {
				m_val2 = y;
			}
			void set_z(const T& z) {
				m_val3 = z;
			}

			void set_vector(const T& x, const T& y, const T& z) {
				m_val1 = x;
				m_val2 = y;
				m_val3 = z;
			}

			void add_x(const T& x) {
				m_val1 += x;
			}
			void add_y(const T& y) {
				m_val2 += y;
			}
			void add_z(const T& z) {
				m_val3 += z;
			}

			void multiply(const T& x, const T& y, const T& z) {
				m_val1 *= x;
				m_val2 *= y;
				m_val3 *= z;
			}
			void divide(const T& x, const T& y, const T& z) {
				m_val1 /= x;
				m_val2 /= y;
				m_val3 /= z;
			}

			const Vector3<T>& get_vector() const {
				return this;
			}

			inline Vector3<T>& operator=(const Vector3<T>& other) {
				m_val1 = other.get_x();
				m_val2 = other.get_y();
				m_val3 = other.get_z();
				return *this;
			}
	};
}

template<typename T>
inline std::ostream& operator<<(std::ostream& stream, const sde::Vector3<T>& other) {
	stream << other.get_x() << ", " << other.get_y() << ", " << other.get_z();
	return stream;
}