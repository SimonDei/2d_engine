#include "Main.hpp"


void Main::init() {
	m_core.set_window_title("sde window");
	m_core.set_window_position(50, 50);
	m_core.create_window(1024, 768);

	m_core.set_keyboard_function([&]() { this->keyboard(); });
	m_core.set_update_function([&]() { this->update(); });
	m_core.set_render_function([&]() { this->render(); });

	m_core.start_game();
}

void Main::keyboard() {
	if (m_core.poll_events_timed()) {
		if (m_core.get_event_type() == sde::Event::EVENT_KEYDOWN) {
			switch (m_core.get_keycode()) {
				case sde::Keycode::KEYCODE_ESCAPE:
					m_core.close();
			}
		}
	}
}

void Main::update() {

}

void Main::render() {
	m_renderer.clear(0, 0, 0);

	m_renderer.draw_filled_circle(200.0f, 200.0f, 50.0f, 255, 0, 0);

	m_renderer.display();
}