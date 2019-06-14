#ifndef _EVENTS_HPP_
#define _EVENTS_HPP_

#include <allegro5/allegro.h>


namespace sde {
	enum class Event : int {
		EVENT_NONE = 0,

		EVENT_KEYDOWN = 10,
		EVENT_KEYUP = 12,

		EVENT_MOUSE_BUTTON_DOWN = 21,
		EVENT_MOUSE_BUTTON_UP = 22,
		EVENT_MOUSE_GAIN_FOCUS = 23,
		EVENT_MOUSE_LOSE_FOCUS = 24,

		EVENT_TIMER_EXPIRED = 30,

		EVENT_APP_RESIZE = 41,
		EVENT_APP_CLOSE = 42,
	};
}

#endif