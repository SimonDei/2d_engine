#ifndef _DISPLAYFLAGS_HPP_
#define _DISPLAYFLAGS_HPP_


namespace sde {
	enum class DisplayFlags : int {
		DISPLAY_WINDOWED = 1 << 0,
		DISPLAY_FULLSCREEN = 1 << 1,
		DISPLAY_RESIZABLE = 1 << 4,
		DISPLAY_FRAMELESS = 1 << 5,
		DISPLAY_FULLSCREEN_WINDOW = 1 << 9,
		DISPLAY_MINIMIZED = 1 << 10,
		DISPLAY_MAXIMIZED = 1 << 13
	};
}

#endif