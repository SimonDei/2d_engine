#ifndef _MAIN2_HPP_
#define _MAIN2_HPP_

#include <sd_engine.hpp>


class Main_2 : public sde::Game {
	private:
		sde::Core m_core{ };
		sde::Renderer m_renderer{ };
		sde::Assets m_assets{ m_core.get_assets() };
		
		float m_display_width{ 0.0f };
		float m_display_height{ 0.0f };

		float m_grid_width{ 0.0f };
		float m_grid_height{ 0.0f };

		float m_cell_size{ 30.0f };
		
		unsigned int m_player_score{ 0 };

		sde::Rectangle<float> m_snake{ };
		sde::Rectangle<float> m_food{ };

		sde::Vector2<float> m_snake_velocity{ 200.0f, 0.0f };


	public:
		Main_2() { init(); }
		~Main_2() { dispose(); }

		void init() override;
		void keyboard() override;
		void update() override;
		void render() override;
		void dispose() override;
};

#endif