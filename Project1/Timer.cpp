#include "Timer.hpp"


namespace sde {
	Timer::Timer(double ticks_per_sec) {
		m_timer = al_create_timer(ticks_per_sec);
		m_created = true;
	}

	void Timer::start_timer() {
		if (!m_created) {
			m_timer = al_create_timer(1.0);
		}
		al_start_timer(m_timer);
		m_started = true;
		m_stopped = false;
	}

	void Timer::stop_timer() {
		if (!m_stopped) {
			al_stop_timer(m_timer);
			m_stopped = true;
		}
	}

	void Timer::resume_timer() {
		if (m_stopped) {
			al_resume_timer(m_timer);
			m_stopped = false;
		}
	}

	long Timer::get_elapsed_ticks() const {
		return static_cast<long>(al_get_timer_count(m_timer));
	}

	bool Timer::is_started() const {
		return m_started;
	}

	bool Timer::is_running() const {
		return !m_stopped;
	}

	void Timer::dispose() {
		if (m_timer != nullptr && !m_disposed) {
			al_destroy_timer(m_timer);
			m_timer = nullptr;
			m_disposed = true;
		}
	}

	Timer::~Timer() {
	}
}