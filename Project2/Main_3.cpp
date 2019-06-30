#include <sd_engine.hpp>


int main_3() {
	sde::Core core{ "sde window", 1024, 768 };
	//core.set_fps(60.0f);
	
	sde::Renderer renderer{ };

	const float display_width{ core.get_display().get_width() };
	const float display_height{ core.get_display().get_height() };

	sde::Assets assets{ core.get_assets() };
	assets.load_texture("ball", "res/ball.tga");
	assets.load_texture("paddle1", "res/paddle1.tga");
	assets.load_texture("paddle2", "res/paddle2.tga");
	assets.load_font("arial", "res/arial.ttf", 26);

	sde::Sprite ball{ assets.get_texture("ball") };
	ball.set_position(display_width / 2.0f - ball.get_half_width(), display_height / 2.0f - ball.get_half_height());

	sde::Sprite paddle1{ assets.get_texture("paddle1") };
	paddle1.set_position(50.0f, display_height / 2.0f - paddle1.get_half_height());
	
	sde::Sprite paddle2{ assets.get_texture("paddle2") };
	paddle2.set_position(display_width - 50.0f - paddle2.get_width(), display_height / 2.0f - paddle2.get_half_height());

	core.set_paused(true);

	bool reset_ball{ false };
	bool paddle_up{ false };
	bool paddle_down{ false };

	unsigned int player_1_score{ 0 };
	unsigned int player_2_score{ 0 };

	const float paddle_velocity{ 10.0f };

	sde::Vector2<float> ball_velocity{ 12.5f, 12.5f };
	if (sde::rand::get_random_number(0, 1) == 0) ball_velocity.invert_x();
	if (sde::rand::get_random_number(0, 1) == 0) ball_velocity.invert_y();
	
	while (core.is_running()) {
		if (core.poll_events_timed()) {
			switch (core.get_event_type()) {
				case sde::Event::EVENT_KEYDOWN:
					switch (core.get_keycode()) {
						case sde::Keycode::KEYCODE_W:
							paddle_down = true;
							break;
						case sde::Keycode::KEYCODE_S:
							paddle_up = true;
							break;
						case sde::Keycode::KEYCODE_SPACE:
							core.toggle_paused();
							break;
					}
					break;
				case sde::Event::EVENT_KEYUP:
					switch (core.get_keycode()) {
						case sde::Keycode::KEYCODE_W:
							paddle_down = false;
							break;
						case sde::Keycode::KEYCODE_S:
							paddle_up = false;
							break;
					}
					break;
			}
		}
		if (!core.is_paused()) {
			if (ball.get_y() < paddle2.get_y()) {
				paddle2.add_y(-paddle_velocity * core.get_frame_time() * 25.0f);
			} else if (ball.get_bottom_right().get_y() > paddle2.get_bottom_left().get_y()) {
				paddle2.add_y(paddle_velocity * core.get_frame_time() * 25.0f);
			}
			if (sde::math::collision_rect_rect(paddle1.get_x(), paddle1.get_y(), paddle1.get_width(), paddle1.get_height(), ball.get_x(), ball.get_y(), ball.get_width(), ball.get_height()) ||
				sde::math::collision_rect_rect(paddle2.get_x(), paddle2.get_y(), paddle2.get_width(), paddle2.get_height(), ball.get_x(), ball.get_y(), ball.get_width(), ball.get_height())) {
				ball_velocity.invert_x();
			}
			if (ball.get_bottom_left().get_y() < 0.0f || ball.get_top_left().get_y() > display_height) {
				ball_velocity.invert_y();
			}
			if (ball.get_x() > display_width) {
				player_1_score++;
				reset_ball = true;
				core.toggle_paused();
			}
			if (ball.get_top_right().get_x() < 0.0f) {
				player_2_score++;
				reset_ball = true;
				core.toggle_paused();
			}
			if (reset_ball) {
				ball.set_position(display_width / 2.0f - ball.get_half_width(), display_height / 2.0f - ball.get_half_height());
				if (sde::rand::get_random_number(0, 1) == 0) ball_velocity.invert_x();
				if (sde::rand::get_random_number(0, 1) == 0) ball_velocity.invert_y();
				reset_ball = false;
			}
			ball.add_position(ball_velocity.get_x() * core.get_frame_time() * 25.0f, ball_velocity.get_y() * core.get_frame_time() * 25.0f);
			if (paddle_up) {
				paddle1.add_y(paddle_velocity * core.get_frame_time() * 25.0f);
			} else if (paddle_down) {
				paddle1.add_y(-paddle_velocity * core.get_frame_time() * 25.0f);
			}
		}

		renderer.clear(0, 0, 0);

		renderer.draw_line(display_width / 2.0f, 0.0f, display_width / 2.0f, display_height);
		renderer.draw_circle(display_width / 2.0f, display_height / 2.0f, 50.0f);

		renderer.draw_text(std::to_string(core.get_fps()), assets.get_font("arial"), 100.0f, 20.0f);
		renderer.draw_text(std::to_string(player_1_score), assets.get_font("arial"), 50.0f, 20.0f);
		renderer.draw_text(std::to_string(player_2_score), assets.get_font("arial"), display_width - 100.0f, 20.0f);
		
		renderer.draw_object(ball);
		renderer.draw_object(paddle1);
		renderer.draw_object(paddle2);
		
		renderer.display();
	}

	return SDE_SUCCESS;
}