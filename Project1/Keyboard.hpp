#ifndef _KEYBOARD_HPP_
#define _KEYBOARD_HPP-

#include <allegro5/allegro.h>

#include "Keycodes.hpp"


namespace sde {
	namespace keyboard {
		namespace {
			ALLEGRO_KEYBOARD_STATE m_keystate{ };
		}

		static bool is_key_down(const Keycode& keycode) {
			al_get_keyboard_state(&m_keystate);
			if (al_key_down(&m_keystate, static_cast<int>(keycode))) {
				return true;
			}
			return false;
		}
	}
}

#endif