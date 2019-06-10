#ifndef _MUSICQUEUE_HPP_
#define _MUSICQUEUE_HPP_

#include <unordered_map>

#include "Music.hpp"
#include "Updateable.hpp"


namespace sde {
	class MusicQueue : public Updateable {
		private:
			std::unordered_map<unsigned int, std::shared_ptr<Music>> m_music_map;
			std::shared_ptr<Music> m_playing_music = nullptr;
			unsigned int m_playing_index = 0;
			unsigned int m_current_position = 0;
			bool m_paused = false;


		public:
			MusicQueue() = default;
			~MusicQueue();

			void set_volume(float volume);

			void push_music(const Music& music);

			void play();
			void pause();
			void resume();
			void stop();
			void reset();

			void update() override;

			const std::unordered_map<unsigned int, std::shared_ptr<Music>>& get_music_map() const;
		
			bool is_playing() const;
	};
}

#endif