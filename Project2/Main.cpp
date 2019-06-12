#include <sd_engine.hpp>


int main() {
	sde::Core core{ "sde window", 1024, 768 };
	//core.set_fps(60.0f);
	
	sde::Renderer renderer;

	const float display_width = core.get_display().get_width();
	const float display_height = core.get_display().get_height();

	sde::Assets assets{ core.get_assets() };
	assets.load_texture("ball", "res/ball.png");
	assets.load_texture("paddle1", "res/paddle1.png");
	assets.load_texture("paddle2", "res/paddle2.png");
	assets.load_font("arial", "res/arial.ttf", 26);

	sde::Sprite ball{ assets.get_texture("ball") };
	ball.set_position(display_width / 2.0f - ball.get_half_width(), display_height / 2.0f - ball.get_half_height());

	sde::Sprite paddle1{ assets.get_texture("paddle1") };
	paddle1.set_position(50.0f, display_height / 2.0f - paddle1.get_half_height());
	
	sde::Sprite paddle2{ assets.get_texture("paddle2") };
	paddle2.set_position(display_width - 50.0f - paddle2.get_width(), display_height / 2.0f - paddle2.get_half_height());
	
	bool paddle_up = false;
	bool paddle_down = false;
	bool reset_ball = false;

	unsigned int player_1_score = 0;
	unsigned int player_2_score = 0;

	const float paddle_velocity = 10.0f;
	sde::Vector2<float> ball_velocity(12.5f, 12.5f);
	
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
		ball.add_position(ball_velocity.get_x() * core.get_frame_time() * 25.0f, ball_velocity.get_y() * core.get_frame_time() * 25.0f);
		if (paddle_up) {
			paddle1.add_y(paddle_velocity * core.get_frame_time() * 25.0f);
		} else if (paddle_down) {
			paddle1.add_y(-paddle_velocity * core.get_frame_time() * 25.0f);
		}
		if (sde::math::collision_rect_rect(paddle1.get_x(), paddle1.get_y(), paddle1.get_width(), paddle1.get_height(), ball.get_x(), ball.get_y(), ball.get_width(), ball.get_height()) ||
			sde::math::collision_rect_rect(paddle2.get_x(), paddle2.get_y(), paddle2.get_width(), paddle2.get_height(), ball.get_x(), ball.get_y(), ball.get_width(), ball.get_height())) {
			ball_velocity.invert_x();
		}
		if (ball.get_y() < 0.0f || ball.get_y() + ball.get_height() / 2.0f > display_height) {
			ball_velocity.invert_y();
		}
		if (ball.get_x() > display_width) {
			player_1_score++;
			reset_ball = true;
		}
		if (ball.get_x() - ball.get_width() < 0.0f) {
			player_2_score++;
			reset_ball = true;
		}
		if (reset_ball) {
			ball.set_position(display_width / 2.0f - ball.get_half_width(), display_height / 2.0f - ball.get_half_height());
			if (core.get_random_number(0, 1) == 0) { ball_velocity.invert_x(); }
			if (core.get_random_number(0, 1) == 0) { ball_velocity.invert_y(); }
			reset_ball = false;
		}

		renderer.clear(0, 0, 0);

		renderer.draw_line(display_width / 2.0f, 0.0f, display_width / 2.0f, display_height);
		renderer.draw_circle(display_width / 2.0f, display_height / 2.0f, 50.0f);

		renderer.draw_text(std::to_string(core.get_fps()), assets.get_font("arial"), 100.0f, 20.0f);
		renderer.draw_text(std::to_string(player_1_score), assets.get_font("arial"), 50.0f, 20.0f);
		renderer.draw_text(std::to_string(player_2_score), assets.get_font("arial"), display_width - 100.0f, 20.0f);
		
		renderer.draw_sprite(ball);
		renderer.draw_sprite(paddle1);
		renderer.draw_sprite(paddle2);
		
		renderer.display();
	}

	return SDE_SUCCESS;
}