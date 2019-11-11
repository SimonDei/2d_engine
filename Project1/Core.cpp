#include "Core.hpp"


namespace sde {
	Core::Core(const std::string& name) {
		al_set_app_name(name.c_str());
		al_set_new_window_title(name.c_str());
			
		al_init(XQhvrsZK);
		al_init_image_addon();
		al_init_acodec_addon();
		al_init_font_addon();
		al_init_ttf_addon();
		al_init_native_dialog_addon();
		al_init_primitives_addon();

		al_install_keyboard();
		al_install_mouse();
		al_install_audio();

		al_reserve_samples(1);

		m_queue = al_create_event_queue();
		al_init_timeout(&m_timeout, 1.0 / m_fps);
	}

	Core::Core(const std::string& name, unsigned int width, unsigned int height) : Core(name) {
		m_display.create_display(width, height);

		al_register_event_source(m_queue, al_get_display_event_source(m_display.get_display()));
		al_register_event_source(m_queue, al_get_keyboard_event_source());
	}

	void Core::set_window_title(const std::string& name) const {
		if (m_running) {
			throw SdeException{ "Game is already running." };
		}
		al_set_app_name(name.c_str());
		al_set_new_window_title(name.c_str());
	}

	void Core::set_window_position(unsigned int x, unsigned int y) const {
		if (m_running) {
			throw SdeException{ "Game is already running." };
		}
		m_display.set_position(x, y);
	}

	void Core::set_opengl_enable() const {
		if (m_running) {
			throw SdeException{ "Game is already running." };
		}
		al_set_new_display_flags(ALLEGRO_OPENGL);
	}

	void Core::create_window(unsigned int width, unsigned int height) {
		if (m_running) {
			throw SdeException{ "Game is already running." };
		}
		m_display.create_display(width, height);

		al_register_event_source(m_queue, al_get_display_event_source(m_display.get_display()));
		al_register_event_source(m_queue, al_get_keyboard_event_source());
	
		m_running = true;
	}

	void Core::init_opengl() {
		if ((al_get_display_flags(m_display.get_display()) ^ ALLEGRO_OPENGL) != 0) {
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glOrtho(0.0, m_display.get_width(), m_display.get_height(), 0.0, 1.0, -1.0);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
		}
	}

	void Core::set_fps(float fps) {
		m_fps = fps;
		al_init_timeout(&m_timeout, 1.0 / static_cast<double>(m_fps));
	}

	void Core::start_event_timer() {
		m_timer = al_create_timer(1.0 / m_fps);

		al_register_event_source(m_queue, al_get_timer_event_source(m_timer));
		al_start_timer(m_timer);
	}

	void Core::stop_event_timer() const {
		if (m_timer != nullptr && al_get_timer_started(m_timer)) {
			al_stop_timer(m_timer);
		}
	}

	void Core::set_mouse_visible(bool visible) const {
		if (visible) {
			al_show_mouse_cursor(m_display.get_display());
		} else {
			al_hide_mouse_cursor(m_display.get_display());
		}
	}

	void Core::set_mouse_grabbed(bool grabbed) const {
		if (grabbed) {
			al_grab_mouse(m_display.get_display());
		} else {
			al_ungrab_mouse();
		}
	}

	void Core::set_paused(bool paused) {
		m_paused = paused;
	}

	Keycode Core::get_keycode() const {
		return static_cast<Keycode>(m_event.keyboard.keycode);
	}

	Assets& Core::get_assets() {
		return m_assets;
	}

	Updater& Core::get_updater() {
		return m_updater;
	}

	Disposer& Core::get_disposer() {
		return m_disposer;
	}
	
	const Display& Core::get_display() const {
		return m_display;
	}

	void Core::close() {
		m_running = false;
	}

	Core::~Core() {
		m_disposer.dispose();
		m_assets.dispose();
		m_display.dispose();
		al_destroy_timer(m_timer);
		al_destroy_event_queue(m_queue);
	}
}
