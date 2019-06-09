#pragma once

#include <iostream>


namespace sde {
	template<typename T>
	class __declspec(dllexport) Color3 {
		private:
			T m_red;
			T m_green;
			T m_blue;

		public:
			Color3() = default;
			Color3(T red, T green, T blue) {
				m_red = red;
				m_green = green;
				m_blue = blue;
			}
			~Color3() { }

			const T& get_red() const {
				return m_red;
			}
			const T& get_green() const {
				return m_green;
			}
			const T& get_blue() const {
				return m_blue;
			}

			void set_color(const T& r, const T& g, const T& b) {
				m_red = r;
				m_green = g;
				m_blue = b;
			}

			const Color3<T>& get_color() const {
				return this;
			}

			const ALLEGRO_COLOR get_al_color() const {
				return al_map_rgb(m_red, m_green, m_blue);
			}
	};
}

/*template<typename T>
inline std::ostream& operator<<(std::ostream& stream, const sde::Color3<T>& other) {
	stream << other.get_red() << ", " << other.get_green() << ", " << other.get_blue();
	return stream;
}*/
