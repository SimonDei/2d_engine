#ifndef _MAIN_HPP_
#define _MAIN_HPP_

#include <sd_engine.hpp>


class Main : public sde::Game {
	private:
		sde::Core m_core{ };
		sde::Renderer m_renderer{ };


	public:
		Main() { init(); }
		~Main() { }

		void init() override;
		void keyboard() override;
		void update() override;
		void render() override;
};

#endif