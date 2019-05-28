#pragma once

#include <iostream>


namespace sde {
	template<typename T>
	class Color4 {
		private:
			T m_red;
			T m_green;
			T m_blue;
			T m_alpha;

		public:
			Color4() = default;
			Color4(T red, T green, T blue, T alpha) {
				m_red = red;
				m_green = green;
				m_blue = blue;
				m_alpha = alpha;
			}
			~Color4() { }

			const T& get_red() const {
				return m_red;
			}
			const T& get_green() const {
				return m_green;
			}
			const T& get_blue() const {
				return m_blue;
			}
			const T& get_alpha() const {
				return m_alpha;
			}

			void set_color(const T& r, const T& g, const T& b, const T& a) {
				m_red = r;
				m_green = g;
				m_blue = b;
				m_alpha = a;
			}

			const Color4<T>& get_color() const {
				return this;
			}

			const ALLEGRO_COLOR get_al_color() const {
				return al_map_rgba(m_red, m_green, m_blue, m_alpha);
			}
	};
}

template<typename T>
inline std::ostream& operator<<(std::ostream& stream, const sde::Color4<T>& other) {
	stream << other.get_red() << ", " << other.get_green() << ", " << other.get_blue() << ", " << other.get_alpha();
	return stream;
}