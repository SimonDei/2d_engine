#include "Core.hpp"


namespace sde {
	Core::Core() : Core("sde window") {
	}

	Core::Core(const std::string& name) {
		al_set_app_name(name.c_str());
		al_set_new_window_title(name.c_str());

		al_init();
		al_init_image_addon();
		al_init_acodec_addon();
		al_init_font_addon();
		al_init_ttf_addon();
		al_init_native_dialog_addon();
		al_init_primitives_addon();

		al_install_keyboard();
		al_install_audio();

		al_reserve_samples(1);

		m_queue = al_create_event_queue();

		al_init_timeout(&m_timeout, 1.0 / 60.0);

		m_running = true;
	}

	Core::Core(const std::string& name, unsigned int width, unsigned int height) : Core(name) {
		m_display.create_display(width, height);

		al_register_event_source(m_queue, al_get_display_event_source(m_display.get_display()));
		al_register_event_source(m_queue, al_get_keyboard_event_source());
	}

	void Core::set_window_title(const std::string& name) const {
		al_set_app_name(name.c_str());
		al_set_new_window_title(name.c_str());
	}

	void Core::set_window_position(unsigned int x, unsigned int y) const {
		m_display.set_position(x, y);
	}

	void Core::create_window(unsigned int width, unsigned int height) {
		m_display.create_display(width, height);

		al_register_event_source(m_queue, al_get_display_event_source(m_display.get_display()));
		al_register_event_source(m_queue, al_get_keyboard_event_source());
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

	bool Core::is_event_in_queue() {
		m_has_event = al_wait_for_event_until(m_queue, &m_event, &m_timeout);
		if (m_event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			m_running = false;
		}
		// TODO: update Methode Platz finden
		m_updater.update();
		return m_has_event;
	}

	const Keycode& Core::get_keycode() const {
		return static_cast<Keycode>(m_event.keyboard.keycode);
	}

	Assets& Core::get_assets() {
		return m_assets;
	}

	const Display& Core::get_display() const {
		return m_display;
	}

	const Disposer& Core::get_disposer() const {
		return m_disposer;
	}

	const Updater& Core::get_updater() const {
		return m_updater;
	}

	void Core::wait(int ms) const {
		std::this_thread::sleep_for(std::chrono::milliseconds(ms));
	}

	void Core::close() {
		m_running = false;
	}

	Core::~Core() {
		m_assets.dispose();
		m_disposer.dispose();
		m_display.dispose();
		al_destroy_event_queue(m_queue);
	}
}
