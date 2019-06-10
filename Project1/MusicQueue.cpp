#include "MusicQueue.hpp"


namespace sde {
	void MusicQueue::set_volume(float volume) {
		al_set_sample_instance_gain(m_playing_music->get_sample_instance(), volume / 100.0f);
	}

	void sde::MusicQueue::push_music(const Music& music) {
		m_music_map.insert(std::make_pair(m_music_map.size(), std::make_shared<Music>(music)));
	}
	
	void MusicQueue::play() {
		m_playing_music = m_music_map.at(m_playing_index);
		al_play_sample_instance(m_playing_music->get_sample_instance());
		al_attach_sample_instance_to_mixer(m_playing_music->get_sample_instance(), al_get_default_mixer());
		m_playing_music->set_started(true);
	}

	void MusicQueue::pause() {
		m_current_position = al_get_sample_instance_position(m_playing_music->get_sample_instance());
		al_set_sample_instance_playing(m_playing_music->get_sample_instance(), false);
		m_paused = true;
	}

	void MusicQueue::resume() {
		al_set_sample_instance_playing(m_playing_music->get_sample_instance(), true);
		al_set_sample_instance_position(m_playing_music->get_sample_instance(), m_current_position);
		m_paused = false;
	}

	void MusicQueue::stop() {
		al_stop_sample_instance(m_playing_music->get_sample_instance());
		m_playing_music = nullptr;
	}

	void MusicQueue::reset() {
		m_playing_index = 0;
		play();
	}

	void MusicQueue::update() {
		if (!m_paused && m_playing_music->get_sample_instance() != nullptr) {
			if (!al_get_sample_instance_playing(m_playing_music->get_sample_instance()) && m_playing_music->get_started()) {
				m_playing_music->set_started(false);
				m_playing_music = nullptr;
				if (m_playing_index + 1 < m_music_map.size()) {
					m_playing_index++;
					play();
				}
			}
		}
	}

	const std::unordered_map<unsigned int, std::shared_ptr<Music>>& MusicQueue::get_music_map() const {
		return m_music_map;
	}

	bool MusicQueue::is_playing() const {
		return !m_paused;
	}

	MusicQueue::~MusicQueue() {
	}
}
