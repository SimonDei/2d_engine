#include "Core.h"


namespace sde {
	Core::Core() : Core("sde window") {
	}

	Core::Core(const std::string& name) {
		al_set_app_name(name.c_str());

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
		create_display(width, height);
	}

	void Core::create_display(unsigned int width, unsigned int height) {
		m_display.create_display(width, height);

		al_register_event_source(m_queue, al_get_display_event_source(m_display.get_display()));
		al_register_event_source(m_queue, al_get_keyboard_event_source());
	}

	void Core::add_updateable(const Updateable& updateable) {
		m_updater.add_updateable(updateable);
	}

	void Core::add_disposable(std::shared_ptr<Disposable> disposable) {
		m_disposer.add_disposable(disposable);
	}

	void Core::set_mouse_visible(bool visible) {
		if (visible) {
			al_show_mouse_cursor(m_display.get_display());
		} else {
			al_hide_mouse_cursor(m_display.get_display());
		}
	}

	void Core::set_mouse_grabbed(bool grabbed) const {
		set_mouse_grabbed(grabbed);
	}

	bool Core::is_event_in_queue() {
		m_has_event = al_wait_for_event_until(m_queue, &m_event, &m_timeout);
		if (m_event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			m_running = false;
		}
		return m_has_event;
	}

	const Keycode& Core::get_keycode() const {
		return (Keycode) m_event.keyboard.keycode;
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
		m_disposer.dispose();
		al_destroy_event_queue(m_queue);
	}
}
