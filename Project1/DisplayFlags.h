#pragma once

#include <allegro5/allegro.h>


namespace sde {
	enum DisplayFlags {
		DISPLAY_WINDOWED = 1 << 0,
		DISPLAY_FULLSCREEN = 1 << 1,
		DISPLAY_RESIZABLE = 1 << 4,
		DISPLAY_FRAMELESS = 1 << 5,
		DISPLAY_FULLSCREEN_WINDOW = 1 << 9,
		DISPLAY_MINIMIZED = 1 << 10,
		DISPLAY_MAXIMIZED = 1 << 13
	};
}