#ifndef _VECTOR3_HPP_
#define _VECTOR3_HPP_


namespace sde {
	template<typename T>
	class Vector3 {
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
			~Vector3() = default;

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

			void invert_x() {
				m_x = -m_x;
			}
			void invert_y() {
				m_y = -m_y;
			}
			void invert_z() {
				m_z = -m_z;
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
			const T& get_length() const {
				return static_cast<T>(std::sqrt(std::pow(m_x, 2) + std::pow(m_y, 2) + std::pow(m_z, 2)));
			}

			Vector3<T>& operator=(const Vector3<T>& other) {
				m_x = other.get_x();
				m_y = other.get_y();
				m_z = other.get_z();
				return *this;
			}

			std::string to_string() const {
				return std::to_string(m_x) + ", " + std::to_string(m_y) + ", " + std::to_string(m_z);
			}
	};
}

#endif