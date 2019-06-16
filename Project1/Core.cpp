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
		al_init_timeout(&m_timeout, 1.0 / m_fps);
		
		m_old_frame_time = al_get_time();
		m_random.seed(std::chrono::system_clock::now().time_since_epoch().count());

		m_running = true;
	}

	Core::Core(const std::string& name, unsigned int width, unsigned int height) : Core(name) {
		m_display.create_display(width, height);

		al_set_clipping_rectangle(0, 0, width, height);

		al_register_event_source(m_queue, al_get_display_event_source(m_display.get_display()));
		al_register_event_source(m_queue, al_get_keyboard_event_source());
	}

	void Core::set_window_title(const std::string& name) const {
		if (m_running) {
			return;
		}
		al_set_app_name(name.c_str());
		al_set_new_window_title(name.c_str());
	}

	void Core::set_window_position(unsigned int x, unsigned int y) const {
		if (m_running) {
			return;
		}
		m_display.set_position(x, y);
	}

	void Core::create_window(unsigned int width, unsigned int height) {
		if (m_running) {
			return;
		}
		m_display.create_display(width, height);

		al_register_event_source(m_queue, al_get_display_event_source(m_display.get_display()));
		al_register_event_source(m_queue, al_get_keyboard_event_source());
	}

	void Core::set_fps(float fps) {
		m_fps = static_cast<double>(fps);

		al_init_timeout(&m_timeout, 1.0 / m_fps);
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

	void Core::toggle_paused() {
		m_paused = !m_paused;
	}

	double Core::get_game_time() const {
		return al_get_time();
	}

	double Core::get_frame_time() const {
		return m_delta_frame_time;
	}

	double Core::get_fps() const {
		return m_current_fps;
	}

	int Core::get_random_number(int min, int max) {
		std::uniform_int_distribution<int> dis(min, max);
		return dis(m_random);
	}

	const Keycode Core::get_keycode() const {
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

	Updater& Core::get_updater() {
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
		m_assets.dispose();
		m_display.dispose();
		al_destroy_timer(m_timer);
		al_destroy_event_queue(m_queue);
	}
}
