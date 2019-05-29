#include "Music.h"


namespace sde {
	Music::Music(const std::string& path) {
		if ((m_sample = al_load_sample(path.c_str())) != nullptr) {
			m_instance = al_create_sample_instance(m_sample);
			al_attach_sample_instance_to_mixer(m_instance, al_get_default_mixer());
		} else {
			throw NullException("Sample at " + path + " does not exist.");
		}
	}

	Music::Music(const Music& music) {
		m_sample = music.get_sample();
		m_instance = music.get_sample_instance();
		m_started = music.get_started();
	}

	bool Music::get_started() const {
		return m_started;
	}

	ALLEGRO_SAMPLE* Music::get_sample() const {
		return m_sample;
	}

	ALLEGRO_SAMPLE_INSTANCE* Music::get_sample_instance() const {
		return m_instance;
	}

	void Music::set_started(bool started) {
		m_started = started;
	}

	void Music::dispose() {
		if (m_sample != nullptr && !m_disposed) {
			al_destroy_sample_instance(m_instance);
			al_destroy_sample(m_sample);
			m_sample = nullptr;
			m_instance = nullptr;
			m_disposed = true;
		}
	}

	Music::~Music() {
	}
}
