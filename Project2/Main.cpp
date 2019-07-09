#include "Main.hpp"


void Main::init() {
	m_core.set_window_title("sde window");
	m_core.set_window_position(50, 50);
	m_core.create_window(1024, 768);
	
	m_display_width = m_core.get_display().get_width();
	m_display_height = m_core.get_display().get_height();
	
	m_assets.load_font("arial", "res/arial.ttf", 36);
	m_assets.load_texture("ball", "res/ball.tga");
	m_assets.load_texture("paddle1", "res/paddle1.tga");
	m_assets.load_texture("paddle2", "res/paddle2.tga");

	m_ball.set_texture(m_assets.get_texture("ball"));
	m_ball.set_position(m_display_width / 2.0f - m_ball.get_width() / 2.0f,
						m_display_height / 2.0f - m_ball.get_height() / 2.0f);
	
	m_paddle1.set_texture(m_assets.get_texture("paddle1"));
	m_paddle1.set_position(30.0f,
						   m_display_height / 2.0f - m_paddle1.get_height() / 2.0f);

	m_paddle2.set_texture(m_assets.get_texture("paddle2"));
	m_paddle2.set_position(m_display_width - m_paddle2.get_width() - 50.0f,
						   m_display_height / 2.0f - m_paddle2.get_height() / 2.0f);

	if (sde::rand::get_random_number(0, 1) == 0) m_ball_velocity.invert_x();
	if (sde::rand::get_random_number(0, 1) == 0) m_ball_velocity.invert_y();

	//m_camera.set_auto_apply(true);
	//m_renderer.set_camera(&m_camera);

	m_core.set_paused(true);

	while (m_core.is_running()) {
		keyboard();
		update();
		render();
	}
}

void Main::keyboard() {
	if (m_core.poll_events_timed()) {
		switch (m_core.get_event_type()) {
			case sde::Event::EVENT_KEYDOWN:
				switch (m_core.get_keycode()) {
					case sde::Keycode::KEYCODE_SPACE:
						m_core.set_paused(false);
						break;
					case sde::Keycode::KEYCODE_W:
						m_paddle_down = true;
						break;
					case sde::Keycode::KEYCODE_S:
						m_paddle_up = true;
						break;
				}
				break;
			case sde::Event::EVENT_KEYUP:
				switch (m_core.get_keycode()) {
					case sde::Keycode::KEYCODE_W:
						m_paddle_down = false;
						break;
					case sde::Keycode::KEYCODE_S:
						m_paddle_up = false;
						break;
				}
				break;
		}
	}
}

void Main::update() {
	if (!(m_core.is_paused())) {
		//========================
		//===     MOVEMENT     ===
		//========================
		if (m_paddle_up) {
			m_paddle1.add_y(m_paddle_velocity * sde::time::get_frame_time() * 25.0f);
		}
		if (m_paddle_down) {
			m_paddle1.add_y(-m_paddle_velocity * sde::time::get_frame_time() * 25.0f);
		}
		m_ball.add_position(m_ball_velocity.get_x() * sde::time::get_frame_time() * 25.0f,
							m_ball_velocity.get_y() * sde::time::get_frame_time() * 25.0f);
		if (m_ball.get_y() < m_paddle2.get_y()) {
			m_paddle2.add_y(-m_paddle_velocity * sde::time::get_frame_time() * 25.0f);
		}
		if (m_ball.get_y() > m_paddle2.get_y() + m_paddle2.get_height()) {
			m_paddle2.add_y(m_paddle_velocity * sde::time::get_frame_time() * 25.0f);
		}
		//=========================
		//===     COLLISION     ===
		//=========================
		if (sde::math::collision_rect_rect(m_paddle1.get_x(), m_paddle1.get_y(), m_paddle1.get_width(), m_paddle1.get_height(),
										   m_ball.get_x(), m_ball.get_y(), m_ball.get_width(), m_ball.get_height())) {
			m_ball_velocity.invert_x();
		}
		if (sde::math::collision_rect_rect(m_paddle2.get_x(), m_paddle2.get_y(), m_paddle2.get_width(), m_paddle2.get_height(),
										   m_ball.get_x(), m_ball.get_y(), m_ball.get_width(), m_ball.get_height())) {
			m_ball_velocity.invert_x();
		}
		if (m_ball.get_y() - m_ball.get_height() < 0.0f) {
			m_ball_velocity.invert_y();
		}
		if (m_ball.get_y() > m_display_height) {
			m_ball_velocity.invert_y();
		}
		if (m_ball.get_x() + m_ball.get_width() < 0.0f) {
			m_player2_score++;
			m_ball_reset = true;
			m_core.set_paused(true);
		}
		if (m_ball.get_x() > m_display_width) {
			m_player1_score++;
			m_ball_reset = true;
			m_core.set_paused(true);
		}
		//==========================
		//===     RESET GAME     ===
		//==========================
		if (m_ball_reset) {
			m_ball.set_position(m_display_width / 2.0f - m_ball.get_width() / 2.0f, m_display_height / 2.0 - m_ball.get_height() / 2.0f);
			if (sde::rand::get_random_number(0, 1) == 0) m_ball_velocity.invert_x();
			if (sde::rand::get_random_number(0, 1) == 0) m_ball_velocity.invert_y();
			m_ball_reset = false;
		}
	}

	//m_camera.add_offset_x(0.01f);
}

void Main::render() {
	m_renderer.clear(0, 0, 0);

	m_renderer.draw_circle(100.0f, 100.0f, 50.0f);
	
	/*m_renderer.draw_line(m_display_width / 2.0f, 0.0f, m_display_width / 2.0f, m_display_height);
	m_renderer.draw_circle(m_display_width / 2.0f, m_display_height / 2.0f, 50.0f);

	m_renderer.draw_text(std::to_string(m_player1_score), m_assets.get_font("arial"), 50.0f, 20.0f);
	m_renderer.draw_text(std::to_string(m_player2_score), m_assets.get_font("arial"), m_display_width - 100.0f, 20.0f);

	m_renderer.draw_object(m_paddle1);
	m_renderer.draw_object(m_paddle2);
	m_renderer.draw_object(m_ball);*/

	m_renderer.display();
}

void Main::dispose() {
}