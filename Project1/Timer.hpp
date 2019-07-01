#ifndef _TIMER_HPP_
#define _TIMER_HPP_

#include <allegro5/allegro.h>

#include <memory>

#include "Disposable.hpp"


namespace sde {
	class Timer : public Disposable {
		private:
			ALLEGRO_TIMER* m_timer{ nullptr };
			bool m_created{ false };
			bool m_started{ false };
			bool m_stopped{ true };


		public:
			Timer() = default;
			explicit Timer(double ticks_per_sec);
			~Timer();

			void set_ticks_per_sec(double ticks_per_sec) const;

			void start_timer();
			void stop_timer();
			void resume_timer();

			void reset() const;

			double get_one_second() const;
			long get_elapsed_time() const;

			bool is_started() const;
			bool is_running() const;
			bool is_one_second_elapsed() const;

			void dispose() override;
	};
}

#endif