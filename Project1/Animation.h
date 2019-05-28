#pragma once

#include <allegro5/allegro.h>

#include <list>


namespace sde {
	class Animation {
		private:	
			std::list<ALLEGRO_BITMAP*> m_sprites;
			float m_frame_delay = 0.0f;

		public:
			Animation() = default;
			~Animation();
	};
}
