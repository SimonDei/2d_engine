#ifndef _DISPLAY_HPP_
#define _DISPLAY_HPP_

#include "allegro5/allegro.h"

#include <string>

#include "DisplayFlags.hpp"
#include "Disposable.hpp"


namespace sde {
	class Display : public Disposable {
		private:
			ALLEGRO_DISPLAY* m_display{ nullptr };
			unsigned int m_width{ 0 };
			unsigned int m_height{ 0 };


		public:
			Display() = default;
			~Display();

			void create_display(unsigned int width, unsigned int height);

			void set_position(unsigned int x, unsigned int y) const;
			void set_title(const std::string& name) const;
			void set_flags(const DisplayFlags& flags) const;

			float get_width() const;
			float get_height() const;
			ALLEGRO_DISPLAY* get_display() const;

			void dispose() override;
	};
}

#endif