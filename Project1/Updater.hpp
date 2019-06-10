#ifndef _UPDATER_HPP_
#define _UPDATER_HPP_

#include <vector>
#include <memory>

#include "Updateable.hpp"


namespace sde {
	class Updater : public Updateable {
		private:
			std::vector<std::shared_ptr<Updateable>> m_update_vector;
			

		public:
			Updater() = default;
			~Updater();

			void add_updateable(const Updateable& updateable);
			
			unsigned int get_size() const;

			void update() override;
	};
}

#endif