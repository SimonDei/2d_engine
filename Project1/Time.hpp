#ifndef _TIME_HPP_
#define _TIME_HPP_

#include <allegro5/allegro.h>

#include <thread>
#include <chrono>


namespace sde {
	namespace time {
		namespace {
			float m_old_frame_time{ 0.0f };
			float m_new_frame_time{ 0.0f };
			float m_delta_frame_time{ 0.0f };
		}

		/**
		  * Function for internal use only.
		**/
		static void update() {
			m_new_frame_time = static_cast<float>(al_get_time());
			m_delta_frame_time = m_new_frame_time - m_old_frame_time;
			m_old_frame_time = m_new_frame_time;
		}

		static float get_fps() {
			return 1000.0f / (m_delta_frame_time * 1000.0f);
		}

		static float get_frame_time() {
			return m_delta_frame_time;
		}

		static float get_game_time() {
			return static_cast<float>(al_get_time());
		}

		static void wait(int milliseconds) {
			std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
		}
	}
}

#endif