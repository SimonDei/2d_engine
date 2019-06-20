#ifndef _MUSIC_HPP_
#define _MUSIC_HPP_

#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include <string>

#include "SdeException.hpp"
#include "Disposable.hpp"


namespace sde {
	class Music : public Disposable {
		private:
			ALLEGRO_SAMPLE* m_sample{ nullptr };
			ALLEGRO_SAMPLE_INSTANCE* m_instance{ nullptr };
			bool m_started{ false };


		public:
			Music() = default;
			explicit Music(const std::string& path);
			explicit Music(const Music& music);
			~Music();
			
			void set_started(bool started);

			bool get_started() const;

			ALLEGRO_SAMPLE* get_sample() const;
			ALLEGRO_SAMPLE_INSTANCE* get_sample_instance() const;

			void dispose() override;
	};
}

#endif