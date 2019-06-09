#pragma once

#include <iostream>


namespace sde {
	template<typename T>
	class __declspec(dllexport) Vector3 {
		private:
			T m_x;
			T m_y;
			T m_z;


		public:
			Vector3() = default;
			Vector3(const T& val1, const T& val2, const T& val3) {
				m_x = val1;
				m_y = val2;
				m_z = val3;
			}
			~Vector3() { }

			const T& get_x() const {
				return m_x;
			}
			const T& get_y() const {
				return m_y;
			}
			const T& get_z() const {
				return m_z;
			}

			void set_x(const T& x) {
				m_x = x;
			}
			void set_y(const T& y) {
				m_y = y;
			}
			void set_z(const T& z) {
				m_z = z;
			}

			void set_vector(const T& x, const T& y, const T& z) {
				m_x = x;
				m_y = y;
				m_z = z;
			}

			void add_x(const T& x) {
				m_x += x;
			}
			void add_y(const T& y) {
				m_y += y;
			}
			void add_z(const T& z) {
				m_z += z;
			}

			void multiply(const T& x, const T& y, const T& z) {
				m_x *= x;
				m_y *= y;
				m_z *= z;
			}
			void divide(const T& x, const T& y, const T& z) {
				m_x /= x;
				m_y /= y;
				m_z /= z;
			}

			const Vector3<T>& get_vector() const {
				return this;
			}

			inline Vector3<T>& operator=(const Vector3<T>& other) {
				m_x = other.get_x();
				m_y = other.get_y();
				m_z = other.get_z();
				return *this;
			}
	};
}

/*template<typename T>
inline std::ostream& operator<<(std::ostream& stream, const sde::Vector3<T>& other) {
	stream << other.get_x() << ", " << other.get_y() << ", " << other.get_z();
	return stream;
}*/