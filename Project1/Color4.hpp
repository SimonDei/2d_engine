#ifndef _COLOR4_HPP_
#define _COLOR4_HPP_


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
			~Color4() = default;

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

			ALLEGRO_COLOR get_al_color() const {
				if (std::is_same<T, unsigned char>::value) {
					return al_map_rgba(m_red, m_green, m_blue, m_alpha);
				}
				if (std::is_same<T, float>::value) {
					return al_map_rgba_f(m_red, m_green, m_blue, m_alpha);
				}
				return al_map_rgba(255, 255, 255, 255);
			}

			istd::string to_string() const {
				return std::to_string(m_red) + ", " + std::to_string(m_green) + ", " + std::to_string(m_blue) + ", " + std::to_string(m_alpha);
			}
	};
}

#endif