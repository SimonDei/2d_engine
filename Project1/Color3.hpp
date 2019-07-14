#ifndef _COLOR3_HPP_
#define _COLOR3_HPP_


namespace sde {
	template<typename T>
	class Color3 {
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
			~Color3() = default;

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

			ALLEGRO_COLOR get_al_color() const {
				if (std::is_same<T, unsigned char>::value) {
					return al_map_rgb(m_red, m_green, m_blue);
				}
				if (std::is_same<T, float>::value) {
					return al_map_rgb_f(m_red, m_green, m_blue);
				}
				return al_map_rgb(255, 255, 255);
			}

			std::string to_string() const {
				return std::to_string(m_red) + ", " + std::to_string(m_green) + ", " + std::to_string(m_blue);
			}
	};
}

#endif