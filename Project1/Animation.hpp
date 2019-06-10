#ifndef _ANIMATION_HPP_
#define _ANIMATION_HPP_

#include <allegro5/allegro.h>

#include <list>

#include "Updateable.hpp"


namespace sde {
	class Animation : public Updateable {
		private:	
			
			float m_frame_delay = 0.0f;

		public:
			Animation() = default;
			~Animation();

			void update() override;
	};
}

#endif