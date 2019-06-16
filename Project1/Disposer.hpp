#ifndef _DISPOSER_HPP_
#define _DISPOSER_HPP_

#include <iostream>
#include <vector>

#include "Disposable.hpp"


namespace sde {
	class Disposer : public Disposable {
		private:
			std::vector<Disposable*> m_dispose_vector{ };
			bool m_disposed{ false };


		public:
			Disposer() = default;
			~Disposer();

			void add_disposable(Disposable* disposable);

			void dispose() override;
	};
}

#endif