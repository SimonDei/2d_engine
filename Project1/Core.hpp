#ifndef _CORE_HPP_
#define _CORE_HPP_

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

#include <string>
#include <chrono>
#include <thread>

#include "Display.hpp"
#include "Disposer.hpp"
#include "Updater.hpp"
#include "Assets.hpp"

#include "Events.hpp"
#include "DisplayFlags.hpp"
#include "Keycodes.hpp"


namespace sde {
	class Core {
		private:
			Display m_display{ };
			ALLEGRO_EVENT_QUEUE* m_queue{ nullptr };
			ALLEGRO_TIMER* m_timer{ nullptr };
			ALLEGRO_EVENT m_event{ };
			ALLEGRO_TIMEOUT m_timeout{ };
			ALLEGRO_MOUSE_STATE m_mouse_info{ };
			Disposer m_disposer{ };
			Updater m_updater{ };
			Assets m_assets{ };
			bool m_running{ false };
			bool m_paused{ false };
			bool m_has_event{ false };
			double m_fps{ 60.0 };
			double m_old_frame_time{ 0.0 };
			double m_new_frame_time{ 0.0 };
			double m_delta_frame_time{ 0.0 };
			double m_current_fps{ 0.0 };


		public:
			Core() : Core{ "sde window" } { };
			explicit Core(const std::string& name);
			Core(const std::string& name, unsigned int width, unsigned int height);
			~Core();

			void set_window_title(const std::string& name) const;
			void set_window_position(unsigned int x, unsigned int y) const;
			void set_opengl_enable() const;
			void create_window(unsigned int width, unsigned int height);

			void set_fps(float fps);
			void init_opengl();

			void start_event_timer();
			void stop_event_timer() const;

			void set_mouse_visible(bool visible) const;
			void set_mouse_grabbed(bool grabbed) const;
			
			void set_paused(bool paused);
			void toggle_paused();

			float get_mouse_x();
			float get_mouse_y();
			const Vector2<float> get_mouse_position();

			double get_game_time() const;
			double get_frame_time() const;
			double get_fps() const;
			
			void wait(int ms) const;

			void add_updateable(Updateable* updateable) {
				m_updater.add_updateable(updateable);
			}

			void add_disposable(Disposable* disposable) {
				m_disposer.add_disposable(disposable);
			}

			inline bool is_paused() const { 
				return m_paused;
			};

			inline bool is_running() {
				m_new_frame_time = al_get_time();
				m_delta_frame_time = m_new_frame_time - m_old_frame_time;
				m_current_fps = 1000.0 / (m_delta_frame_time * 1000.0);
				m_old_frame_time = m_new_frame_time;
				return m_running;
			}

			// ===================================	
			inline bool poll_events() {
				al_wait_for_event(m_queue, &m_event);
				if (m_event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { m_running = false; }
				return al_is_event_queue_empty(m_queue);
			}
			// =========== ODER ==================
			inline bool poll_events_timed() {
				m_has_event = al_wait_for_event_until(m_queue, &m_event, &m_timeout);
				if (m_event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { m_running = false; }
				// TODO: update Methode Platz finden
				//m_updater.update();
				return m_has_event;
			}
			// ===================================

			inline void update() {
				m_updater.update(m_delta_frame_time);
			}

			inline const Event get_event_type() const {
				return static_cast<Event>(m_event.type);
			}

			Assets& get_assets();
			Updater& get_updater();
			Disposer& get_disposer();
			const Keycode get_keycode() const;
			const Display& get_display() const;
	
			void close();
	};
}

#endif