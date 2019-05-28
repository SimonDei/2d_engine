#pragma once

#include "allegro5/allegro.h"

#include "DisplayFlags.h"
#include "Disposable.h"


namespace sde {
	class Display : public Disposable {
		private:
			ALLEGRO_DISPLAY* m_display = nullptr;
			unsigned int m_width = 0;
			unsigned int m_height = 0;


		public:
			Display() = default;
			~Display();

			void create_display(unsigned int width, unsigned int height);

			void set_flags(const DisplayFlags& flags);

			ALLEGRO_DISPLAY* get_display() const;

			void dispose() override;
	};
}