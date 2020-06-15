#ifndef _MAIN_HPP_
#define _MAIN_HPP_

#include <sd_engine.hpp>


class Main : public sde::Game {
	private:
		sde::Core m_core{ };
		sde::Renderer m_renderer{ };
		sde::Assets m_assets{ m_core.get_assets() };
		
		float m_display_width{ 0.0f };
		float m_display_height{ 0.0f };

		sde::Camera m_camera{ };

		sde::Sprite m_ball{ };
		sde::Sprite m_paddle1{ };
		sde::Sprite m_paddle2{ };

		bool m_ball_reset{ false };
		bool m_paddle_up{ false };
		bool m_paddle_down{ false };
				
		unsigned int m_player1_score{ 0 };
		unsigned int m_player2_score{ 0 };
		
		const float m_paddle_velocity{ 10.0f };

		sde::Vector2<float> m_ball_velocity{ 12.5f, 12.5f };


	public:
		Main() { init(); }
		~Main() { }

		void init() override;
		void keyboard() override;
		void update() override;
		void render() override;
		void dispose() override;
};

#endif
