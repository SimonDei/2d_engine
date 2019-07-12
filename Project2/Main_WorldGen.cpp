#include "Main_WorldGen.hpp"


void Main_WorldGen::init() {
	m_core.set_window_position(50, 50);
	m_core.set_window_title("sde window");
	m_core.create_window(1024, 768);

	m_map.load_texture("res/image.png");
	m_map.lock();

	m_camera.set_auto_apply(true);
	m_camera.set_camera_bounds(m_core.get_display().get_width(), m_core.get_display().get_height());

	m_renderer.set_camera(&m_camera);

	while (m_core.is_running()) {
		keyboard();
		update();
		render();
	}
}

void Main_WorldGen::keyboard() {
	while (m_core.poll_events_timed()) {
		
	}
}

void Main_WorldGen::update() {
	sde::time::update();
	float delta = sde::math::clamp(sde::time::get_frame_time(), 0.0145f, 0.0175f);
	al_get_keyboard_state(&state);

	if (al_key_down(&state, (int) sde::Keycode::KEYCODE_W)) {
		m_camera.add_y(200.0f * sde::time::get_frame_time());
	}
	if (al_key_down(&state, (int)sde::Keycode::KEYCODE_S)) {
		m_camera.add_y(-200.0f * sde::time::get_frame_time());
		//if (m_camera.get_offset_y() >= 0.0f) {
		//	m_camera.set_offset_y(0.0f);
		//}
	}
	if (al_key_down(&state, (int)sde::Keycode::KEYCODE_A)) {
		m_camera.add_x(200.0f * sde::time::get_frame_time());
	}
	if (al_key_down(&state, (int)sde::Keycode::KEYCODE_D)) {
		m_camera.add_x(-200.0f * sde::time::get_frame_time());
		//if (m_camera.get_offset_x() >= 0.0f) {
		//	m_camera.set_offset_x(0.0f);
		//}
	}
}

void Main_WorldGen::render() {
	draws = 0;

	m_renderer.clear(0, 0, 0, 255);
	
	for (int y = -m_camera.get_y() / 16; y < 768 / 16; y++) {
		for (int x = -m_camera.get_x() / 16; x < 1024 / 16; x++) {
			if (sde::math::collision_rect_rect(sde::Rectangle<float>{ x * 16.0f, y * 16.0f, 16.0f, 16.0f },
											   m_camera.get_camera_rect())) {
				switch (m_map.get_pixel_color(x, y)) {
					case 0x56B000FF:
						m_renderer.draw_filled_rectangle(x * 16, y * 16, 16, 16, 86, 176, 0);
						draws++;
						break;
					case 0xC2B280FF:
						m_renderer.draw_filled_rectangle(x * 16, y * 16, 16, 16, 194, 178, 128);
						draws++;
						break;
					case 0x006994FF:
						m_renderer.draw_filled_rectangle(x * 16, y * 16, 16, 16, 0, 105, 148);
						draws++;
						break;
					case 0xCA6700FF:
						m_renderer.draw_filled_rectangle(x * 16, y * 16, 16, 16, 202, 103, 0);
						draws++;
						break;
					default:
						break;
				}
			}
		}
	}

	m_renderer.display();

	std::cout << draws << std::endl;
}

void Main_WorldGen::dispose() {
	m_map.unlock();
	m_map.dispose();
}