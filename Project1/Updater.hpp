#ifndef _UPDATER_HPP_
#define _UPDATER_HPP_

#include <vector>
#include <memory>

#include "Updateable.hpp"
#include "SdeException.hpp"


namespace sde {
	class Updater : public Updateable {
		private:
			std::vector<Updateable*> m_update_vector{ };
			

		public:
			Updater() = default;
			~Updater();

			void add_updateable(Updateable* updateable);
			
			unsigned int get_size() const;

			void update(double delta) override;
	};
}

#endif