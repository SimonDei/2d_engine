#pragma once

#include <vector>

#include "Updateable.h"


namespace sde {
	class Updater : public Updateable {
		private:
			std::vector<Updateable*> m_update_vector;
			

		public:
			Updater() = default;
			~Updater();

			void add_updateable(const Updateable& updateable);
			
			void update() override;
	};
}
