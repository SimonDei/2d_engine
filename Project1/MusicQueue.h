#pragma once

#include <unordered_map>

#include "Music.h"
#include "Updateable.h"


namespace sde {
	class MusicQueue : public Updateable {
		private:
			std::unordered_map<unsigned int, Music*> m_music_map;
			Music* m_playing_music = nullptr;
			unsigned int m_playing_index = 0;
			unsigned int m_current_position = 0;
			bool m_paused = false;

		public:
			MusicQueue() = default;
			~MusicQueue();

			void push_music(const Music& music);

			void play();
			void pause();
			void resume();
			void stop();
			void reset();

			void update() override;

			const std::unordered_map<unsigned int, Music*>& get_music_map() const;
		
			bool is_playing() const;
	};
}
