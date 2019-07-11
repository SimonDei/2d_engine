#ifndef _MAIN_WORLDGEN_HPP_
#define _MAIN_WORLDGEN_HPP_

#include <sd_engine.hpp>


class Main_WorldGen : public sde::Game {
	private:
		sde::Core m_core{ };
		sde::Renderer m_renderer{ };
		sde::Assets m_assets{ m_core.get_assets() };

		ALLEGRO_KEYBOARD_STATE state{ };

		sde::Camera m_camera{ };

		sde::Texture m_map{ sde::TextureFlags::MEMORY_BITMAP, sde::TextureFlags::NO_PRESERVE };

		int draws{ 0 };


	public:
		Main_WorldGen() { init(); }
		~Main_WorldGen() { dispose(); }

		virtual void init() override;
		virtual void keyboard() override;
		virtual void update() override;
		virtual void render() override;
		virtual void dispose() override;
};

#endif