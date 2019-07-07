#ifndef _MOUSE_HPP_
#define _MOUSE_HPP-

#include <allegro5/allegro.h>

#include "Vector2.hpp"


namespace sde {
	namespace mouse {
		namespace {
			ALLEGRO_MOUSE_STATE m_mouse_state{ };
		}

		static float get_mouse_x() {
			al_get_mouse_state(&m_mouse_state);
			return static_cast<float>(m_mouse_state.x);
		}

		static float get_mouse_y() {
			al_get_mouse_state(&m_mouse_state);
			return static_cast<float>(m_mouse_state.y);
		}

		static const Vector2<float> get_mouse_position() {
			al_get_mouse_state(&m_mouse_state);
			return Vector2<float>{ static_cast<float>(m_mouse_state.x), static_cast<float>(m_mouse_state.y) };
		}
	}
}

#endif