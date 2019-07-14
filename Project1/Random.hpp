#ifndef _RANDOM_HPP_
#define _RANDOM_HPP_

#include <random>
#include <chrono>


namespace sde {
	namespace rand {
		namespace {
			std::default_random_engine rand_engine{
				static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count())
			};
		}

		static int get_random_number(int min, int max) {
			const std::uniform_int_distribution<int> dist(min, max);
			return dist(rand_engine);
		}

		static float get_random_number(float min, float max) {
			const std::uniform_real_distribution<float> dist(min, max);
			return dist(rand_engine);
		}
	}
}

#endif