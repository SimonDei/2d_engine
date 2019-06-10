#ifndef _DISPOSER_HPP_
#define _DISPOSER_HPP_

#include <iostream>
#include <vector>

#include "Disposable.hpp"


namespace sde {
	class Disposer : public Disposable {
		private:
			std::vector<std::shared_ptr<Disposable>> m_dispose_vector;
			bool m_disposed = false;


		public:
			Disposer() = default;
			~Disposer();

			void add_disposable(std::shared_ptr<Disposable> disposable);

			void dispose() override;
	};
}

#endif