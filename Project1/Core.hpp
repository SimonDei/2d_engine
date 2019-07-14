#ifndef _CORE_HPP_
#define _CORE_HPP_

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

#include <string>

#include "Time.hpp"

#include "Display.hpp"
#include "Disposer.hpp"
#include "Updater.hpp"
#include "Assets.hpp"

#include "Events.hpp"
#include "Keycodes.hpp"


namespace sde {
	class Core {
		private:
			Display m_display{ };
			ALLEGRO_EVENT_QUEUE* m_queue{ nullptr };
			ALLEGRO_TIMER* m_timer{ nullptr };
			ALLEGRO_EVENT m_event{ };
			ALLEGRO_TIMEOUT m_timeout{ };
			Disposer m_disposer{ };
			Updater m_updater{ };
			Assets m_assets{ };
			bool m_running{ false };
			bool m_paused{ false };
			bool m_has_event{ false };
			float m_fps{ 60.0f };


		public:
			Core() : Core{ "sde window" } { };
			explicit Core(const std::string& name);
			Core(const std::string& name, unsigned int width, unsigned int height);
			~Core();

			void set_window_title(const std::string& name) const;
			void set_window_position(unsigned int x, unsigned int y) const;
			void set_opengl_enable() const;
			void create_window(unsigned int width, unsigned int height);

			void init_opengl();
			void set_fps(float fps);

			void start_event_timer();
			void stop_event_timer() const;

			void set_mouse_visible(bool visible) const;
			void set_mouse_grabbed(bool grabbed) const;
			
			void set_paused(bool paused);

			void add_updateable(Updateable* updateable) {
				m_updater.add_updateable(updateable);
			}

			void add_disposable(Disposable* disposable) {
				m_disposer.add_disposable(disposable);
			}

			bool is_paused() const { 
				return m_paused;
			};

			bool is_running() const {
				return m_running;
			}

			// ===================================	
			bool poll_events() {
				al_wait_for_event(m_queue, &m_event);
				if (m_event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { m_running = false; }
				return al_is_event_queue_empty(m_queue);
			}
			// =========== ODER ==================
			bool poll_events_timed() {
				m_has_event = al_wait_for_event_until(m_queue, &m_event, &m_timeout);
				if (m_event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { m_running = false; }
				return m_has_event;
			}
			// ===================================

			void update() {
				m_updater.update(time::get_frame_time());
			}

			Event get_event_type() const {
				return static_cast<Event>(m_event.type);
			}

			Assets& get_assets();
			Updater& get_updater();
			Disposer& get_disposer();
			Keycode get_keycode() const;
			const Display& get_display() const;
	
			void close();
	};
}

#endif