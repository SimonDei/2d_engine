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
#include "FileAccess.hpp"
#include "Keycodes.hpp"


namespace sde {
	class Core {
		private:
			Display m_display;
			ALLEGRO_EVENT_QUEUE* m_queue = nullptr;
			ALLEGRO_EVENT m_event;
			ALLEGRO_TIMEOUT m_timeout;
			Disposer m_disposer;
			Updater m_updater;
			Assets m_assets;
			bool m_running = false;
			bool m_has_event = false;
			

		public:
			Core();
			explicit Core(const std::string& name);
			Core(const std::string& name, unsigned int width, unsigned int height);
			~Core();

			void set_window_title(const std::string& name) const;
			void set_window_position(unsigned int x, unsigned int y) const;
			void create_window(unsigned int width, unsigned int height);

			template<typename T>
			void add_updateable(const T& updateable) {
				m_updater.add_updateable(std::make_shared<T>(updateable));
			}

			template<typename T>
			void add_disposable(const T& disposable) {
				m_disposer.add_disposable(std::make_shared<T>(disposable));
			}

			void set_mouse_visible(bool visible) const;
			void set_mouse_grabbed(bool grabbed) const;

			inline bool is_running() const {
				return m_running;
			}
			inline const Event& get_event_type() const {
				return static_cast<Event>(m_event.type);
			}
			//inline void update() override {
			//	m_updater.update();
			//}

			bool is_event_in_queue();

			const Keycode& get_keycode() const;

			Assets& get_assets();

			const Display& get_display() const;
			const Disposer& get_disposer() const;
			const Updater& get_updater() const;

			void wait(int ms) const;
	
			void close();
	};
}

#endif