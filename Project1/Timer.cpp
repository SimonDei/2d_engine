#include "Timer.hpp"


namespace sde {
	Timer::Timer(double ticks_per_sec) {
		m_timer = al_create_timer(1.0 / ticks_per_sec);
		m_created = true;
	}

	void Timer::set_ticks_per_sec(double ticks_per_sec) const {
		al_set_timer_speed(m_timer, 1.0 / ticks_per_sec);
	}

	void Timer::start_timer() {
		if (!m_created) {
			m_timer = al_create_timer(1.0);
			m_created = true;
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

	void Timer::reset() const {
		al_set_timer_count(m_timer, 0);
	}
	
	double Timer::get_one_second() const {
		return al_get_timer_speed(m_timer);
	}

	long Timer::get_elapsed_time() const {
		return static_cast<long>(al_get_timer_count(m_timer));
	}

	bool Timer::is_started() const {
		return m_started;
	}

	bool Timer::is_running() const {
		return !m_stopped;
	}

	bool Timer::is_one_second_elapsed() const {
		return static_cast<double>(al_get_timer_count(m_timer)) >= al_get_timer_speed(m_timer);
	}

	void Timer::dispose() {
		if (!m_disposed && m_timer != nullptr) {
			al_destroy_timer(m_timer);
			m_timer = nullptr;
			m_disposed = true;
		}
	}
}