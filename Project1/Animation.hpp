#ifndef _ANIMATION_HPP_
#define _ANIMATION_HPP_

#include <allegro5/allegro.h>

#include <memory>

#include "TextureSheet.hpp"
#include "Timer.hpp"
#include "Updateable.hpp"


namespace sde {
	class Animation : public Updateable {
		private:
			std::shared_ptr<TextureSheet> m_texture_sheet{ nullptr };
			Timer m_timer{ };
			double m_frame_time{ 0.0 };
			

		public:
			Animation() = default;
			~Animation();

			void set_texture_sheet(const TextureSheet& texture_sheet);
			void set_frame_time(float frame_time);

			void update(double delta) override;
	};
}

#endif