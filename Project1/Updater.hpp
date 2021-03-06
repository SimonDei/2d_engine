#ifndef _UPDATER_HPP_
#define _UPDATER_HPP_

#include <vector>

#include "Updateable.hpp"


namespace sde {
	class Updater : public Updateable {
		private:
			std::vector<Updateable*> m_update_vector{ };
			

		public:
			Updater() = default;
			~Updater() = default;

			void add_updateable(Updateable* updateable);
			
			unsigned int get_size() const;

			void update(float delta) override;
	};
}

#endif