#include "Main_2.hpp"


void Main_2::init() {
	m_core.set_window_title("sde snake");
	m_core.set_window_position(50, 50);
	m_core.create_window(1024, 768);

	m_display_width = m_core.get_display().get_width();
	m_display_height = m_core.get_display().get_height();

	m_assets.load_font("arial", "res/arial.ttf", 38);

	m_grid_width = (m_display_width / m_cell_size);
	m_grid_height = (m_display_height / m_cell_size);

	m_snake.set_rectangle(sde::rand::get_random_number(0.0f, m_grid_width) * m_cell_size,
						  sde::rand::get_random_number(0.0f, m_grid_height) * m_cell_size,
						  m_cell_size, m_cell_size);

	m_food.set_rectangle(sde::rand::get_random_number(0.0f, m_grid_width) * m_cell_size,
						 sde::rand::get_random_number(0.0f, m_grid_height) * m_cell_size,
						 m_cell_size, m_cell_size);

	while (m_core.is_running()) {
		keyboard();
		update();
		render();
	}
}

void Main_2::keyboard() {
	if (m_core.poll_events_timed()) {
		switch (m_core.get_event_type()) {
			case sde::Event::EVENT_KEYDOWN:
				switch (m_core.get_keycode()) {
					case sde::Keycode::KEYCODE_W:
						m_snake_velocity.set_vector(0.0f, -200.0f);
						break;
					case sde::Keycode::KEYCODE_S:
						m_snake_velocity.set_vector(0.0f, 200.0f);
						break;
					case sde::Keycode::KEYCODE_A:
						m_snake_velocity.set_vector(-200.0f, 0.0f);
						break;
					case sde::Keycode::KEYCODE_D:
						m_snake_velocity.set_vector(200.0f, 0.0f);
						break;
				}
				break;
		}
	}
}

void Main_2::update() {
	m_snake.add_position(m_snake_velocity.get_x() * m_core.get_frame_time(),
						 m_snake_velocity.get_y() * m_core.get_frame_time());
	if (sde::math::collision_rect_rect(m_snake, m_food)) {
		m_food.set_rectangle(sde::rand::get_random_number(0.0f, m_grid_width) * m_cell_size,
							 sde::rand::get_random_number(0.0f, m_grid_height) * m_cell_size,
							 m_cell_size, m_cell_size);
		m_snake.add_width(m_cell_size);
		m_player_score++;
	}
}

void Main_2::render() {
	m_renderer.clear(sde::color::BLACK);
	
	m_renderer.draw_filled_rectangle(m_snake, sde::Color3<unsigned char>{ 255, 0, 0 });
	m_renderer.draw_filled_rectangle(m_food, sde::Color3<unsigned char>{ 255, 255, 0 });

	m_renderer.draw_text(std::to_string(m_player_score), m_assets.get_font("arial"), 30.0f, 30.0f);

	m_renderer.display();
}

void Main_2::dispose() {
}