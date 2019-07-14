#ifndef _ANIMATION_HPP_
#define _ANIMATION_HPP_

#include <allegro5/allegro.h>

#include <memory>

#include "TextureSheet.hpp"
#include "Timer.hpp"
#include "Drawable.hpp"
#include "Transformable.hpp"
#include "Updateable.hpp"


namespace sde {
	class Animation : public Drawable, public Transformable, public Updateable {
		private:
			std::shared_ptr<TextureSheet> m_texture_sheet{ nullptr };
			Timer m_timer{ 1.0 };
			unsigned int m_max_frames{ 0 };
			unsigned int m_frame{ 0 };
			

		public:
			Animation() = default;
			explicit Animation(unsigned int frames);
			Animation(unsigned int frames, const TextureSheet& texture_sheet);
			~Animation();

			void set_texture_sheet(const TextureSheet& texture_sheet);
			void set_frame_time(double frames_per_sec) const;

			void update(float delta) override;

			void draw() const override;
			void draw(float x, float y) const override;
	};
}

#endif